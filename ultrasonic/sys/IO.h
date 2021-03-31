#ifndef __IO_H
#define __IO_H 		
#include "MY_ST_config.h"

//	 	PC2
#define PC2_OUT {RCC->IOPENR|=1<<2;GPIOC->MODER&=~(3<<4);GPIOC->MODER|=1<<4;} 
#define PC2_SET GPIOC->ODR|=1<<2
#define PC2_RESET  GPIOC->ODR&=~(1<<2)
#define PC2_TOG GPIOC->ODR^=1<<2

//LED_CTRL4	 	PA5
#define LED_4_OUT {RCC->IOPENR|=1<<0;GPIOA->MODER&=~(3<<10);GPIOA->MODER|=1<<10;} 
#define LED_4_SET GPIOA->ODR|=1<<5
#define LED_4_RESET  GPIOA->ODR&=~(1<<5)
#define LED_4_TOG GPIOA->ODR^=1<<5

//PC13
#define KEY_IN  {RCC->IOPENR|=1<<2;GPIOC->MODER&=~(3<<26);GPIOC->MODER|=0<<26;} 
#define KEY_State ((GPIOC->IDR & 1<<13) == 1<<13)
extern uint8_t F_TASK_SR04;
void TASK_SR04(void);
void IO_Init(void);
	
#endif

