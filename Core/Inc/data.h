/*
 * data.h
 *
 *  Created on: May 9, 2026
 *      Author: Ryan Main
 */

#ifndef DATA_H_
#define DATA_H_

#include "main.h"
#include <stdint.h>

#define SCREENMODE

#define RPMCANID 1520
#define CLTCANID 1522
#define GEARCANID 1553
#define BATTERYCANID 1523
#define SPEEDCANID 1562




void lcdInit();

void updateMainData();

void processCAN(FDCAN_RxHeaderTypeDef *hdr, uint8_t *data);

#endif
