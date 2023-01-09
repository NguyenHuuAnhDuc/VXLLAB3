#include "main.h"
#include "led_display.h"

#define NUMBER_OF_DECIMAL_DIGITS			10
#define	NUMBER_OF_SEVEN_SEGMENT_LEDS		2
#define	NUMBER_OF_LEDS						7

#define SEVEN_SEGMENT_1_A			GPIO_PIN_0
#define SEVEN_SEGMENT_1_A_PORT		GPIOB
#define SEVEN_SEGMENT_1_B			GPIO_PIN_1
#define SEVEN_SEGMENT_1_B_PORT		GPIOB
#define SEVEN_SEGMENT_1_C			GPIO_PIN_2
#define SEVEN_SEGMENT_1_C_PORT		GPIOB
#define SEVEN_SEGMENT_1_D			GPIO_PIN_3
#define SEVEN_SEGMENT_1_D_PORT		GPIOB
#define SEVEN_SEGMENT_1_E			GPIO_PIN_4
#define SEVEN_SEGMENT_1_E_PORT		GPIOB
#define SEVEN_SEGMENT_1_F			GPIO_PIN_5
#define SEVEN_SEGMENT_1_F_PORT		GPIOB
#define SEVEN_SEGMENT_1_G			GPIO_PIN_6
#define SEVEN_SEGMENT_1_G_PORT		GPIOB

#define SEVEN_SEGMENT_2_A			GPIO_PIN_7
#define SEVEN_SEGMENT_2_A_PORT		GPIOB
#define SEVEN_SEGMENT_2_B			GPIO_PIN_8
#define SEVEN_SEGMENT_2_B_PORT		GPIOB
#define SEVEN_SEGMENT_2_C			GPIO_PIN_9
#define SEVEN_SEGMENT_2_C_PORT		GPIOB
#define SEVEN_SEGMENT_2_D			GPIO_PIN_10
#define SEVEN_SEGMENT_2_D_PORT		GPIOB
#define SEVEN_SEGMENT_2_E			GPIO_PIN_11
#define SEVEN_SEGMENT_2_E_PORT		GPIOB
#define SEVEN_SEGMENT_2_F			GPIO_PIN_12
#define SEVEN_SEGMENT_2_F_PORT		GPIOB
#define SEVEN_SEGMENT_2_G			GPIO_PIN_13
#define SEVEN_SEGMENT_2_G_PORT		GPIOB

//common Anode
//static uint8_t sevenSegmentLEDConversion[NUMBER_OF_DECIMAL_DIGITS] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

//common Cathode
static uint8_t sevenSegmentLEDConversion[NUMBER_OF_DECIMAL_DIGITS] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78 ,0x00 ,0x10};

static uint8_t sevenSegmentLEDBuffer[NUMBER_OF_SEVEN_SEGMENT_LEDS];



uint8_t update_seven_segment_led_buffer(uint8_t val, uint8_t idx){
	if(idx >= NUMBER_OF_SEVEN_SEGMENT_LEDS) return 0;
	if(val > NUMBER_OF_DECIMAL_DIGITS) return 0;
	sevenSegmentLEDBuffer[idx] = val;
	return 1;
}


void seven_segment_led_driver(){
	//uint16_t temp = sevenSegmentLEDConversion[sevenSegmentLEDBuffer[idx]]<<(7);
	//uint8_t temp = sevenSegmentLEDConversion[sevenSegmentLEDBuffer[idx]]<<(7);
	uint16_t temp = 0x0;
	for(int i = 0; i<=NUMBER_OF_SEVEN_SEGMENT_LEDS; i++) temp |= sevenSegmentLEDConversion[sevenSegmentLEDBuffer[i]]<<(i*NUMBER_OF_LEDS);

	//if sevenSegmentLEDBuffer[0] = 0; what the value of temp? = sevenSegmentLEDConversion[0]
	//temp = 0x3f 0b00111111
	if(temp & 0x01){ //what is the value of temp & 0x01 = 0x01 --> TRUE
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_A_PORT, SEVEN_SEGMENT_1_A, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_A_PORT, SEVEN_SEGMENT_1_A, RESET);
	}

	if(temp & 0x02){
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_B_PORT, SEVEN_SEGMENT_1_B, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_B_PORT, SEVEN_SEGMENT_1_B, RESET);
	}

	if(temp & 0x04){
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_C_PORT, SEVEN_SEGMENT_1_C, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_C_PORT, SEVEN_SEGMENT_1_C, RESET);
	}

	if(temp & 0x08){
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_D_PORT, SEVEN_SEGMENT_1_D, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_D_PORT, SEVEN_SEGMENT_1_D, RESET);
	}

	if(temp & 0x10){
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_E_PORT, SEVEN_SEGMENT_1_E, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_E_PORT, SEVEN_SEGMENT_1_E, RESET);
	}
