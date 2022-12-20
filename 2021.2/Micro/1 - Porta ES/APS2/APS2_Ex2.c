#include <msp430.h> 
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
	/*-----------------CONFIGURACAO DA PORTA 1----------------------------------------------------
	 *
	 * P1.0 - N.C
	 * P1.1 - Entrada com resistor
	 * P1.2 - Entrada com resistor
	 * P1.3 - Entrada com resistor
	 * P1.4 - Entrada com resistor
	 * P1.5 - N.C
	 * P1.6 - N.C
	 * P1.7 - N.C
	 *
	 * >>> P1DIR (Saída 1, Entrada 0)
	 *                  bit     7  6  5  4    3  2  1  0
	 *           valor ini.     0  0  0  0    0  0  0  0
	 *           valor def.     1  1  1  0    0  0  0  1
	 *           -----------------------------------------
	 *           P1DIR = 0xE1;
	 *
	 *
	 * >>> P1REN (Resistor das chaves de entradas)
     *                  bit     7  6  5  4    3  2  1  0
     *           valor ini.     0  0  0  0    0  0  0  0
     *           valor def.     0  0  0  1    1  1  1  0
     *           -----------------------------------------
     *           P1REN = 0x1E;
	 *
	 *
	 * >>> P1OUT (As entradas são configuradas como resistores pull-up(1) ou pull-down(0) e as saídas em nível baixo)
     *                  bit     7  6  5  4    3  2  1  0
     *           valor ini.     0  0  0  0    0  0  0  0
     *           valor def.     0  0  0  1    1  1  1  0
     *           -----------------------------------------
     *           P1OUT = 0x1E;
	 */


    /*--------------------------------CONFIGURACAO DA PORTA 2----------------------------------*/
    /*
	 * P2.0 - Saida em baixo nivel (Led apagado) Vazio
	 * P2.1 - Saida em baixo nivel (Led apagado) 1/4
	 * P2.2 - Saida em baixo nivel (Led apagado) 1/2
	 * P2.3 - N.C
	 * P2.4 - N.C
	 * P2.5 - N.C
	 * P2.6 - Saida em baixo nivel (Led apagado) 3/4
	 * P2.7 - Saida em baixo nivel (Led apagado) Cheio
	 *
	 * >>> P2DIR (Saída 1, Entrada 0)
	 *                  bit     7  6  5  4    3  2  1  0
	 *           valor ini.     0  0  0  0    0  0  0  0
	 *           valor def.     1  1  1  1    1  1  1  1
	 *           -----------------------------------------
	 *           P2DIR = 0xFF;
     * 
     * P1OUT = 0x00; // LED's apagados e os demais pinos em nivel baixo
	 *
    */
   P1DIR = BIT7+BIT6+BIT5+BIT0;
   P1REN = BIT4+BIT3+BIT2+BIT1;
   P1OUT = BIT4+BIT3+BIT2+BIT1;

   P2DIR = 1; //Todos os pinos são saídas
   P2OUT = 0; //Todas as saídas em nível baixo

   do{
        if(P1OUT=0 || P1OUT=BIT1) //0000 0000 ou 0000 0010
        {
            P2OUT = BIT0; //Ascende o LED de Vazio
        }
        else if(P1OUT=BIT2||P1OUT=BIT2+BIT1||P1OUT=BIT3) //0000 0100 ou 0000 0110 ou 0000 1000
        {
            P2OUT = BIT1; //Ascende o LED de 1/4
        }
        else if(P1OUT=BIT3+BIT1||P1OUT=BIT3+BIT2||P1OUT=BIT3+BIT2+BIT1||P1OUT=BIT4||P1OUT=BIT4+BIT1) //0000 1010 ou 0000 1100 ou 0000 1110 ou 0001 0000 ou 0001 0010
        {
            P2OUT = BIT2; //Ascende o LED de 1/2
        }
        else if(P1OUT=BIT4+BIT2||P1OUT=BIT4+BIT2+BIT1||P1OUT=BIT4+BIT3) //0001 0100 ou 0001 0110 ou 0001 1000
        {
            P2OUT = BIT6; //Ascende o LED de 3/4
        }
        else //0001 1010 ou 0001 1100 ou 0001 1110
        {
            P2OUT = BIT7; //Ascende o LED de Cheio
        }
    }while(1); 
}
