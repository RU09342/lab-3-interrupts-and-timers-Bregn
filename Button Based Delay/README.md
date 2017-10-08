#Button Based Delay
By Bryan Regn
Last updated 10/1/2017

## Dependancies 
Similar to all labs MSP430.h is required. 

## Differences between boards and functionality 

Interupt enable had to be set for the button and initially set to trigger on falling edge to catch the first button press.
CCR0 is used in the up counting mode. The value that the register compares itself was set on the line after that at a rate that made the led blink at 10Hz.
The timer was set up using SMCLK, dividing that by 8, setting it to count in up mode, and it clears Timer A's Register. 
### Interupts 
In the timer interupt vector the led is toggeled. 
The button interupt evaluates if the button is pressed or not. If the button is pressed it sets the interupt edge select to trigger on the rising edge or button release. The timer is also cleared because the button was just pressed. Lastly it clears the interupt flag.
If the button was not pressed it changes the interupt edge select to trigger. The value of the CCR0 is changed to the value of the timer, and lastly it clears the interupt flag. 

Only differences between the board's code was that for the F2311 Timer B was used instead of Timer A, also for the MSP430FR family of processors the following line of code was required to turn off the default high impedance mode on GPIO: PM5CTL0 &= ~LOCKLPM5;