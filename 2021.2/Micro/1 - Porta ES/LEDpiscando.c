/*
 * EXEMPLO 1: Portas E/S
 *
 * O codigo faz o LED1 conectado em P1.0 piscar
 *
 * 12/11/2013
 *
 */
#include <msp430.h> 

void main(void) {
	unsigned long int i = 0;

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    // LED1 conectado em P1.0 (pino 2 do uCon)
    // Os demais pinos nao utilizados sao configurados como saida em nivel baixo
    P1DIR = BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7; // ou de forma equivalente P1DIR = 0xFF;
    P1OUT = 0x00; // LED1 apagado e os demais pinos em nivel baixo

    // Porta 2 nao utilizada. Entao, todos os pinos como saida em nivel baixo
    P2DIR = BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7; // ou de forma equivalente P2DIR = 0xFF;
    P2OUT = 0x00; // TODOS os pinos em nivel baixo

    P2SEL &= ~(BIT6 + BIT7); // Configura pinos 18 e 19 como E/S, conectando a P2.6 e P2.7
	
    do{
       	P1OUT ^= BIT0; // inverte estado do LED1
    	for(i = 0; i < 100000; i++);  // for executado em determinado intervalo de tempo (~ 1s)

/*    	P1OUT |= BIT0; // acende LED1
    	for(i = 0; i < 100000; i++);  // for executado em determinado intervalo de tempo (~ 1s)

    	P1OUT &= ~BIT0; // apaga LED1
    	for(i = 0; i < 100000; i++);  // for executado em determinado intervalo de tempo (~ 1s)

*/
    }while(1);
}