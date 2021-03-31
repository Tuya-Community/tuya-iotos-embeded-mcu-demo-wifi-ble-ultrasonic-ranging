#include "IO.h"
#include "delay.h"
#include "TIM.h"
#include "USART.h"


uint8_t F_TASK_SR04=0;


void SR04_Init(void)
{
	PC2_OUT;
	PC2_RESET;
	
	RCC->IOPENR|=1<<2;
	GPIOC->MODER&=~(3<<6);
	GPIOC->MODER|=0<<6;
	EXTI->EXTICR[0] &= ~(0xf<<24);
	EXTI->EXTICR[0] |= 2<<24;//设置PC3为中断
  EXTI->IMR1 |= 1<<3;//开放来自Line3的中断
  EXTI->RTSR1 |= 1<<3;//允许Line3上升沿中断
	EXTI->FTSR1 |= 1<<3;//允许Line3下降沿中断
  NVIC_SetPriority(EXTI2_3_IRQn, 1); 
  NVIC_EnableIRQ(EXTI2_3_IRQn);
}

void EXTI2_3_IRQHandler(void)
{
  if((EXTI->RPR1 & 1<<3) == 1<<3)//发生了上升沿触发请求
  {
    /* Clear EXTI 3 flag */
    EXTI->RPR1 = 1<<3;
		TIM7->CR1 |=1<<0;//使能计数器
  }
  else if((EXTI->FPR1 & 1<<3) == 1<<3)//发生了下降沿触发请求
  {
    uint16_t wide;
    EXTI->FPR1 = 1<<3;		//* Clear EXTI 3 flag 
		TIM7->CR1 &=~(1<<0);	//禁止计数器
		wide=TIM7->CNT*17;
		mcu_dp_value_update(DPID_DISTANCE,wide);
		TIM7->CNT =0;//计数清零
  }	
}


void TASK_SR04(void)
{
	PC2_SET;
	delay_us(15);
	PC2_RESET;
	
}

void IO_Init(void)
{
	SR04_Init();
	LED_4_OUT;
	LED_4_RESET;
	KEY_IN;
}
