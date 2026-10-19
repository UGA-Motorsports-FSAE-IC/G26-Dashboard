/*
 * rpiSceneBuilderUser.h
 *
 *  Created on: May 2, 2025
 *      Author: Bhargav and Ryan
 */
#include <stdint.h>
#include <stdio.h>

#ifndef SRC_RPI_DISPLAY_RPISCENEBUILDERUSER_H_
#define SRC_RPI_DISPLAY_RPISCENEBUILDERUSER_H_


#define NUMSCENES 3
#define NULLP 0xFFFF

#ifdef __cplusplus
extern "C" {
#endif
	void domainscreen();
	void initdatascreen();
	void changebackground(uint16_t color);
	void dosplashscene();

	uint16_t positionMatrix[100][NUMSCENES][2] = {
			{ {10, 10}, {10, 10}, {NULLP, NULLP} }, // GEAR
			{ {10, 20}, {20, 10}, {NULLP, NULLP} } //RPM
	};
#ifdef __cplusplus
}
#endif


#endif /* SRC_RPI_DISPLAY_RPISCENEBUILDERUSER_H_ */
