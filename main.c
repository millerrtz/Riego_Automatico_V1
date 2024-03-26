/*
 * Riego_Automatico_CodeV1.c
 *
 * Created: 28/02/2023 11:36:34 p. m.
 * Author : MillerOrtiz
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"
#include "usartTX.h"


int main(void)
{
	unsigned int valor;
	unsigned char txstring[30];
	unsigned char BT;
	
	DDRC = 0x06;
	DDRD = 0x02;
	
	configADC();
	configUSART();
	
    while (1) 
    {
		startADC();
		while (!isADCFinish());
		
		valor = ADCdata();
		
		sprintf(txstring, "ADC: %d \r\n", valor);
		usart_TX_txt(txstring);
		
		sensar(valor);
		
		_delay_ms(2000);
		
		BT = usartRX();
		
		if (BT == 'r')
		{
			PORTC |= (1 << PINC1);
			PORTC &=~(1 << PINC2);
			
			_delay_ms(1500);
			
			PORTC &=~(1 << PINC1);
			PORTC |= (1 << PINC2);
		}
		
    }
}

