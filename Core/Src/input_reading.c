# include "main.h"
// we aim to work with more than one buttons
# define N0_OF_BUTTONS 3
// timer interrupt duration is 10ms , so to pass 1 second ,
// we need to jump to the interrupt service routine 100 time
# define DURATION_FOR_AUTO_INCREASING 100
# define READ_BUTTON_IS_PRESSED GPIO_PIN_RESET
# define READ_BUTTON_IS_RELEASED GPIO_PIN_SET

enum ButtonState {BUTTON_IS_PRESSED, BUTTON_IS_RELEASED, BUTTON_IS_HOLD};
// the buffer that the final result is stored after
 // debouncing
 static enum ButtonState buttonBuffer [ N0_OF_BUTTONS ] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
 // we define two buffers for debouncing
 static GPIO_PinState debounceButtonBuffer1 [ N0_OF_BUTTONS ];
 static GPIO_PinState debounceButtonBuffer2 [ N0_OF_BUTTONS ];
 // we define a flag for a button pressed more than 1 second .
// static uint8_t flagForButtonPress1s [ N0_OF_BUTTONS ];
 // we define counter for automatically increasing the value
 // after the button is pressed more than 1 second .
// static uint16_t counterForButtonPress1s [ N0_OF_BUTTONS ];

 GPIO_PinState readPin ( uint8_t n ) {

	 switch(n){

	 case 0:
		 return HAL_GPIO_ReadPin (GPIOA , GPIO_PIN_1 ) ;
	 case 1:
	 	 return HAL_GPIO_ReadPin (GPIOA , GPIO_PIN_2 ) ;
	 case 2:
		 return HAL_GPIO_ReadPin (GPIOA , GPIO_PIN_3 );

	 default:
	 	return 0;
	 }

 }
 void button_reading ( void ) {
	 for ( uint8_t i = 0; i < N0_OF_BUTTONS ; i ++) {
		 debounceButtonBuffer2 [ i ] = debounceButtonBuffer1 [ i ];
		 debounceButtonBuffer1 [ i ] = readPin (i) ;
		 if( debounceButtonBuffer1 [i] == debounceButtonBuffer2 [i]) {

			 if(debounceButtonBuffer1 [i] == READ_BUTTON_IS_PRESSED ){

				 if(buttonBuffer [ i] == BUTTON_IS_HOLD)
					 buttonBuffer [ i] = BUTTON_IS_HOLD;
				 else
					 buttonBuffer [ i] = BUTTON_IS_PRESSED;

			 }
			 else {
				 buttonBuffer [ i] = BUTTON_IS_RELEASED;
//				 press_counter = 0;
			 }
		 }
//		 if( buttonBuffer [i ] == BUTTON_IS_PRESSED || buttonBuffer [i ] == BUTTON_IS_HOLD) {
//			 if(buttonBuffer [i ] == BUTTON_IS_PRESSED) buttonBuffer [i ] = BUTTON_IS_HOLD;
//			 // if a button is pressed , we start counting
//			 if( counterForButtonPress1s [ i ] < DURATION_FOR_AUTO_INCREASING ) {
//				 counterForButtonPress1s [ i ]++;
//			 }
//			 else {
//				 // the flag is turned on when 1 second has passed
//				 // since the button is pressed .
//				 flagForButtonPress1s [i ] = 1;
//				 // todo
//			 }
//		 }
//		 else {
//			 counterForButtonPress1s [i ] = 0;
//			 flagForButtonPress1s [i ] = 0;
//		 }
	 }
 }


unsigned char is_button_pressed ( uint8_t index ) {
 if( index >= N0_OF_BUTTONS ) return 0;
 if(buttonBuffer [ index ] == BUTTON_IS_PRESSED) {
	 buttonBuffer [ index ] = BUTTON_IS_HOLD;
	 return 1;
 }
 else return 0;
}

//unsigned char is_button_pressed_1s ( unsigned char index ) {
// if( index >= N0_OF_BUTTONS ) return 0xff ;
// return ( flagForButtonPress1s [ index ] == 1) ;
// }
