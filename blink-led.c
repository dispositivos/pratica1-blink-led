/*
 * File:   blink-led.c
 * Author: edno
 *
 * Código inicial para aprendizado sobre a programação do PIC.
 * Aqui utilizo diversas técnicas de acionamento de porta digital, a saber:
 *  - Variável LATB5
 *  - Estrutura LATBbits
 *  - Uso de máscaras com a variável LATB
 *  - Uso de ponteiro para a região de memória do registrador LATB
 */

#include <xc.h>
#include <p18f2550.h>
#include "configuration.h"

#define _XTAL_FREQ 20e+6

#define SET_BIT(reg,index)(reg |= (1 << index))
#define CLR_BIT(reg,index)(reg &= ~(1 << index))

#define PORTMSK

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

#ifdef PTRMSK
    unsigned char *latb = 0xF8A;
#endif
    
    // loop infinito
    while(1) {
#ifdef LATMODE
        LATB5 = 1;
        delay();
        LATB5 = 0;
        delay();
#endif
#ifdef PORTBITS
        LATBbits.LATB5 = 1;
        delay();
        LATBbits.LATB5 = 0;
        delay();
#endif
#ifdef PORTMSK
        SET_BIT(LATB,5);
        delay();
        CLR_BIT(LATB,5);
        delay();
#endif
#ifdef PTRMSK
        SET_BIT(*latb,5);
        delay();
        CLR_BIT(*latb,5);
        delay();
#endif
    }
    
    return;
}