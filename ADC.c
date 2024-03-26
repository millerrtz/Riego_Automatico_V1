/*
 * ADC.c
 *
 * Created: 1/03/2023 12:05:54 a. m.
 *  Author: MillerOrtiz
 */ 

#include <avr/io.h>

void configADC()
{
	ADMUX &= ~(1 << REFS1); // Voltaje interno 5V
	ADMUX |= (1 << REFS0);
	
	ADMUX |= (1 << ADLAR); // Desplazar resultado a la izquierda
	ADMUX &= ~(1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0); // ADC0
	
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1); // Prescaler 64
	ADCSRA |= (1 << ADEN); // Habilitar ADC
	
	ADCSRA |= (1 << ADATE);
}

void startADC()
{
	ADCSRA |= (1 << ADSC); // Inicia a convertir
}

int isADCFinish()
{
	return (ADCSRA & (1 << ADIF));
}

unsigned int ADCdata()
{
	unsigned int valor;
	
	ADCSRA |= (1 << ADIF);
	valor = ADCH;
	
	return valor;
}