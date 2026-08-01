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
#include "FreeRTOS.h"
#include "cmsis_os2.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "rpiSceneBuilderUser.h"
#include "data.h"
#include "fdcanmessage.h"
#include "fdcan.h"
#include <stdio.h>
#include <stdlib.h>
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
extern osMessageQueueId_t canQueue;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern uint16_t framebuffer[];
char shiftCounterChar[20] = "";
volatile uint8_t shiftCounter = 0;
volatile uint32_t lastSendMs = 0;
uint8_t shiftCommand;
uint8_t sparkCutFlag = 0;
uint8_t sparkCutCommand = 1;
uint32_t lastShift = 0;
uint32_t lastDraw = 0;
uint8_t button1 = 0;
uint8_t button2 = 0;
uint32_t btn1Hit;
uint32_t btn2Hit;
uint8_t currentScreen = 0;
uint8_t resetFlag = 0;
uint8_t ledOn = 0;

//GPIO Callback function for buttons and paddle shifters
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	uint32_t now = HAL_GetTick();
	if ((now - lastShift) < 250)
		return;
	lastShift = now;

	if (GPIO_Pin == PAD__Pin) {
		// Down Shift
		shiftCounter++;
		shiftCommand = 1;
	} else if (GPIO_Pin == PAD_A2_Pin) {
		// Up Shift
		shiftCounter++;
		shiftCommand = 2;
	} else if (GPIO_Pin == BTN1_Pin) {
		resetFlag = 1;
	}
}


extern uint16_t rpmVal;
int checkShift() {
	if (shiftCommand == 2) {
		return 1;
	} else if (rpmVal > 10000) {
		return 0;
	}
	return 1;
}

const osThreadAttr_t shiftTaskattributes = { .name = "shiftTask", .stack_size =
		2048, .priority = (osPriority_t) osPriorityHigh};
const osThreadAttr_t buttonTaskattributes = { .name = "buttonTask",
		.stack_size = 256, .priority = (osPriority_t) osPriorityBelowNormal};
const osThreadAttr_t displayTaskattributes = { .name = "displayTask",
		.stack_size = 16384, .priority = (osPriority_t) osPriorityHigh};
const osThreadAttr_t CANTaskattributes = { .name = "CANTask", .stack_size =
		2048, .priority = (osPriority_t) osPriorityAboveNormal};
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void CANTask(void *argument);
void shiftTask(void *argument);
void buttonTask(void *argument);
void displayTask(void *argument);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  shiftTaskHandle = osThreadNew(shiftTask, NULL, &shiftTaskattributes);
  buttonTaskHandle = osThreadNew(buttonTask, NULL, &buttonTaskattributes);
  displayTaskHandle = osThreadNew(displayTask, NULL, &displayTaskattributes);
  CANTaskHandle = osThreadNew(CANTask, NULL, &CANTaskattributes);
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
/* Tasks */
void shiftTask(void *arg) {
	for (;;) {
		if (checkShift()) {
			TXMessage message;
			message.data[2] = sparkCutCommand;
			message.data[1] = shiftCounter;
			message.data[0] = shiftCommand;

			message.header.Identifier = 172;
			message.header.IdType = FDCAN_STANDARD_ID;
			message.header.TxFrameType = FDCAN_DATA_FRAME;
			message.header.DataLength = FDCAN_DLC_BYTES_8;
			message.header.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
			message.header.BitRateSwitch = FDCAN_BRS_OFF;
			message.header.FDFormat = FDCAN_CLASSIC_CAN;
			message.header.MessageMarker = 0;

			HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &message.header, message.data);

		}
		osDelay(1);
	}
}

void CANTask(void *argument) {
	for (;;) {
		RXMessage message;
		if (osMessageQueueGet(canQueue, &message, NULL, osWaitForever) == osOK) {
			processCAN(message.header.Identifier, message.data);
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
		osDelay(10);
	}
}
/* USER CODE END Application */

