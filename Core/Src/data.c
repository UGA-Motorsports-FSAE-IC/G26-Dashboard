/* shiftLights.c
 *
 *  Created on: May 5, 2026
 *      Author: ____Ryan____ Main
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
char oiltemp[20] = "null";

extern FDCAN_HandleTypeDef hfdcan2;

volatile uint32_t uniqueId = 1;
uint16_t framesSent = 0;
extern volatile uint8_t shiftPending;
extern volatile uint32_t lastSendMs;
extern uint8_t shiftCommand;

void lcdInit() {
    resetScreen();
    initializeScreen();
    HAL_Delay(200);
    settempdata(temp, 0xFFFF);
    setgeardata(gear);
    setrpmdata(rpm);
    setbattdata(batt);
    setspeeddata(speed);
    domainscreen();
}

/*
void updateMainData(FDCAN_HandleTypeDef *__hfdcan__) {
    while (HAL_FDCAN_GetRxFifoFillLevel(__hfdcan__, FDCAN_RX_FIFO0) > 0) {
        HAL_FDCAN_GetRxMessage(__hfdcan__, FDCAN_RX_FIFO0, &rxHeader, rxData);

        processCAN(&rxHeader, rxData);
    }
    __domainscreen__();
}
*/

int processCAN(int id, uint8_t *data) {
    switch (id) {
        case RPMCANID: {
            uint16_t rpmVal = ((uint16_t)data[6] << 8) + data[7];
            UpdateShiftLights(&htim2, TIM_CHANNEL_1, ledcolors, ledbytes, rpmVal, G1);
            itoa(rpmVal, rpm, 10);
            setrpmdata(rpm);
            break;
        }

        case SPEEDCANID: {
            uint16_t speedVal = ((uint16_t)data[0] << 8) | data[1];
            speedVal /= 10;
            itoa(speedVal, speed, 10);
            setspeeddata(speed);
            break;
        }

        case GEARCANID: {
            uint16_t gearVal = ((uint16_t)data[3] << 8) | data[2];
            int gearNum = calculateGear(gearVal);
            itoa(gearNum, gear, 10);
            setgeardata(gear);
            break;
        }

        case CLTCANID: {
            uint16_t tempVal = ((uint16_t)data[6] << 8) + data[7];
            tempVal /= 10;
            uint16_t color = (tempVal > 215) ? 0xf8e0 : 0xFFFF;
            itoa(tempVal, temp, 10);
            settempdata(temp, color);
            break;
        }

        case BATTERYCANID: {
            uint16_t battvalue = ((uint16_t)data[2] << 8) + data[3];
            uint16_t batIntPart = battvalue / 10;
            uint16_t batDecimalPart = battvalue % 10;
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

        case OILTEMPCANID: {
        	uint16_t oiltempval = ((uint16_t)data[3] << 8) + data[4];
        	itoa(oiltempval, oiltemp, 10);
        	setoiltempdata(oiltemp);
        }
    }
}

int calculateGear(uint16_t gv) {
	if (gv > 385 && gv < 685) {
		return 1;
	} else if (gv >= 685 && gv < 1065) {
		return 7;
	} else if (gv >= 1065 && gv < 1335) {
		return 2;
	} else if (gv >= 1335 && gv < 2014) {
		return 3;
	} else if (gv >= 2014 && gv < 2466) {
		return 4;
	} else if (gv >= 2466 && gv < 3000) {
		return 5;
	} else if (gv >= 3000 && gv < 3689) {
		return 6;
	} else {
		return 8;
	}
}

void shiftTask(void)
{
    if (!shiftPending) {
        return;
    }

	FDCAN_TxHeaderTypeDef txShiftHeader;
	uint8_t txData[8] = {0};
	txData[1] = uniqueId;
	txData[0] = shiftCommand;

	txShiftHeader.Identifier = 10;
	txShiftHeader.IdType = FDCAN_EXTENDED_ID;
	txShiftHeader.TxFrameType = FDCAN_DATA_FRAME;
	txShiftHeader.DataLength = FDCAN_DLC_BYTES_8;
	txShiftHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
	txShiftHeader.BitRateSwitch = FDCAN_BRS_OFF;
	txShiftHeader.FDFormat = FDCAN_CLASSIC_CAN;
	txShiftHeader.MessageMarker = 0;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &txShiftHeader, txData) == HAL_OK) {
		lastSendMs = HAL_GetTick();
		framesSent++;
    }
}

