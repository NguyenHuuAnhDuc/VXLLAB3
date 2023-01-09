/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define SWITCH_1_A			GPIO_PIN_11
#define SWITCH_1_A_PORT		GPIOA
#define SWITCH_1_B			GPIO_PIN_12
#define SWITCH_1_B_PORT		GPIOA
#define SWITCH_1_C			GPIO_PIN_13
#define SWITCH_1_C_PORT		GPIOA
#define SWITCH_1_D			GPIO_PIN_14
#define SWITCH_1_D_PORT		GPIOA
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */


/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */
void update7SEG ( int index );
void setSwitch0 ( int duration );
void setTimer0 ( int duration );
void setBlink0 ( int duration );
void update_led_buffer_mode1();
void update_led_buffer_mode2();

uint8_t update_light_led_buffer(uint8_t val, uint8_t idx);
void transport_light_led_driver();
void blinkLED(int mode);

void seven_segment_led_driver();
uint8_t update_seven_segment_led_buffer(uint8_t val, uint8_t idx);
void display7SEG (int num);
void timer_run() ;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
