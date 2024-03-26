/*
 * Riego.c
 *
 * Created: 2/03/2023 8:06:23 p. m.
 *  Author: mille
 */ 
#include <avr/io.h>

void sensar(int *valor)
{
	if (valor > 150)
	{
		PORTC |= (1 << PINC1);
		PORTC &=~(1 << PINC2);
	}
	else
	{
		PORTC &=~(1 << PINC1);
		PORTC |= (1 << PINC2);
	}
}