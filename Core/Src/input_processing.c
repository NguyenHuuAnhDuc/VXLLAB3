# include "main.h"
# include "input_reading.h"
# include "led_display.h"

const int MAX_LED = 4;
int index_led = 0;

const int TIMER_CYCLE = 10; //ms

int switch_counter = 0;
int timer0_counter = 0;
int blink_counter = 0;

int switch_flag = 0;
int timer0_flag = 0;
int blink_flag = 0;

int value1 = 0;
int value2 = 0;
int TRAFFIC_LIGHT_MAX[3] = {99, 3, 2}; //RED, GREEN, YELLOW
int TRAFFIC_LIGHT_MAX_TEMP[3] = {99, 3, 2}; //RED, GREEN, YELLOW
uint8_t state1 = 0; //RED
uint8_t state2 = 1; //GREEN

enum ModeState { INIT, MODE1 , MODE2 ,MODE3, MODE4 } ;
enum ModeState modeState = INIT ;

 int led_buffer [4] = {0 , 0 , 0 , 0};


 void update7SEG ( int index ) {
 	switch ( index ) {
 	case 0:
 		HAL_GPIO_WritePin ( SWITCH_1_B_PORT, SWITCH_1_B, SET ) ;
 		HAL_GPIO_WritePin ( SWITCH_1_C_PORT, SWITCH_1_C, SET ) ;
 		HAL_GPIO_WritePin ( SWITCH_1_D_PORT, SWITCH_1_D, SET ) ;
 		display7SEG (led_buffer[index]);
 		HAL_GPIO_WritePin ( SWITCH_1_A_PORT, SWITCH_1_A, RESET ) ;
 		break;
 	case 1:
 		HAL_GPIO_WritePin ( SWITCH_1_A_PORT, SWITCH_1_A, SET ) ;
 		HAL_GPIO_WritePin ( SWITCH_1_C_PORT, SWITCH_1_C, SET ) ;
 		HAL_GPIO_WritePin ( SWITCH_1_D_PORT, SWITCH_1_D, SET ) ;
 		display7SEG (led_buffer[index]);
 		HAL_GPIO_WritePin ( SWITCH_1_B_PORT, SWITCH_1_B, RESET ) ;
 		break;
 	case 2:
 		HAL_GPIO_WritePin ( SWITCH_1_A_PORT, SWITCH_1_A, SET ) ;
 		HAL_GPIO_WritePin ( SWITCH_1_B_PORT, SWITCH_1_B, SET ) ;
 		HAL_GPIO_WritePin ( SWITCH_1_D_PORT, SWITCH_1_D, SET ) ;
 		display7SEG (led_buffer[index]);
 		HAL_GPIO_WritePin ( SWITCH_1_C_PORT, SWITCH_1_C, RESET ) ;
 		break;
 	case 3:
 		HAL_GPIO_WritePin ( SWITCH_1_A_PORT, SWITCH_1_A, SET ) ;
 		HAL_GPIO_WritePin ( SWITCH_1_B_PORT, SWITCH_1_B, SET ) ;
 		HAL_GPIO_WritePin ( SWITCH_1_C_PORT, SWITCH_1_C, SET ) ;
 		display7SEG (led_buffer[index]);
 		HAL_GPIO_WritePin ( SWITCH_1_D_PORT, SWITCH_1_D, RESET ) ;
 		break;
 	default:
 		break;
 	}
 }

 void setSwitch0 ( int duration ) {
 	switch_counter = duration / TIMER_CYCLE ;
 	switch_flag = 0;
 }

 void setTimer0 ( int duration ) {
 	timer0_counter = duration / TIMER_CYCLE ;
 	timer0_flag = 0;
 }

 void setBlink0 ( int duration ) {
 	blink_counter = duration / TIMER_CYCLE ;
 	blink_flag = 0;
 }

 void timer_run() {

  	if( timer0_counter > 0) {
  		timer0_counter--;
  		if( timer0_counter == 0) timer0_flag = 1;
  		else {
  			 transport_light_led_driver();
  		}
  	}

  	if( switch_counter > 0) {
  		switch_counter--;
  			if( switch_counter == 0) switch_flag = 1;
  	}

  	if( blink_counter > 0 && modeState != MODE1) {
  		blink_counter--;
  			if( blink_counter == 0) blink_flag = 1;
  	}

  }

