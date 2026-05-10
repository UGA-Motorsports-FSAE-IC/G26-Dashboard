/*
 * shiftLights.c
 *
 *  Created on: May 5, 2026
 *      Author: Ryan Main
 */

#include "data.h"
#include "rpiSceneBuilderUser.h"
#include "shiftLights.h"
#include "lcd_io.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern uint8_t ledcolors[];
extern uint32_t ledbytes[];
extern TIM_HandleTypeDef htim2;
int G1[12] = {500, 3000, 4000, 5000, 6000, 7000, 8000, 8500, 9000, 9500, 10000, 10200};
char rpm[20] = "null";
char temp[20] = "null";
char gear[20] = "8";
char batt[20] = "null";
char speed[20] = "null";

FDCAN_RxHeaderTypeDef rxHeader;
uint8_t rxData[64];

void lcdInit() {
	resetScreen();
	initializeScreen();
	HAL_Delay(200);
	settempdata(temp);
	setgeardata(gear);
	setrpmdata(rpm);
	setbattdata(batt);
	setspeeddata(speed);
	domainscreen();
}

void updateMainData(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs) {
	while (HAL_FDCAN_GetRxFifoFillLevel(hfdcan, FDCAN_RX_FIFO0) > 0) {
		HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &rxHeader, rxData);
		processCAN(&rxHeader, rxData);
	}
	domainscreen();
}

void processCAN(FDCAN_RxHeaderTypeDef *hdr, uint8_t *data) {
    switch (hdr->Identifier) {
        case RPMCANID:
        	uint16_t rpmVal = (uint16_t) ((data[6]) << 8) + data[7];
		    UpdateShiftLights(&htim2, TIM_CHANNEL_1, ledcolors, ledbytes, rpmVal, G1);
		    itoa(rpmVal, (char*)(rpm), 10);
		    setrpmdata(rpm);
            break;

        case SPEEDCANID:
        	uint16_t speedVal = (uint16_t) ((data[0] << 8) | data[1]);
        	speedVal /= 10;
		    itoa(speedVal, (char*) speed, 10);
		    setspeeddata(speed);
		    break;

        case GEARCANID:
        	uint16_t gearVal = (uint8_t) (data[6]);
		    itoa(gearVal, gear, 10);
		    setgeardata(gear);
            break;

        case CLTCANID:
        	uint16_t tempVal = (uint16_t) (((data[6]) << 8) + data[7]);
        	tempVal /= 10;
			if (tempVal > 215) {
		      setColor(&htim2, TIM_CHANNEL_1, 0, 255, 0, ledcolors, ledbytes, 15);
		    } else {
			  setColor(&htim2, TIM_CHANNEL_1, 0, 0, 0, ledcolors, ledbytes, 15);
		    }
		    itoa(tempVal, temp, 10);
		    settempdata(temp);
		    break;

        case BATTERYCANID:
        	uint8_t battvalue = (uint8_t) (((data[2]) << 8) + data[3]);
			uint8_t batIntPart = battvalue / 10;
			uint8_t batDecimalPart = battvalue % 10;
			char batint[10];
			char batdec[10];
			itoa(batIntPart, batint, 10);
			itoa(batDecimalPart, batdec, 10);
			strncpy(batt, "", 20);
			strncat(batt, batint, 5);
			strncat(batt, ".", 5);
			strncat(batt, batdec, 1);
			setbattdata(batt);
			break;
    }
}

