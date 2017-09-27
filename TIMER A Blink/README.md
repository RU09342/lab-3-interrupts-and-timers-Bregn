#Timer A Blink
By Bryan Regn
Created 9/20
Last Updated 9/26

For the most part this code was the exact same from processor to processor. The same changes that were needed before are needed again, like the differences in the PxSEL between processors.
One other difference that changed the code was the for the MSP430FR2311 there was no Timer A, so Timer B was used instead. 
Similar to part one you need to enable all maskable interupts in order to be able to use an interupt for the timer. This is indicated by the line of code: __bis_SR_register(GIE); 
Also since I want an interupt to occur when the timer reaches a certain value I needed to anable the Capture Control Register so I can compare the timer to that register to see if it reached its goal yet. This is indicated by: TA0CCTL0 = CCIE;
To set the value of the register we are comparing I used: TA0CCR0 = 60000; 
Lastly I needed to clear the timer, set how I was going to count, and choose the clock being used. This is compacted into the following line of code: TA0CTL = TASSEL_2 + MC_1 + TACLR;