//  void timer_run_mode2() {
//  	if( switch_counter > 0) {
//  		switch_counter--;
//  			if( switch_counter == 0) switch_flag = 1;
//  	}
//  	if( blink_counter > 0) {
//  		blink_counter--;
//  			if( blink_counter == 0) blink_flag = 1;
//  	}
//  }

 void update_7SEG_buffer(enum ModeState mode){
	 switch(mode){
	 case INIT:

		 	break;
	 case MODE1:
		 	led_buffer[0] = value1/10;
		 	led_buffer[1] = value1%10;
		 	led_buffer[2] = value2/10;
		 	led_buffer[3] = value2%10;
		 	break;
	 case MODE2:
		 	led_buffer[0] = 0;
		 	led_buffer[1] = 2;
		 	led_buffer[2] = TRAFFIC_LIGHT_MAX_TEMP[0]/10;
		 	led_buffer[3] = TRAFFIC_LIGHT_MAX_TEMP[0]%10;
		 	break;
	 case MODE3:
	 		 	led_buffer[0] = 0;
	 		 	led_buffer[1] = 3;
	 		 	led_buffer[2] = TRAFFIC_LIGHT_MAX_TEMP[2]/10;
	 		 	led_buffer[3] = TRAFFIC_LIGHT_MAX_TEMP[2]%10;
	 		 	break;
	 case MODE4:
	 		 	led_buffer[0] = 0;
	 		 	led_buffer[1] = 4;
	 		 	led_buffer[2] = TRAFFIC_LIGHT_MAX_TEMP[1]/10;
	 		 	led_buffer[3] = TRAFFIC_LIGHT_MAX_TEMP[1]%10;
	 		 	break;
	 }
 }

