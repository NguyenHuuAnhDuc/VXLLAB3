/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
# include "input_processing.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
//#define BUTTON_1_GPIO_Port GPIO_A;
//#define BUTTON_1_Pin;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//int counter = 0;
//int sw = 0;
//int MODE = 1;

//const int MAX_LED = 4;
//int index_led = 0;
//int led_buffer [4] = {0 , 0 , 0 , 0};
//int hour = 15 , minute = 8 , second = 50;
//
//const int blink = 500; //ms

//const int TIMER_CYCLE = 10; //ms
//
//int switch_counter = 0;
//int timer0_counter = 0;
//int blink_counter = 0;
//
//int switch_flag = 0;
//int timer0_flag = 0;
//int blink_flag = 0;

//uint8_t counter = 0;
//uint8_t valueToDisplay = 0;
//uint8_t value1 = 0;
//uint8_t value2 = 0;
//uint8_t TRAFFIC_LIGHT_MAX[3] = {5, 3, 2}; //RED, GREEN, YELLOW
//uint8_t state1 = 0; //RED
//uint8_t state2 = 1; //GREEN

//void update7SEG ( int index ) {
//	switch ( index ) {
//	case 0:
//		HAL_GPIO_WritePin ( SWITCH_1_B_PORT, SWITCH_1_B, SET ) ;
//		HAL_GPIO_WritePin ( SWITCH_1_C_PORT, SWITCH_1_C, SET ) ;
//		HAL_GPIO_WritePin ( SWITCH_1_D_PORT, SWITCH_1_D, SET ) ;
//		display7SEG (led_buffer[index]);
//		HAL_GPIO_WritePin ( SWITCH_1_A_PORT, SWITCH_1_A, RESET ) ;
//		break;
//	case 1:
//		HAL_GPIO_WritePin ( SWITCH_1_A_PORT, SWITCH_1_A, SET ) ;
//		HAL_GPIO_WritePin ( SWITCH_1_C_PORT, SWITCH_1_C, SET ) ;
//		HAL_GPIO_WritePin ( SWITCH_1_D_PORT, SWITCH_1_D, SET ) ;
//		display7SEG (led_buffer[index]);
//		HAL_GPIO_WritePin ( SWITCH_1_B_PORT, SWITCH_1_B, RESET ) ;
//		break;
//	case 2:
//		HAL_GPIO_WritePin ( SWITCH_1_A_PORT, SWITCH_1_A, SET ) ;
//		HAL_GPIO_WritePin ( SWITCH_1_B_PORT, SWITCH_1_B, SET ) ;
//		HAL_GPIO_WritePin ( SWITCH_1_D_PORT, SWITCH_1_D, SET ) ;
//		display7SEG (led_buffer[index]);
//		HAL_GPIO_WritePin ( SWITCH_1_C_PORT, SWITCH_1_C, RESET ) ;
//		break;
//	case 3:
//		HAL_GPIO_WritePin ( SWITCH_1_A_PORT, SWITCH_1_A, SET ) ;
//		HAL_GPIO_WritePin ( SWITCH_1_B_PORT, SWITCH_1_B, SET ) ;
//		HAL_GPIO_WritePin ( SWITCH_1_C_PORT, SWITCH_1_C, SET ) ;
//		display7SEG (led_buffer[index]);
//		HAL_GPIO_WritePin ( SWITCH_1_D_PORT, SWITCH_1_D, RESET ) ;
//		break;
//	default:
//		break;
//	}
//}



//void timer_run_mode1() {
//
//	if( timer0_counter > 0) {
//		timer0_counter--;
//		if( timer0_counter == 0) timer0_flag = 1;
//		else {
//			 transport_light_led_driver();
//		}
//	}
//	if( switch_counter > 0) {
//		switch_counter--;
//			if( switch_counter == 0) switch_flag = 1;
//	}
//
//}
//
//void timer_run_mode2() {
//	if( switch_counter > 0) {
//		switch_counter--;
//			if( switch_counter == 0) switch_flag = 1;
//	}
//	if( blink_counter > 0) {
//		blink_counter--;
//			if( blink_counter == 0) blink_flag = 1;
//	}
//}

//void update_led_buffer_mode1(){
//	led_buffer[0] = value1/10;
//	led_buffer[1] = value1%10;
//	led_buffer[2] = value2/10;
//	led_buffer[3] = value2%10;
//}
//
//void update_led_buffer_mode2(){
//	led_buffer[0] = 0;
//	led_buffer[1] = 2;
//	led_buffer[2] = TRAFFIC_LIGHT_MAX[0]/10;
//	led_buffer[3] = TRAFFIC_LIGHT_MAX[0]%10;
//}

//void executeLED(){
//
//		  value1--;
//		  value2--;
//		  if(!value1) {
//			  state1 = (state1+1)%3;
//			  value1 = TRAFFIC_LIGHT_MAX[state1];
//			  update_light_led_buffer(state1, 0);
//
//		  }
//		  if(!value2) {
//			  state2 = (state2+1)%3;
//			  value2 = TRAFFIC_LIGHT_MAX[state2];
//			  update_light_led_buffer(state2, 1);
//
//		  }
//		  update_led_buffer_mode1();
//
//}
//int press_b1 = 0;
//int press_b2 = 0;
//void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim ){
////	if(MODE ==1) timer_run_mode1();
////	else if(MODE==2) timer_run_mode2();
//
//
//	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1))
//	{
//				  press_b1++;
//		  		  if(press_b1 == 10){
//		  			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
////		  			MODE++;
////		  			  if(MODE>2) MODE=1;
//		  		  }
//	}
//	else{
//		press_b1 = 0;
//	}
////
////	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2))
////	{
////		      press_b2++;
////			  if(press_b2 == 10 && MODE==2){
////
////				  	  	TRAFFIC_LIGHT_MAX[0]++;
////				  	  	if (TRAFFIC_LIGHT_MAX[0] > 99) TRAFFIC_LIGHT_MAX[0] = 0;
////
////			  }
////
////	 }
////	else{
////		press_b2 = 0;
////	}
//}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


  //Loop


  while(1){

	  fsm_for_input_processing () ;


  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA1 PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA6 PA7
                           PA8 PA9 PA10 PA11
                           PA12 PA13 PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10
                           PB11 PB12 PB13 PB14
                           PB15 PB3 PB4 PB5
                           PB6 PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
