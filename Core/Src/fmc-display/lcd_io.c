/*
 * rpi-display.c
 *
 *  Created on: Mar 10, 2025
 *      Author: bharg
 */

#include "lcd_io.h"
#include "rpiDisplayShapes.h"
#include "gfxfont.h"
#include <string.h>

extern uint16_t framebuffer[];
extern DMA2D_HandleTypeDef hdma2d;
extern uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);

void commandAndData(uint16_t command, uint16_t* data, unsigned int size) {
    LCD_REG = command;

    if (size) {
        for (unsigned int i = 0; i < size; i++) {
            LCD_RAM = data[i];
        }
    }
}

void transmitRepeatedData(uint16_t data16, unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {
        LCD_RAM = data16;
    }
}

void transmitSingleData(uint16_t data16) {
	LCD_RAM = data16;
}

void LCD_FILL_DMA2D(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)	{
	uint32_t dest = (uint32_t)&framebuffer[y * SCREEN_WIDTH + x];

	//DMA2D->OOR = SCREEN_WIDTH - w;
	HAL_DMA2D_Start(&hdma2d, color, dest, w, h);
	HAL_DMA2D_PollForTransfer(&hdma2d, 100);

	SCB_InvalidateDCache_by_Addr((uint32_t*)framebuffer, FRAME_BUFFER_SIZE * 2);
}

void LCD_CLEAR_DMA2D(uint32_t color) {
	HAL_DMA2D_Start(&hdma2d, (uint32_t)color, (uint32_t )framebuffer, SCREEN_WIDTH, SCREEN_HEIGHT);
	HAL_DMA2D_PollForTransfer(&hdma2d, HAL_MAX_DELAY);
	SCB_InvalidateDCache_by_Addr((uint32_t*)framebuffer, FRAME_BUFFER_SIZE * 2);

	modifySpace(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
	commandAndData(0x2C, framebuffer, FRAME_BUFFER_SIZE);
}

void LCD_DRAW_POINT(uint16_t x, uint16_t y, uint32_t color) {
	framebuffer[y * SCREEN_WIDTH + x] = (uint16_t) color;
}

void displayOn() {
	commandAndData(0x29, NULL, 0);
}

void displayOff() {
	commandAndData(0x28, NULL, 0);
}

void resetScreen() {
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(20);
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET);
	HAL_Delay(20);
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(100);
}

void initializeScreen() {
	commandAndData(0x01, NULL, 0);
	commandAndData(0x11, NULL, 0);
	{
		uint16_t data[] = {0x0055};
		commandAndData(0x3A, data, sizeof(data) / sizeof(data[0]));
	}
	{
		uint16_t data[] = {0x0019, 0x001a};
		commandAndData(0xC0, data, sizeof(data) / sizeof(data[0]));
	}
	{
		uint16_t data[] = {0x0045, 0x0000};
		commandAndData(0xC1, data, sizeof(data) / sizeof(data[0]));
	}
	{
		uint16_t data[] = {0x0033};
		commandAndData(0xC2, data, sizeof(data) / sizeof(data[0]));
	}
	{
		uint16_t data[] = {0x0000, 0x0028};
		commandAndData(0xC5, data, sizeof(data) / sizeof(data[0]));
	}
	{
		uint16_t data[] = {0x00A0, 0x0011};
		commandAndData(0xB1, data, sizeof(data) / sizeof(data[0]));
	}
	{
		uint16_t data[] = {0x0002};
		commandAndData(0xB4, data, sizeof(data) / sizeof(data[0]));
	}
	{
	    uint16_t data[] = {0x0000, 0x0007, 0x000F, 0x000D, 0x001B,
	                       0x000A, 0x003C, 0x0078, 0x004A, 0x0007,
	                       0x000E, 0x0009, 0x001B, 0x001E, 0x000F};
	    commandAndData(0xE0, data, sizeof(data) / sizeof(data[0]));
	}
	{
	    uint16_t data[] = {0x0000, 0x0022, 0x0024, 0x0006, 0x0012,
	                       0x0007, 0x0036, 0x0047, 0x0047, 0x0006,
	                       0x000A, 0x0007, 0x0030, 0x0037, 0x000F};
	    commandAndData(0xE1, data, sizeof(data) / sizeof(data[0]));
	}
	commandAndData(0x21, NULL, 0);   // inversion on (fix your inverted colors)


	LCD_CLEAR_DMA2D(0x0000);
	displayOn();
}






