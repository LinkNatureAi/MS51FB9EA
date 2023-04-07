#include "MS51_16K.H"
#include "timer.H"
#include "stdio.H"
#include "string.H"

int putchar (int c)
{
	while (!TI);
	TI = 0;
	SBUF = c;
	return c; 
}

void main(void) {
    ALL_GPIO_QUASI_MODE;
    MODIFY_HIRC(HIRC_24);
    UART_Open(24000000, UART0_Timer3, 115200);
    ENABLE_UART0_PRINTF;
    TI = 1;

    while (1) {
        P14 = !P14;
       printf_small("\n Hello world! , led status:%d",(P14));
       // puts("how are you");
        Timer1_Delay10ms(100);
    }
}
