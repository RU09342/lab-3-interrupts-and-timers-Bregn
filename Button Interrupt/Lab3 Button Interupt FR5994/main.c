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

    PM5CTL0 &= ~LOCKLPM5;

    P1SEL0 = 0x00; // sets pin 1 to GPIO
    P1SEL1 = 0x00; // sets pin 1 to GPIO
    P5SEL0 = 0x00; // sets pin 5 to GPIO
    P5SEL1 = 0x00; // sets pin 5 to GPIO

    P1DIR = BIT0; //sets LED at P1.0 to output
    P5REN = BIT6; //Resistor enabled for button P5.6
    P5OUT = BIT6; //Sets resistor to pull up for button

    P5IE |= BIT6; //interupt enable for button P5.6
    P5IFG &= ~BIT6; //Clears interupt flag register

    __bis_SR_register(GIE); //global interupt enable (enables all maskable interupts)

    for(;;){}
    return 0;
}

#pragma vector=PORT5_VECTOR
__interrupt void Port_5(void){
    unsigned int i=0;
    for(i=0; i<20000; i++);{ //used for delay to see led blink
        if(i%10000==0){
            P1OUT ^= BIT0; //toggles LED when interupt triggered
            P5IFG &= ~BIT6; //Clears interupt flag register needed otherwise will be stuck in infinite loop
        }
    }
}