// void update_led_buffer_mode2(){
// 	led_buffer[0] = 0;
// 	led_buffer[1] = 2;
// 	led_buffer[2] = TRAFFIC_LIGHT_MAX[0]/10;
// 	led_buffer[3] = TRAFFIC_LIGHT_MAX[0]%10;
// }



 void fsm_for_input_processing ( void ) {



	 switch ( modeState ){
	 	 case INIT :
	 		 modeState = MODE1 ;  // change mode state
	 		 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);

	 		 //set up for 1st group of traffic lights
	 		 value1 = TRAFFIC_LIGHT_MAX[state1];
	 		 update_light_led_buffer(state1, 0);

	 		 //set up for 2nd group of traffic lights
	 		 value2 = TRAFFIC_LIGHT_MAX[state2];
	 		 update_light_led_buffer(state2, 1);
	 		 update_7SEG_buffer(MODE1);

	 		 //set timer
	 		 setSwitch0 (100);
	 		 setTimer0 (1000);
	 		 break;


		 case MODE1 :
			 if( !is_button_pressed (0) ) {
				 // INCREASE VALUE OF PORT A BY ONE UNIT
				 if(timer0_flag) { //update traffic light value every 1000ms

					  value1--;
					  value2--;
					  if(!value1) {
						  state1 = (state1+1)%3;
						  value1 = TRAFFIC_LIGHT_MAX[state1];
						  update_light_led_buffer(state1, 0);

					  }
					  if(!value2) {
						  state2 = (state2+1)%3;
						  value2 = TRAFFIC_LIGHT_MAX[state2];
						  update_light_led_buffer(state2, 1);

					  }
					  update_7SEG_buffer(MODE1);
					  setTimer0 (1000);
				 }

				if(switch_flag){ //change led and update display value every 250ms

					   	  	  		update7SEG (index_led);
					   	  	  		if(index_led==3) index_led=0;
					   	  	  		else index_led++;
					   	  	  		setSwitch0 (250);
				}

			 }
			 else {
				 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
				 HAL_GPIO_WritePin (GPIOA , GPIO_PIN_5, RESET ) ;
				 HAL_GPIO_WritePin (GPIOA , GPIO_PIN_8, RESET ) ;
				 modeState = MODE2 ;
				 update_7SEG_buffer(MODE2);
				 setBlink0 (500);


			 }
			 break ;
		 case MODE2 :
			 if (! is_button_pressed (0) ) {

				 if ( is_button_pressed (1) ) {
					 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
					 TRAFFIC_LIGHT_MAX_TEMP[0]=TRAFFIC_LIGHT_MAX_TEMP[0]+1;
					 if (TRAFFIC_LIGHT_MAX_TEMP[0] > 99) TRAFFIC_LIGHT_MAX_TEMP[0] = 0;
					 update_7SEG_buffer(MODE2);
				 }
				 if ( is_button_pressed (2) ) {
					 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
					 TRAFFIC_LIGHT_MAX[0] = TRAFFIC_LIGHT_MAX_TEMP[0];

					 modeState = MODE3;
					 update_7SEG_buffer(MODE3);
					 //setTimer0 (1000);
				 }
				 if(blink_flag) { //blink red led every 500ms
				 	  		  blinkLED(2);
				 	  		  setBlink0 (500);
				}
				if(switch_flag){

						   	  	  		update7SEG (index_led);
						   	  	  		if(index_led==3) index_led=0;
						   	  	  		else index_led++;
						   	  	  		setSwitch0 (250);
				}
			 }
			 else {
				 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
				 HAL_GPIO_WritePin (GPIOA , GPIO_PIN_6, RESET ) ;
				 HAL_GPIO_WritePin (GPIOA , GPIO_PIN_9, RESET ) ;

				 TRAFFIC_LIGHT_MAX_TEMP[0] = TRAFFIC_LIGHT_MAX[0];
				 modeState = MODE3 ;
				 update_7SEG_buffer(MODE3);
				 //setTimer0 (1000);
			 }
			 break ;
		 case MODE3 :
			 if (! is_button_pressed (0) ) {
				 if ( is_button_pressed (1) ) {
					 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
					 TRAFFIC_LIGHT_MAX_TEMP[2]=TRAFFIC_LIGHT_MAX_TEMP[2]+1;
					 if (TRAFFIC_LIGHT_MAX_TEMP[2] > 99) TRAFFIC_LIGHT_MAX_TEMP[2] = 0;
					 update_7SEG_buffer(MODE3);
				 }
				 if ( is_button_pressed (2) ) {
					 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
					 TRAFFIC_LIGHT_MAX[2] = TRAFFIC_LIGHT_MAX_TEMP[2];

					 modeState = MODE4;
					 update_7SEG_buffer(MODE4);
					 //setTimer0 (1000);
				 }
				 if(blink_flag) {
				 	  		  blinkLED(3);
				 	  		  setBlink0 (500);
				}
				if(switch_flag){

						   	  update7SEG (index_led);
						   	  if(index_led==3) index_led=0;
						   	  else index_led++;
						   	  setSwitch0 (250);
				}
			 }
			 else {
				 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
				 HAL_GPIO_WritePin (GPIOA , GPIO_PIN_7, RESET ) ;
				 HAL_GPIO_WritePin (GPIOA , GPIO_PIN_10, RESET ) ;

				 TRAFFIC_LIGHT_MAX_TEMP[2] = TRAFFIC_LIGHT_MAX[2];
				 modeState = MODE4 ;
				 update_7SEG_buffer(MODE4);
				 //setTimer0 (1000);
			 }
			 break ;
		 case MODE4 :
			 if (! is_button_pressed (0) ) {
				 if ( is_button_pressed (1) ) {
					 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
					 TRAFFIC_LIGHT_MAX_TEMP[1]=TRAFFIC_LIGHT_MAX_TEMP[1]+1;
					 if (TRAFFIC_LIGHT_MAX_TEMP[1] > 99) TRAFFIC_LIGHT_MAX_TEMP[1] = 0;
					 update_7SEG_buffer(MODE4);
				 }
				 if ( is_button_pressed (2) ) {
					 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
					 TRAFFIC_LIGHT_MAX[1] = TRAFFIC_LIGHT_MAX_TEMP[1];

					 modeState = MODE1 ;
					 update_7SEG_buffer(MODE1);
					 //setTimer0 (1000);
				 }
				 if(blink_flag) {
				 	  		  blinkLED(4);
				 	  		  setBlink0 (500);
				}
				if(switch_flag){

						   	  update7SEG (index_led);
						   	  if(index_led==3) index_led=0;
						   	  else index_led++;
						   	  setSwitch0 (250);
				}
			 }
			 else {
				 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
				 TRAFFIC_LIGHT_MAX_TEMP[1] = TRAFFIC_LIGHT_MAX[1];
				 modeState = MODE1 ;

				 state1 = 0; //RED
		 		 value1 = TRAFFIC_LIGHT_MAX[state1];
		 		 update_light_led_buffer(state1, 0);

		 		 state2 = 1; //GREEN
		 		 value2 = TRAFFIC_LIGHT_MAX[state2];
		 		 update_light_led_buffer(state2, 1);
				 update_7SEG_buffer(MODE1);
				 //setTimer0 (1000);
			 }
		 	 break ;
	 }
 }





