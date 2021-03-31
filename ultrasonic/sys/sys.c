#include "sys.h"
#include "RCC.h"
#include "delay.h"
#include "IO.h"
#include "TIM.h"
#include "USART.h"
void System_Init(void)
{
	SystemClock_Config();//HSI16/4 -> PLL*8/2->16M	
	delay_init(16);
	TIM_Init();
	Configure_USART_MAIN(USART_MAIN_BOUND);
	IO_Init();
}


void System_Task(void)
{
	if(F_TASK_SR04)
	{
		F_TASK_SR04=0;
		TASK_SR04();
	}
  if(KEY_State==0)
	{
		delay_ms(10);
		if(KEY_State==0)
			mcu_set_wifi_mode(0);
	}		
}

