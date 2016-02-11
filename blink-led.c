/*
 * File:   blink-led.c
 * Author: edno
 *
 * Created on 11 de Fevereiro de 2016, 13:39
 */

#include <xc.h>
#include "configuration.h"

#define _XTAL_FREQ 20e+6

#define SET_BIT(reg,index)(reg |= (1 << index))
#define CLR_BIT(reg,index)(reg &= ~(1 << index))

#define LED LATB5

void delay()
{
    int i;
    for(i = 0; i < 50; i++){
        __delay_ms(10);
    }
}

void main(void) {
    // define RB0 como saida
    TRISB = CLR_BIT(TRISB,5);
    
    // loop infinito
    while(1) {
        LED = 1;
        delay();
        LED = 0;
        delay();
    }
    
    return;
}