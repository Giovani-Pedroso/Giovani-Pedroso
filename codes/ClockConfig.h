#include "stm32f1xx.h"

#ifndef _CLOCK_CONFIG_H

#define _CLOCK_CONFIG_H

void ClockConfig_Init(){

//1° step activate the HSE and wait untill be ready

    //Enable the extrenal clock aka cystral
    RCC->CR |= RCC_CR_HSEON;

    //Wait untill the HSE be ready
    while(!(RCC->CR & RCC_CR_HSERDY));

//2° step config the flash mem

    FLASH->ACR |= FLASH_ACR_PRFTBE;

    FLASH->ACR &= ~(FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t) 0x2;

//3° comfigure the pll

    //reset some values of the register to make easy the configuration
    RCC->CFGR &= ~(RCC_CFGR_PLLSRC|RCC_CFGR_PLLMULL|RCC_CFGR_PLLXTPRE);

    //divide the HSE by 1
    RCC->CFGR &= ~(RCC_CFGR_PLLXTPRE);//if set the HSE would be div by 2

    //Soucer of the PLL - HSE
    RCC->CFGR |= RCC_CFGR_PLLSRC;// if reset source = HSI

    //PLL multiplier
    RCC->CFGR |= RCC_CFGR_PLLMULL9;

    //AHB Prescaler 1
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

    //APB1 Prescaler 2 the max speed of this bus is 36 Mhz
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

    //APB2 Prescaler 1
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;

    //Turn on the pll
    RCC->CR |= RCC_CR_PLLON;

    //WAIT UNTILL THE PLL BE READY
    while(!(RCC->CR & RCC_CR_PLLRDY));

    //Set the pll as the clock system
    RCC->CFGR &= ~(RCC_CFGR_SW);//reste just in case
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    //Wait untill the selection be done
    while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));
}


#endif