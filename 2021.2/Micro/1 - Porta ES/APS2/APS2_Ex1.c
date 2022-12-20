#include <msp430.h> 
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	/*-----------------CONFIGURACAO DA PORTA 1----------------------------------------------------
	 *
	 * P1.0 - Entrada S1 com interrupcao
	 * P1.1 - Entrada S2 sem interrupcao
	 * P1.2 - Entrada S3 com interrupcao
	 * P1.3 - Saida em baixo nivel (Led apagado)
	 * P1.4 - N.C
	 * P1.5 - Saida em baixo nivel (Led apagado)
	 * P1.6 - N.C
	 * P1.7 - Saida em baixo nivel (Led apagado)
	 *
	 * >>> P1DIR (Saída 1, Entrada 0)
	 *                  bit     7  6  5  4    3  2  1  0
	 *           valor ini.     0  0  0  0    0  0  0  0
	 *           valor def.     1  1  1  1    1  0  0  0
	 *           -----------------------------------------
	 *           P1DIR = 0xF8;
	 *
	 *
	 * >>> P1REN (Resistor das chaves de entradas)
     *                  bit     7  6  5  4    3  2  1  0
     *           valor ini.     0  0  0  0    0  0  0  0
     *           valor def.     0  0  0  0    0  1  1  1
     *           -----------------------------------------
     *           P1REN = 0x07;
	 *
	 *
	 * >>> P1OUT (As entradas são configuradas como resistores pull-up(1) ou pull-down(0))
     *                  bit     7  6  5  4    3  2  1  0
     *           valor ini.     0  0  0  0    0  0  0  0
     *           valor def.     0  0  0  0    0  1  1  1
     *           -----------------------------------------
     *           P1OUT = 0x07;
     *
	 * ---------------------------------------------------------------------------------------
     * ---------------------Ativando Interrupcao para S1 e S3---------------------------------
     * ---------------------------------------------------------------------------------------
	 * >>> P1IES
     *                  bit     7  6  5  4    3  2  1  0
     *           valor ini.     0  0  0  0    0  0  0  0
     *           valor def.     0  0  0  0    0  1  0  1
     *           -----------------------------------------
     *           P1IES = 0x05;
     *
     *
     * >>> P1IFG (Limpar o historico de Flags)
     *                  bit     7  6  5  4    3  2  1  0
     *           valor ini.     X  X  X  X    X  X  X  X
     *           valor def.     0  0  0  0    0  0  0  0
     *           -----------------------------------------
     *           P1IFG = 0;
     *
     *
     * >>> P1IE
     *                  bit     7  6  5  4    3  2  1  0
     *           valor ini.     0  0  0  0    0  0  0  0
     *           valor def.     0  0  0  0    0  1  0  1
     *           -----------------------------------------
     *           P1IE = 0x05;
	 *
	 */


    /*--------------------------------CONFIGURACAO DA PORTA 2----------------------------------*/
    /*
	 * P2.0 - Entrada S4 com interrupcao
	 * P2.1 - Saida em baixo nivel (Led apagado)
	 * P2.2 - Entrada S5 sem interrupcao
	 * P2.3 - Saida em baixo nivel (Led apagado)
	 * P2.4 - N.C
	 * P2.5 - Entrada S6 com interrupcao
	 * P2.6 - Saida em baixo nivel (Led apagado)
	 * P2.7 - N.C
	 *
	 * >>> P2DIR (Saída 1, Entrada 0)
	 *                  bit     7  6  5  4    3  2  1  0
	 *           valor ini.     0  0  0  0    0  0  0  0
	 *           valor def.     0  1  0  0    1  0  1  0
	 *           -----------------------------------------
	 *           P2DIR = 0x4A;
	 *
	 *
	 * >>> P2REN (Resistor das chaves de entradas)
     *                  bit     7  6  5  4    3  2  1  0
     *           valor ini.     0  0  0  0    0  0  0  0
     *           valor def.     0  0  1  0    0  1  0  1
     *           -----------------------------------------
     *           P2REN = 0x25;
	 *
	 *
	 * >>> P2OUT (As entradas são configuradas como resistores pull-up(1) ou pull-down(0))
     *                  bit     7  6  5  4    3  2  1  0
     *           valor ini.     0  0  0  0    0  0  0  0
     *           valor def.     0  0  1  0    0  1  0  1
     *           -----------------------------------------
     *           P2OUT = 0x25;
     * 
     * ---------------------------------------------------------------------------------------
     * ---------------------Ativando Interrupcao para S4 e S6---------------------------------
     * ---------------------------------------------------------------------------------------
	 * >>> P2IES
     *                  bit     7  6  5  4    3  2  1  0
     *           valor ini.     0  0  0  0    0  0  0  0
     *           valor def.     0  0  1  0    0  0  0  1
     *           -----------------------------------------
     *           P2IES = 0x21;
     *
     *
     * >>> P2IFG (Limpar o historico de Flags)
     *                  bit     7  6  5  4    3  2  1  0
     *           valor ini.     X  X  X  X    X  X  X  X
     *           valor def.     0  0  0  0    0  0  0  0
     *           -----------------------------------------
     *           P2IFG = 0;
     *
     *
     * >>> P2IE
     *                  bit     7  6  5  4    3  2  1  0
     *           valor ini.     0  0  0  0    0  0  0  0
     *           valor def.     0  0  1  0    0  0  0  1
     *           -----------------------------------------
     *           P2IE = 0x21; 
    */

   /*---------------------------Invertendo as funcao digital dos pinos 11-18-19------------------
   * PINO 11
   * P3SEL.1 = 0;
   * P3SEL2.1 = 1;
   *
   * PINO 18
   * 
   */

    /*------------------------Ascender os LEDs P1.3, P2.1, P2.6, P1.7----------------------------
    *   P1OUT |= (BIT3 + BIT7);
    *   P2OUT |= (BIT1 + BIT6);
    */
   
}
