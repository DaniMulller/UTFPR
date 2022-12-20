/*
 * SM26EL - Exemplo 1 - Timer A - Led VM piscando
 * a cada 1s
 *
 */
#include <msp430.h> 


void config_ini(void);
void ini_P1_P2(void);
void ini_Timer0(void);

unsigned char count = 0;

void main(void)
{
    config_ini();
    ini_P1_P2();
    ini_Timer0();

	do{
	   // Loop infinito
	}while(1);
}
//---------------------------------------------------------------

// RTI do Modulo 0 do Timer0
#pragma  vector=TIMER0_A0_VECTOR
__interrupt void RTI_do_M0_Timer0(void){

    // Alternar o estado do LED VM
    P1OUT ^= BIT0;

    if(count >= 60){
        P1OUT ^= BIT6;
        count = 0;
    }else{
        count++;
    }


}


void ini_Timer0(void){
    /* Inicializacao do Timer 0 para interrupcoes temporizadas
     * de 1s.
     *
     * CONTADOR:
     *      - Clock: ACLK
     *           -> Fdiv: 1
     *      - Modo contagem: UP (crescente)
     *      - Int. do contador: desabilitada
     *
     * MODULO 0:
     *      - Funcao: comparacao (nativa)
     *      - Int.: Habilitada
     *      - Valor de comparacao:
     *           -> TA0CCR0: (1*32768)/1 - 1 = 32767
     *
     */
    TA0CTL = TASSEL0 + MC0;
    TA0CCTL0 = CCIE;
    TA0CCR0 = 32767;
}


void ini_P1_P2(void){
    /* PORTA 1
     *   P1.0 - LED VM - Saida digital em nivel baixo
     *   P1.6 - LED VD - Saida digital em nivel baixo
     *   P1.x - N.C. - Saidas em nivel baixo.
     */
    P1DIR = 0xFF;
    P1OUT = 0;

    /* PORTA 2
     *   P2.0-P2.5 - N.C. - Saidas em nivel baixo.
     *   Pinos 18 e 19 - Funcoes XIN/XOUT devem ser mantidas
     *                   pois o XT1 sera utilizado no
     *                   oscilador LFXT1.
     */
    P2DIR = 0xFF;
    P2OUT = 0;
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












