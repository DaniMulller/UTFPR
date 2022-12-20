/* SM26EL - Sintese de sinal Senoidal via PWM
 *
 *   fsen = 30 Hz
 *   fpwm = 1920 Hz
 *
 *   Timer: 1
 *       - Clock: 2 MHz
 *
 *   Saida PWM: Mod. 1 do Timer 1 via pino 9
 *
 *
 */


#include <msp430.h> 
#include <math.h>

void config_ini(void);
void ini_P1_P2(void);
void ini_Timer1_PWM(void);

// 1ª OPCAO: valores do vetor armazenados na RAM
unsigned int vetor_pwm[64];

/* 2ª OPCAO: valores do vetor armazenados na Flash
      const unsigned int vetor_pwm[64]= { ... valores MatLab };
       -> Nao precisa do for na main.
*/
unsigned char n = 0;


void main(void)
{

    config_ini();
    ini_P1_P2();
    ini_Timer1_PWM();

    // Calcular o vetor_pwm

    for(n=0;n<64;n++){
        vetor_pwm[n] = 521.0*( sin(0.09817477*n) + 1.0  );
    }
    n = 0;
    TA1CTL |= MC0; // Agora que o vetor esta calculado, roda o timer

    do{

    }while(1);

}
// ------------------------------------------------------------------------------

//RTI do Modulo 1 do Timer1
#pragma vector=TIMER1_A1_VECTOR
__interrupt void RTI_M1_Timer1(void){

/* 1ª OPCAO: tratamento para 1 int. hab. apenas */

    (void)TA1IV;

    TA1CCR1 = vetor_pwm[n];

    if(n >= 63){
        n = 0;
    }else{
        n++;
    }



 /* 2ª OPCAO: tratamento de 2 ou mais int. do timer
    switch(TA1IV){
       case 2: // Foi o Modulo 1 quem provovou a int.
            TA1CCR1 = vetor_pwm[n];

            if(n >= 63){
                n = 0;
            }else{
                n++;
            }
       break;
       case 4: // Foi o Modulo 2 quem provovou a int.

       break;
       case 10: // Foi o CONTADOR quem provovou a int.

       break;
    }
*/

}



void ini_Timer1_PWM(void){
    /* Objetivo: gerar PWM
     *
     * CONTADOR:
     *      Clock: SMCLK ~ 2MHz
     *           -  Fdiv: 1
     *      Modo: UP (inicialmente parado)
     *
     *
     * MODULO 0: - Responsavel pelo periodo/freq. do PWM
     *      Funcao: comparacao (nativa)
     *      Int.: desab.
     *      TA1CCR0 = 1041;
     *
     * MODULO 1:
     *      Funcao: comparacao (nativa)
     *      Int.: Habilitar!
     *      Modo de saida: 7 (reset/set)
     *
     */
    TA1CTL = TASSEL1;
    TA1CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT + CCIE;
    TA1CCR0 = 1041;
    TA1CCR1 = 521;
}

void ini_P1_P2(void){
    /* Porta 1:
     *     P1.x: N.C. - Todos como saida em nivel baixo
     *
     */
    P1DIR = 0xFF;
    P1OUT = 0;

    /* Porta 2:
     *
     *     P2.1 - Saida PWM - Mudar funcao para TA1.1
     *     P2.X - N.C. - Saidas em nivel baixo
     *     Pinos 18 e 19: Usados pelo LFXT1 de 32k
     *
     */
    P2DIR = 0xFF;
    P2OUT = 0;
    P2SEL |= BIT1; // Pino 9 passa para TA1.1

}


void config_ini(void){

    WDTCTL = WDTPW | WDTHOLD;   // Para o contador do watchdog timer

    // Configuracoes do BCS
    // MCLK = DCOCLK ~ 16 MHz
    // ACLK = LFXT1CLK = 32768 Hz
    // SMCLK = DCOCLK / 8 ~ 2 MHz

    DCOCTL = CALDCO_16MHZ;    // Freq. Calibrada de 16 MHz
    BCSCTL1 = CALBC1_16MHZ;
    BCSCTL2 = DIVS0 + DIVS1;  // Fator divisao = 8 para SMCLK
    BCSCTL3 = XCAP0 + XCAP1;  // Capacitor do cristal ~12.5 pF

    while(BCSCTL3 & LFXT1OF);

    __enable_interrupt();  // seta o bit GIE - permite geracao de interrupcoes
}