//
	if(temp & 0x20){
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_F_PORT, SEVEN_SEGMENT_1_F, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_F_PORT, SEVEN_SEGMENT_1_F, RESET);
	}
//	//temp = 0x3f
	if(temp & 0x40){ //true or false?
 		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_G_PORT, SEVEN_SEGMENT_1_G, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_G_PORT, SEVEN_SEGMENT_1_G, RESET);
	}



	if(temp & 0x80){ //what is the value of temp & 0x01 = 0x01 --> TRUE
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_A_PORT, SEVEN_SEGMENT_2_A, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_A_PORT, SEVEN_SEGMENT_2_A, RESET);
	}

	if(temp & 0x100){
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_B_PORT, SEVEN_SEGMENT_2_B, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_B_PORT, SEVEN_SEGMENT_2_B, RESET);
	}

	if(temp & 0x200){
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_C_PORT, SEVEN_SEGMENT_2_C, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_C_PORT, SEVEN_SEGMENT_2_C, RESET);
	}

	if(temp & 0x400){
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_D_PORT, SEVEN_SEGMENT_2_D, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_D_PORT, SEVEN_SEGMENT_2_D, RESET);
	}

	if(temp & 0x800){
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_E_PORT, SEVEN_SEGMENT_2_E, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_E_PORT, SEVEN_SEGMENT_2_E, RESET);
	}
//
	if(temp & 0x1000){
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_F_PORT, SEVEN_SEGMENT_2_F, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_F_PORT, SEVEN_SEGMENT_2_F, RESET);
	}
//	//temp = 0x3f
	if(temp & 0x2000){ //true or false?
 		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_G_PORT, SEVEN_SEGMENT_2_G, SET);
	} else{
		HAL_GPIO_WritePin(SEVEN_SEGMENT_2_G_PORT, SEVEN_SEGMENT_2_G, RESET);
	}
//
//	if(temp & 0x80){
//		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_H_PORT, SEVEN_SEGMENT_1_H, SET);
//	} else{
//		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_H_PORT, SEVEN_SEGMENT_1_H, RESET);
//	}

}

void display7SEG (int num){
	  uint8_t temp = sevenSegmentLEDConversion[num];
		if(temp & 0x01){ //what is the value of temp & 0x01 = 0x01 --> TRUE
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_A_PORT, SEVEN_SEGMENT_1_A, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_A_PORT, SEVEN_SEGMENT_1_A, RESET);
		}

		if(temp & 0x02){
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_B_PORT, SEVEN_SEGMENT_1_B, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_B_PORT, SEVEN_SEGMENT_1_B, RESET);
		}

		if(temp & 0x04){
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_C_PORT, SEVEN_SEGMENT_1_C, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_C_PORT, SEVEN_SEGMENT_1_C, RESET);
		}

		if(temp & 0x08){
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_D_PORT, SEVEN_SEGMENT_1_D, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_D_PORT, SEVEN_SEGMENT_1_D, RESET);
		}

		if(temp & 0x10){
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_E_PORT, SEVEN_SEGMENT_1_E, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_E_PORT, SEVEN_SEGMENT_1_E, RESET);
		}
	//
		if(temp & 0x20){
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_F_PORT, SEVEN_SEGMENT_1_F, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_F_PORT, SEVEN_SEGMENT_1_F, RESET);
		}
	//	//temp = 0x3f
		if(temp & 0x40){ //true or false?
	 		HAL_GPIO_WritePin(SEVEN_SEGMENT_1_G_PORT, SEVEN_SEGMENT_1_G, SET);
		} else{
			HAL_GPIO_WritePin(SEVEN_SEGMENT_1_G_PORT, SEVEN_SEGMENT_1_G, RESET);
		}
  }



