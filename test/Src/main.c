/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f0xx.h"

void pausing(uint32_t cycle_num)
{
	for (volatile uint32_t j = 0; j < cycle_num; j++) {}
}

int main(void)
{
	/* LED2 setup */
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER5_0;

	/* Morse sequence */
	uint32_t sos = 0b10101001110111011100101010000000;

	/* blinking */
	for(;;)
	{
		for (uint32_t i = 0; i < 32; i++){
			if ((sos<<i) & 0x80000000){
				GPIOA->BSRR = (1<<5); // set
			}
			else{
				GPIOA->BRR = (1<<5); // reset
			}
			pausing(100000);
		}
		pausing(500000);
	}
}
