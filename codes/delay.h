#include "stm32f1xx.h"

#ifndef _DELAY_H

#define _DELAY_H


    
void delayMs(int ms){

    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk ;
    SysTick->CTRL &= ~(SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk);

    SysTick->LOAD = 9000;
    
    while(ms--){

        while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));

    }

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; 

}

void delayUs(int Us){

    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk ;
    SysTick->CTRL &= ~(SysTick_CTRL_CLKSOURCE_Msk| SysTick_CTRL_TICKINT_Msk);

    SysTick->LOAD = 9;
    
    while(Us--){

        while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));

    }

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; 

}

#endif