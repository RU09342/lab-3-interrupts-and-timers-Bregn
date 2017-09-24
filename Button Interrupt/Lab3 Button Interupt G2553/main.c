#include <msp430.h> 
//By Bryan Regn
//Last Updated 9/24

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //needed to reset device

    P1SEL = 0x00; //sets P1 to GPIO
    P1SEL2 = 0x00; //sets P1 to GPIO

    P1DIR = BIT0; //sets LED at P1.0 to output
    P1REN = BIT3; //Resistor enabled for button P1.3
    P1OUT = BIT3; //Sets resistor to pull up for button

    P1IE |= BIT3; //interupt enable for button P1.3
    P1IFG &= ~BIT3; //Clears interupt flag register

    __bis_SR_register(GIE); //global interupt enable (enables all maskable interupts)

    for(;;){}
    return 0;
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void){
    unsigned int i=0;
    for(i=0; i<20000; i++);{ //used for delay to see led blink
        if(i%10000==0){
            P1OUT ^= BIT0; //toggles LED when interupt triggered
            P1IFG &= ~BIT3; //Clears interupt flag register needed otherwise will be stuck in infinite loop
        }
    }
}