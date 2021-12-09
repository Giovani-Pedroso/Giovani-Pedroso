#include "stm32f1xx.h"

#ifndef _DISPLAY7SEGS_H

#define _DISPLAY7SEGS_H

void displayInit(){

    //Activate the clock for the PortB
    RCC->APB2ENR |=  (RCC_APB2ENR_IOPBEN);

    //PB1 as slow output  
    GPIOB->CRL |=   (GPIO_CRL_MODE1_0);
    GPIOB->CRL &=  ~(GPIO_CRL_MODE1_1|GPIO_CRL_CNF1_0|GPIO_CRL_CNF1_1);

    //PB10 as slow output - green
    GPIOB->CRH |=  (GPIO_CRH_MODE10_0);
    GPIOB->CRH &= ~(GPIO_CRH_MODE10_1|GPIO_CRH_CNF10_0|GPIO_CRH_CNF10_1);

    //PB11 as slow output - green
    GPIOB->CRH |=  (GPIO_CRH_MODE11_0);
    GPIOB->CRH &= ~(GPIO_CRH_MODE11_1|GPIO_CRH_CNF11_0|GPIO_CRH_CNF11_1);

    //PB12 as slow output - blue
    GPIOB->CRH |=  (GPIO_CRH_MODE12_0);
    GPIOB->CRH &= ~(GPIO_CRH_MODE12_1|GPIO_CRH_CNF12_0|GPIO_CRH_CNF12_1);

    //PB13 as slow output - green
    GPIOB->CRH |=  (GPIO_CRH_MODE13_0);
    GPIOB->CRH &= ~(GPIO_CRH_MODE13_1|GPIO_CRH_CNF13_0|GPIO_CRH_CNF13_1);

    //PB14 as slow output - green
    GPIOB->CRH |=  (GPIO_CRH_MODE14_0);
    GPIOB->CRH &= ~(GPIO_CRH_MODE14_1|GPIO_CRH_CNF14_0|GPIO_CRH_CNF14_1);
    
    //PB15 as slow output - green
    GPIOB->CRH |=  (GPIO_CRH_MODE15_0);
    GPIOB->CRH &= ~(GPIO_CRH_MODE15_1|GPIO_CRH_CNF15_0|GPIO_CRH_CNF15_1);

}



void writeCharDisplay7Seg(unsigned char c){

    //This function are responsible for show the characters 
    //received into the display

    //do not expect perfection in the char 
    //after all it is still a seven segments display
    //so is necessary use a bit of imagination to understand 
    //the letters , some examples are K=Q, M=K, and the letter W was impossible
    //to show in the display
    
    //this diagram show which segments are connected with which port
    //       ----B13---
    //      |          |
    //      |          |
    //      B14        B12
    //      |          |
    //      |          |
    //       ----B15---
    //      |          |
    //      |          |
    //      B1         B11
    //      |          |
    //      |          |
    //       ----B10---
   
    // Converter the upper case char in lower case
    if(c >= 'A' && c <='Z') c += 'a' - 'A' ;

    //Check wich char was recived 
    switch (c){

        case '9':
            //turn on or turn off the segments of the display
            //to form the letter or number
            GPIOB->ODR |=  ( GPIO_ODR_ODR15); 
            GPIOB->ODR |=  ( GPIO_ODR_ODR14); 
            GPIOB->ODR &=  ~(GPIO_ODR_ODR1);
            GPIOB->ODR |=  ( GPIO_ODR_ODR10); 
            GPIOB->ODR |=  ( GPIO_ODR_ODR11); 
            GPIOB->ODR |=  ( GPIO_ODR_ODR12); 
            GPIOB->ODR |=  ( GPIO_ODR_ODR13); 
            break;
        
        case '8': 

            GPIOB->ODR  |=  (GPIO_ODR_ODR15); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR14); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR1); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR10); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR11); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR12); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR13); 
            break;

        case '7': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   |=  (GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case '6': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   |=  (GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case '5': 

            GPIOB->ODR  |=  (GPIO_ODR_ODR15); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR14); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR1); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR10); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR11); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR12); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR13); 
            break;

        case '4': 

            GPIOB->ODR  |=  (GPIO_ODR_ODR15); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR14); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR1); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR10); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR11); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR12); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR13); 
            break;

        case '3': 

            GPIOB->ODR  |=  (GPIO_ODR_ODR15); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR14); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR1); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR10); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR11); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR12); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR13); 
            break;

        case '2': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   |=  (GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   |=  (GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case '1': 

            GPIOB->ODR  &= ~(GPIO_ODR_ODR15); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR14); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR1); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR10); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR11); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR12); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR13); 
            break;

        case '0': 

            GPIOB->ODR  &= ~(GPIO_ODR_ODR15); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR14); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR1); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR10); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR11); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR12); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR13); 
            break;

        case 'a': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   |=  (GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case 'b': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   |=  (GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR13);
            break;

        case 'c': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   |=  (GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case 'd': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   |=  (GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   |=  (GPIO_ODR_ODR12);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR13);
            break;

        case 'e': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   |=  (GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case 'f': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case 'g': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   |=  (GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case 'h': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   |=  (GPIO_ODR_ODR12);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR13);
            break;

        case 'i': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR13);
            break;

        case 'j': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR15);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   |=  (GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   |=  (GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case 'k':

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   |=  (GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13); 
            break;

        case 'l': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   |=  (GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR13); 
            break;

        case 'm': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR13); 
            break;

        case 'n': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR13);
            break;

        case 'o': 

            GPIOB->ODR  &= ~(GPIO_ODR_ODR15); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR14); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR1); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR10); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR11); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR12); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR13);
            break;

        case 'p': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   |=  (GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case 'q': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   |=  (GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case 'r': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR13);
            break;

        case 's': 

            GPIOB->ODR  |=  (GPIO_ODR_ODR15); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR14); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR1); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR10); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR11); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR12); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR13);
            break;

        case 't': 

            GPIOB->ODR  |=  (GPIO_ODR_ODR15); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR14); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR1); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR10); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR11); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR12); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR13); 
            break;

        case 'u': 

            GPIOB->ODR  &= ~(GPIO_ODR_ODR15); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR14); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR1); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR10); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR11); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR12); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR13); 
            break;

        case 'v': 

            GPIOB->ODR  &= ~(GPIO_ODR_ODR15); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR14); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR1); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR10); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR11); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR12); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR13); 
            break;

        case 'x':

            GPIOB->ODR  |=  (GPIO_ODR_ODR15); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR14); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR1); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR10); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR11); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR12); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR13); 
            break;

        case 'y':

            GPIOB->ODR  |=  (GPIO_ODR_ODR15); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR14); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR1); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR10); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR11); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR12); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR13);
            break;

        case 'z': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR14);
            GPIOB->ODR   |=  (GPIO_ODR_ODR1);
            GPIOB->ODR   |=  (GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   |=  (GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case '_': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR15);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR14);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR1);
            GPIOB->ODR   |=  (GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR13);
            break;

        case '-': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR14);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR13);
            break;

        case '?': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR15);
            GPIOB->ODR   |=  (GPIO_ODR_ODR14);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   |=  (GPIO_ODR_ODR11);
            GPIOB->ODR   |=  (GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

        case ' ': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR15);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR14);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR1);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR13);
            break;

        default:

            GPIOB->ODR   |=  (GPIO_ODR_ODR15);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR14);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR1);
            GPIOB->ODR   |=  (GPIO_ODR_ODR10);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR11);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR12);
            GPIOB->ODR   |=  (GPIO_ODR_ODR13);
            break;

    }

}
#endif