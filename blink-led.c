/*
 * File:   blink-led.c
 * Author: edno
 *
 * Created on 11 de Fevereiro de 2016, 13:39
 */


#include <xc.h>
#include <p18f2550.h>

#pragma config FOSC = INTOSCIO_EC
#pragma config FCMEN = OFF
#pragma config BORV = 3
#pragma config WDT = OFF
#pragma config CPB = OFF
#pragma config CPD = OFF

#define SET_BIT(reg,index)(reg |= (1 << index))
#define CLR_BIT(reg,index)(reg &= ~(1 << index))

#define LED LATB5

void delayzz()
{
    int i,j;
    for(i = 0; i < 5000; i++){
        for(j = 0; j < 2; j++){}
    }
}



void main(void) {
    // define RB0 como saida
    TRISB = CLR_BIT(TRISB,5);

    // loop infinito
    while(1) {
        LED = 1;
        delayzz();
        LED = 0;
        delayzz();
    }

    return;
}