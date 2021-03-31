#include "TIM.h"
#include "IO.h"


void TIM6_Init(uint16_t arr,uint16_t psc)//TASK分配
{
	RCC->APBENR1 |= 1<<4;
	TIM6->ARR = arr;
	TIM6->PSC = psc;
	TIM6->DIER |= 1<<0;//使能更新中断
	TIM6->CR1 |= 1<<0;//使能计数器
	NVIC_SetPriority(TIM6_DAC_LPTIM1_IRQn, 1); 
	NVIC_EnableIRQ(TIM6_DAC_LPTIM1_IRQn);
}
void TIM6_Start(void)
{
	TIM6->CR1 |=1<<0;//使能计数器
}
void TIM6_Stop(void)
{
	TIM6->CR1 &=~(1<<0);	//禁止计数器
	TIM6->CNT =0;//计数清零
}
uint8_t F_TASK_TIM6=0;
void TIM6_DAC_LPTIM1_IRQHandler(void)
{
	if ((TIM6->SR & 1) == 1) /* Check ARR match */ 
	{	
		TIM6->SR &= ~(1<<0);//清除中断标志位
		F_TASK_SR04=1;
		switch(mcu_get_wifi_work_state())
		{
			case SMART_CONFIG_STATE:
			case AP_STATE:LED_4_SET;break;
			case WIFI_NOT_CONNECTED:
			case WIFI_CONNECTED:LED_4_TOG;break;
			case WIFI_CONN_CLOUD:LED_4_RESET;break;
			case WIFI_LOW_POWER:		LED_4_RESET;break;
			case SMART_AND_AP_STATE:LED_4_RESET;break;
			default :LED_4_RESET;break;
		}		
	}
}



void TIM7_Init(uint16_t arr,uint16_t psc)
{
	RCC->APBENR1 |= 1<<5;
	TIM7->ARR = arr;
	TIM7->PSC = psc;
	TIM7->DIER |= 1<<0;//使能更新中断
	TIM7->CR1 |= 1<<0;//使能计数器
	NVIC_SetPriority(TIM7_LPTIM2_IRQn, 1); 
	NVIC_EnableIRQ(TIM7_LPTIM2_IRQn);
}
void TIM7_Start(void)
{
	TIM7->CR1 |=1<<0;//使能计数器
}
void TIM7_Stop(void)
{
	TIM7->CR1 &=~(1<<0);	//禁止计数器
	TIM7->CNT =0;//计数清零
}

void TIM7_LPTIM2_IRQHandler(void)
{
	if ((TIM7->SR & 1) == 1) /* Check ARR match */ 
	{		
		TIM7->SR &= ~(1<<0);//清除中断标志位
	}
}
void TIM_Init(void)
{	
	TIM6_Init(300,15999);	
	TIM7_Init(10000,159);//100ms
	TIM7_Stop();
}




