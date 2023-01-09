#include "main.h"


#define NUMBER_OF_LIGHTS			3
#define	NUMBER_OF_LEDS		2

#define LED_1_A			GPIO_PIN_5
#define LED_1_A_PORT		GPIOA
#define LED_1_B			GPIO_PIN_6
#define LED_1_B_PORT		GPIOA
#define LED_1_C			GPIO_PIN_7
#define LED_1_C_PORT		GPIOA
#define LED_1_D			GPIO_PIN_8
#define LED_1_D_PORT		GPIOA
#define LED_1_E			GPIO_PIN_9
#define LED_1_E_PORT		GPIOA
#define LED_1_F			GPIO_PIN_10
#define LED_1_F_PORT		GPIOA

static uint8_t translightLEDConversion[NUMBER_OF_LIGHTS] = {0x01,  0x04, 0x02};

static uint8_t translightLEDBuffer[NUMBER_OF_LEDS];

uint8_t update_light_led_buffer(uint8_t val, uint8_t idx){
	if(idx >= NUMBER_OF_LIGHTS) return 0;
	translightLEDBuffer[idx] = val;
	return 1;
}

void transport_light_led_driver(){

	uint8_t temp =0x0;
	for(int i = 0; i<= NUMBER_OF_LEDS; i++) temp |= translightLEDConversion[translightLEDBuffer[i]]<<(i*NUMBER_OF_LIGHTS);
	//if sevenSegmentLEDBuffer[0] = 0; what the value of temp? = sevenSegmentLEDConversion[0]
	//temp = 0x3f 0b00111111
	if(temp & 0x01){ //what is the value of temp & 0x01 = 0x01 --> TRUE
		HAL_GPIO_WritePin(LED_1_A_PORT, LED_1_A, RESET);
	} else{
		HAL_GPIO_WritePin(LED_1_A_PORT, LED_1_A, SET);
	}

	if(temp & 0x02){
		HAL_GPIO_WritePin(LED_1_B_PORT, LED_1_B, RESET);
	} else{
		HAL_GPIO_WritePin(LED_1_B_PORT, LED_1_B, SET);
	}

	if(temp & 0x04){
		HAL_GPIO_WritePin(LED_1_C_PORT, LED_1_C, RESET);
	} else{
		HAL_GPIO_WritePin(LED_1_C_PORT, LED_1_C, SET);
	}

	if(temp & 0x08){
		HAL_GPIO_WritePin(LED_1_D_PORT, LED_1_D, RESET);
	} else{
		HAL_GPIO_WritePin(LED_1_D_PORT, LED_1_D, SET);
	}

	if(temp & 0x10){
		HAL_GPIO_WritePin(LED_1_E_PORT, LED_1_E, RESET);
	} else{
		HAL_GPIO_WritePin(LED_1_E_PORT, LED_1_E, SET);
	}
//
	if(temp & 0x20){
		HAL_GPIO_WritePin(LED_1_F_PORT, LED_1_F, RESET);
	} else{
		HAL_GPIO_WritePin(LED_1_F_PORT, LED_1_F, SET);
	}

}

void blinkLED(int mode){
	if(mode==2){
		HAL_GPIO_TogglePin(LED_1_A_PORT, LED_1_A);
		HAL_GPIO_TogglePin(LED_1_D_PORT, LED_1_D);

		HAL_GPIO_WritePin(LED_1_B_PORT, LED_1_B, RESET);
		HAL_GPIO_WritePin(LED_1_C_PORT, LED_1_C, RESET);
		HAL_GPIO_WritePin(LED_1_E_PORT, LED_1_E, RESET);
		HAL_GPIO_WritePin(LED_1_F_PORT, LED_1_F, RESET);
	}
	else if(mode==3){
		HAL_GPIO_TogglePin(LED_1_B_PORT, LED_1_B);
		HAL_GPIO_TogglePin(LED_1_E_PORT, LED_1_E);

		HAL_GPIO_WritePin(LED_1_A_PORT, LED_1_A, RESET);
		HAL_GPIO_WritePin(LED_1_C_PORT, LED_1_C, RESET);
		HAL_GPIO_WritePin(LED_1_D_PORT, LED_1_D, RESET);
		HAL_GPIO_WritePin(LED_1_F_PORT, LED_1_F, RESET);
	}
	else if(mode==4){
		HAL_GPIO_TogglePin(LED_1_C_PORT, LED_1_C);
		HAL_GPIO_TogglePin(LED_1_F_PORT, LED_1_F);

		HAL_GPIO_WritePin(LED_1_B_PORT, LED_1_B, RESET);
		HAL_GPIO_WritePin(LED_1_A_PORT, LED_1_A, RESET);
		HAL_GPIO_WritePin(LED_1_E_PORT, LED_1_E, RESET);
		HAL_GPIO_WritePin(LED_1_D_PORT, LED_1_D, RESET);
	}
}



