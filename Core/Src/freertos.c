/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
osThreadId_t shiftTaskHandle;
osThreadId_t buttonTaskHandle;
osThreadId_t CANTaskHandle;
osThreadId_t displayTaskHandle;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
const osThreadAttr_t shiftTaskattributes = { .name = "shiftTask", .stack_size =
		2048, .priority = (osPriority_t) osPriorityHigh};
const osThreadAttr_t buttonTaskattributes = { .name = "buttonTask",
		.stack_size = 256, .priority = (osPriority_t) osPriorityBelowNormal};
const osThreadAttr_t displayTaskattributes = { .name = "shiftTask",
		.stack_size = 2048, .priority = (osPriority_t) osPriorityHigh};
const osThreadAttr_t CANTaskattributes = { .name = "shiftTask", .stack_size =
		2048, .priority = (osPriority_t) osPriorityAboveNormal};
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
CANTaskHandle = osThreadNew(CANTask, NULL, &CANTaskattributes);
displayTaskHandle = osThreadNew(displayTask, NULL, &displayTaskattributes);
buttonTaskHandle = osThreadNew(buttonTask, NULL, &buttonTaskattributes);
shiftTaskHandle = osThreadNew(shiftTask, NULL, &shiftTaskttributes);
/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void CANTask(void *argument);
void shiftTask(void *argument);
void buttonTask(void *argument);
void displayTask(void *argument);
/* USER CODE END FunctionPrototypes */

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
/* Tasks */
void shiftTask(void *arg) {
	for (;;) {
		if (checkShift() && timerBool == 1) {
			FDCAN_TxHeaderTypeDef txShiftHeader;
			uint8_t txData[8] = { 0 };
			txData[2] = sparkCutCommand;
			txData[1] = shiftCounter;
			txData[0] = shiftCommand;

			txShiftHeader.Identifier = 172;
			txShiftHeader.IdType = FDCAN_STANDARD_ID;
			txShiftHeader.TxFrameType = FDCAN_DATA_FRAME;
			txShiftHeader.DataLength = FDCAN_DLC_BYTES_8;
			txShiftHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
			txShiftHeader.BitRateSwitch = FDCAN_BRS_OFF;
			txShiftHeader.FDFormat = FDCAN_CLASSIC_CAN;
			txShiftHeader.MessageMarker = 0;

			HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &txShiftHeader, txData);

			timerBool = 0;
			itoa(shiftCounter, shiftCounterChar, 10);
			setshiftcountdata(shiftCounterChar);
		}
	}
	osDelay(1);
}

void CANTask(void *argument) {
	for (;;) {
		if (dataRecieved) {
			updateMainData();
			dataRecieved = 0;
		}
	}
}

void displayTask(void *argument) {
	for (;;) {
		domainscreen();
		osDelay(50);
	}
}

void buttonTask(void *argument) {
	for (;;) {
		if (resetFlag) {
			HAL_NVIC_SystemReset();
			resetFlag = 0;
		}
	}
}
/* USER CODE END Application */

