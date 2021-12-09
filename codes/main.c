#include "stm32f1xx.h"
#include "ClockConfig.h"
#include "Displa7seg.h"
#include "delay.h"

void GpioConfig();

int ms=0;

//
char displaysChars[4] = "    ";

//text that will apear in the display 
char greetings[] = "     hello    ";

int main(){

    int i=0;

    ClockConfig_Init();
    displayInit();
    GpioConfig();
    
    while(1){

        writeCharDisplay7Seg(displaysChars[0]); 
        GPIOA->ODR &= ~(GPIO_ODR_ODR9);//turn on the display
        GPIOA->ODR |= (GPIO_ODR_ODR6);//turn off the previus display
        delayMs(2);

        writeCharDisplay7Seg(displaysChars[1]); 
        GPIOA->ODR &= ~(GPIO_ODR_ODR8);
        GPIOA->ODR |= (GPIO_ODR_ODR9);
        delayMs(2);
       
        writeCharDisplay7Seg(displaysChars[2]); 
        GPIOA->ODR &= ~(GPIO_ODR_ODR7);
        GPIOA->ODR |= (GPIO_ODR_ODR8);
        delayMs(2);

        writeCharDisplay7Seg(displaysChars[3]); 
        GPIOA->ODR &= ~(GPIO_ODR_ODR6);
        GPIOA->ODR |= (GPIO_ODR_ODR7);
        delayMs(2);
        i++;

        if(i==80){
            i=0;
            ms++;
    
            if(greetings[ms+3]=='\0') ms = 0;
    
            displaysChars[0] = greetings[ms];
            displaysChars[1] = greetings[ms+1];
            displaysChars[2] = greetings[ms+2];
            displaysChars[3] = greetings[ms+3];
        }


    }

    return 0;

}

void GpioConfig(){

    //these pins control which display is turn on
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |RCC_APB2ENR_IOPCEN;

    //pin A6 as open-drain 10Mhz
    GPIOA->CRL &= ~(GPIO_CRL_CNF6_1 | GPIO_CRL_MODE6_1);
    GPIOA->CRL |=  (GPIO_CRL_CNF6_0 | GPIO_CRL_MODE6_0);
    GPIOA->ODR |= (GPIO_ODR_ODR9);

    //pin A7 as open-drain 10Mhz
    GPIOA->CRL &= ~(GPIO_CRL_CNF7_1 | GPIO_CRL_MODE7_1);
    GPIOA->CRL |=  (GPIO_CRL_CNF7_0 | GPIO_CRL_MODE7_0);
    GPIOA->ODR |= (GPIO_ODR_ODR7);

    //pin A8 as open-drain 10Mhz
    GPIOA->CRH &= ~(GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1);
    GPIOA->CRH |=  (GPIO_CRH_CNF8_0 | GPIO_CRH_MODE8_0);
    GPIOA->ODR |= (GPIO_ODR_ODR8);

    //pin A9 as open-drain 10Mhz
    GPIOA->CRH &= ~(GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_1);
    GPIOA->CRH |=  (GPIO_CRH_CNF9_0 | GPIO_CRH_MODE9_0);
    GPIOA->ODR |= (GPIO_ODR_ODR9);

}

