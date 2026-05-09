/*
 * rpi-display.h
 *
 *  Created on: Mar 10, 2025
 *      Author: bharg
 */

#ifndef LCD_IO_H
#define LCD_IO_H

#include "gfxfont.h"
#include "main.h"
#include <stdint.h>

/*
 * LCD_REG: BASE_ADDR (FMC Bank 1 = 0x60000000) Swapped to SRAM (0xC0000000)
 * LCD_RAM: DATA_ADDR (0x60020000) Swapper to SRAM (0xC0020000)
 */

#define LCD_REG  (*(volatile uint16_t *)0xC0000000)  // RS = 0
#define LCD_RAM  (*(volatile uint16_t *)0xC0020000)  // RS = 1

/*
 * screen width & height
 */
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320
#define FRAME_BUFFER_SIZE (320 * 480)



/*
 * some useful commands to the screen
 */
#define WRITE_COMMAND 0x2c

/*
 * THE BELOW ARE ALL FUNCTIONS TO DRAW TO THE SCREEN
 */

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * initializes the screen, run this before ever doing anything else with the screen
	 */
	void initializeScreen();

	/*
	 * will clear the screen to the color you want
	 * @param color The color to clear the screen at.
	 */
	void clearScreen(uint16_t color);

	/**
	 * will turn on the display
	 */
	void displayOn();

	/*
	 * will turn off the display (just the lcd, not the backlight)
	 */
	void displayOff();

	/**
	 * resets the screen as if it was power cycled, preferrably run this before you initialize
	 */

	void LCD_DRAW_POINT(uint16_t x, uint16_t y, uint32_t color);

	void commandAndData(uint16_t command, uint16_t* data, unsigned int size);

	void transmitRepeatedData(uint16_t data16, unsigned int count);

	void transmitSingleData(uint16_t data16);

	void LCD_FILL_DMA2D(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);

	void LCD_CLEAR_DMA2D(uint32_t color);

	void resetScreen();

#ifdef __cplusplus
}
#endif



#endif /* SRC_RPI_DISPLAY_RPI_DISPLAY_SHAPES_H_ */
