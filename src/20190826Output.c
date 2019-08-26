
#include <stm32f10x_lib.h>                        // STM32F10x Library Definitions
#include "STM32_Init.h"                           // STM32 Initialization
/*----------------------------------------------------------*\
 | HARDWARE DEFINE                                          |
\*----------------------------------------------------------*/
#define LED             ( 1 << 5 )                // PB5: LED D2
#define LED6            ( 1 << 6 )                // PB5: LED D2
#define LED7            ( 1 << 7 )                // PB5: LED D2

void Delay(vu32 nCount) {
  for(; nCount != 0; nCount--);
  }


	
/*----------------------------------------------------------*\
 | MIAN ENTRY                                               |
\*----------------------------------------------------------*/
int main (void) {
  

	stm32_Init ();                                  // STM32 setup
	
	//*(volatile unsigned int*)0x40021018 = 0x10;//RCC
	//*(volatile unsigned int*)0x40011004 &= ~(0x0f << 20);//PORTC clear
	//*(volatile unsigned int*)0x40011004 |= (0x03 << 20);//PORTC 13 mode setting
	*(volatile unsigned int*)0x40021018 = 0x08;
	*(volatile unsigned int*)0x40010C00 &= ~(0x0f << 28);
	*(volatile unsigned int*)0x40010C00 |= (0x03 << 28);
	for(;;){
		//*(volatile unsigned int*)0x4001100C = 0x00;
		*(volatile unsigned int*)0x40010C0C = 0x00;
		Delay(20000);
		//*(volatile unsigned int*)0x4001100C = 0x2000;
		*(volatile unsigned int*)0x40010C0C = 0x0080;
		Delay(20000);
	}
	
//	*(volatile unsigned int *)0x40021018 = 0x04;
//	*(volatile unsigned int *)0x40020800 = 0x03;
//	*(volatile unsigned int *)0x40020800 = 0x03;
//	*(volatile unsigned int *)0x40010C00 = 0x03;
//  for(;;) {
//		*(volatile unsigned int *)0x4001080C = 0x01;
//		Delay(20000);
//		*(volatile unsigned int *)0x4001080C = 0x00;
//		Delay(20000);
//    GPIOB->ODR &= ~LED;                           // switch on LED
//    GPIOB->ODR &= ~LED6;                           // switch on LED
//    GPIOB->ODR |= LED7;                           // switch on LED
//	Delay(2000000);
//    GPIOB->ODR |=  LED;                           // switch off LED
//    GPIOB->ODR |=  LED6;                           // switch on LED
//    GPIOB->ODR &=  ~LED7;                           // switch on LED
//	Delay(2000000);

//    }
   
  }
/*----------------------------------------------------------*\
 | END OF FILE                                              |
\*----------------------------------------------------------*/
