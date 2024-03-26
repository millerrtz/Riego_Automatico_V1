/*
 * usartTX.c
 *
 * Created: 1/03/2023 10:42:20 p. m.
 *  Author: MillerOrtiz
 */ 
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define FOSC 16000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1


void configUSART()
{
	// Transmision: ON
	// Recepcion: ON
	// Modo: asincrono
	// Baudios: 9600
	// Parametros: 8 bits, 1 stop, sin paridad
	
	UCSR0A = 0x00;	
	UCSR0B = 0X18;
	UCSR0C = 0x06;
	UBRR0 = MYUBRR;
}

void usartTX(unsigned char caracter)
{
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = caracter;
}

void usart_TX_txt(char* cadena)
{
	while (*cadena != 0x00)
	{
		usartTX(*cadena);
		cadena++;
	}
}

unsigned char usartRX()
{
	if(UCSR0A & (1 << RXC0))
		return UDR0;
	else
		return 0;
}