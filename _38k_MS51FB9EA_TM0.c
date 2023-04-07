#include "MS51_16K.H"
#include "timer.H"

void _Timer0_ISR(void) __interrupt 1 {
    TF0 = 0; // clear Timer 0 interrupt flag
    P14 = !P14; // toggle output pin
}

void main(void) {
    ALL_GPIO_QUASI_MODE;
    TMOD = 0x02; // set Timer 0 to 8-bit auto-reload mode
    TH0 = 239; // calculate TH0 value for 38kHz frequency (assuming 16MHz clock)
    TL0 = TH0; // set TL0 to match TH0 for auto-reload mode
    TR0 = 1; // start Timer 0
    ET0 = 1; // enable Timer 0 interrupt
    EA = 1; // enable global interrupts

    while (1) {
       P12=!P12;
       Timer1_Delay10ms(100);
    }
}
