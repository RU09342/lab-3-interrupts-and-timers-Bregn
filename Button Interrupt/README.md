# Button Interrupt
By Bryan Regn
Created: 9/20/17
Last Updated: 9/24

## Dependancies 
Similar to all labs this code depends on the use of the MSP430.h 

## Reference guides used
Guides and code used to get started and understand interupts:
http://processors.wiki.ti.com/index.php/MSP430_LaunchPad_PushButton 
http://www.simplyembedded.org/tutorials/msp430-interrupts/

## Functionality and differences 
PxIE is used as interupt enable, we wanted the button to trigger the interupt so that was the pin used to enabl eit.
PxIFG is used to clear the the interupt flag register. Very important so the interupt can end and return to code.
 __bis_SR_register(GIE) is used to enable all maskable interupts, required to use any interupts besides NMI.
Code was generally the same from device to device. Only differences that were needed was a change of port for the button if that applied to the board, also for the MSP430FR family of processors the following line of code was required to turn off the default high impedance mode on GPIO: PM5CTL0 &= ~LOCKLPM5;