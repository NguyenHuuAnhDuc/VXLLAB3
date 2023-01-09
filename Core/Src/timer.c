# include "main.h"
# include "input_reading.h"



void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	if(htim->Instance == TIM2 ) {
		button_reading () ;
		timer_run();
//		switch(modeState){
//			case MODE1:
//				timer_run_mode1();
//				break;
//			case MODE2:
//				timer_run_mode2();
//				break;
//		}
	}
}
