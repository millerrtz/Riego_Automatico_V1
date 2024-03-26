/*
 * usartTX.h
 *
 * Created: 1/03/2023 10:42:34 p. m.
 *  Author: MillerOrtiz
 */ 


#ifndef USARTTX_H_
#define USARTTX_H_

void configUSART();
void usartTX(unsigned char caracter);
void usart_TX_txt(char* cadena);
unsigned char usartRX();

#endif /* USARTTX_H_ */