#include <msp430.h> 

/* MAPEAMENTO  CONSTANTE -> DIGITO DISPLAY
 *
 *
 * 	Segmentos	pt   g   f   e   d   c   b   a
 *  Bit P2       7   6   5   4   3   2   1   0
 *  ---------
 *   DIGITO
 * 		0		 0   0   1   1   1   1   1   1  =  BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5
 * 		1        0   0   0   0   0   1   1   0  =  BIT1 + BIT2
 * 		2        0   1   0   1   1   0   1   1  =  BIT0 + BIT1 + BIT3 + BIT4 + BIT6
 * 		3		 0   1   0   0   1   1   1   1  =  BIT0 + BIT1 + BIT2 + BIT3 + BIT6
 * 		4		 0   1   1   0   0   1   1   0  =  BIT1 + BIT2 + BIT5 + BIT6
 * 		5		 0   1   1   0   1   1   0   1  =  BIT0 + BIT2 + BIT3 + BIT5 + BIT6
 * 		6		 0   1   1   1   1   1   0   1  =  BIT0 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6
 * 		7		 0   0   0   0   0   1   1   1  =  BIT0 + BIT1 + BIT2
 *
 */

#define		ZERO	(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5)
#define		UM		(BIT1 + BIT2)
#define		DOIS	(BIT0 + BIT1 + BIT3 + BIT4 + BIT6)
#define		TRES	(BIT0 + BIT1 + BIT2 + BIT3 + BIT6)
#define		QUATRO	(BIT1 + BIT2 + BIT5 + BIT6)
#define		CINCO	(BIT0 + BIT2 + BIT3 + BIT5 + BIT6)
#define		SEIS	(BIT0 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6)
#define		SETE	(BIT0 + BIT1 + BIT2)

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    P1DIR = BIT3 + BIT4 + BIT5 + BIT6 + BIT7; // P1.0-P1.2 como entrada, os demais como saida digital
    P1REN = BIT0 + BIT1 + BIT2;  // Habilita resistores de P1.0, P1.1, P1.2
    P1OUT = BIT0 + BIT1 + BIT2;  // Seleciona funcao dos resitores de P1.0, P1.1, P1.2
    							 // Demais bits de P1OUT definem as saidas em nivel logico baixo

    P2DIR = BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7;  // Todos os bits da P2 como saida
    P2OUT = 0;  // Leds apagados

    P2SEL &= ~(BIT6 + BIT7);  // P2.6 e P2.7 como saida digital conectados nos pinos 18 e 19 do uCon

	do{
		/* P1IN
		 *
		 * bit		7 6 5 4 3 2  1  0
		 * P1IN		X X X X X E  E  E
		 * 			0 0 0 0 0 1  1  1  AND
		 * 		  --------------------
		 * 		    0 0 0 0 0 E  E  E
		 */
		 switch( ( P1IN & (BIT0 + BIT1 + BIT2))  ){

		 	 case 0:
		 		 P2OUT = ZERO;
		 	 break;
		 	 case 1:
		 		 P2OUT = UM;
		 	 break;
		 	 case 2:
		 		 P2OUT = DOIS;
		 	 break;
		 	 case 3:
		 		 P2OUT = TRES;
		 	 break;
		 	 case 4:
		 		 P2OUT = QUATRO;
		 	 break;
		 	 case 5:
		 		 P2OUT = CINCO;
		 	 break;
		 	 case 6:
		 		 P2OUT = SEIS;
		 	 break;
		 	 case 7:
		 		 P2OUT = SETE;
		 	 break;

		 	 default:
		 		P2OUT = BIT7;
		     break;
		 }
	}while(1);
}