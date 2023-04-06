#include "MS51_16K.H"
#include "timer.H"

void _Timer1_ISR(void) __interrupt 3 {
    P14 = !P14; 
}

void main(void) {
    ALL_GPIO_QUASI_MODE;
    TMOD = 0x20; // set Timer 1 to mode 2
    TH1 = 239; // calculate TH1 value for 38kHz frequency
    TL1 = 0; // set TL1 to 0 for auto-reload mode
    TR1 = 1; // start Timer 1
    ET1 = 1; // enable Timer 1 interrupt
    EA = 1; // enable global interrupts

    while (1) {
      Timer0_Delay1ms(1000); 
      P12=!P12;
    }
}
