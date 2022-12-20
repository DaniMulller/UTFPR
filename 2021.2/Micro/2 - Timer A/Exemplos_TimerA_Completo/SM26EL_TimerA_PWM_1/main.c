#include <msp430.h> 


void config_ini(void);
void ini_P1_P2(void);
void ini_Timer0_PWM(void);
void ini_Timer1_Debouncer(void);

void main(void)
{
    config_ini();
    ini_P1_P2();
    ini_Timer0_PWM();
    ini_Timer1_Debouncer();

    do{

    }while(1);

}

//------------------------------------------------------------------------------------

// RTI da PORTA 1
#pragma vector=PORT1_VECTOR
__interrupt void RTI_da_Porta_1(void){

    // Passo 1: desabilita int.
    P1IE &= ~BIT3;

    // Passo 2: inicia temporizador
    TA1CCR0 = 6000; // para t ~ 3 ms

}

// RTI do Modulo 0 do Timer 1
#pragma vector=TIMER1_A0_VECTOR
__interrupt void RTI_do_M0_do_Timer1(void){

    // Passo 3: Parar o Timer
    TA1CCR0 = 0;

    // Passo 4: Verifica se S2 foi pressionada
    if( (~P1IN) & BIT3 ){
        // Chave S2 pressionada, entao realiza a acao de S2

        if( TA0CCR1 >= 328 ){
            TA0CCR1 = 0;
        }else{
            TA0CCR1 += 82;// TA0CCR1 = TA0CCR1 + 82;
        }
    }

    // Passo 5: habilita int. de S2
    P1IFG &= ~BIT3;
    P1IE = BIT3;
}


void ini_Timer1_Debouncer(void){
    /* TIMER1 - Debouncer de S2
     *    - tempo = 3 ms
     *
     * CONTADOR:
     *      - Clock: SMCLK ~ 2 MHz
     *           - Fdiv: 1
     *      - Modo: UP
     *      - Int.: Desabilitada.
     *
     * MODULO 0:
     *      - Funcao: comparacao
     *      - Int.: Habilitada
     *      - TA1CCR0: inicialmente com ZERO
     */
    TA1CTL = TASSEL1 + MC0;
    TA1CCTL0 = CCIE;
    TA1CCR0 = 0;
}

void ini_Timer0_PWM(void){
    /* Timer0 para gerar PWM para controle do LED VD
     *   - Frequencia/periodo: 100Hz / 10ms
     *   - RC.: 0% inicial
     *
     * CONTADOR:
     *      - Clock: ACLK = 32768 Hz
     *          - Fdiv: 1
     *      - Int.: Desabilitada
     *      - Modo: UP
     *
     * MODULO 0: -> ref. de periodo/freq. do PWM
     *      - Funcao: comparacao
     *      - Int.: desabilitada
     *      - TA0CCR0 = (32768 * 0,01) -1 = 327
     *
     * MODULO 1: -> Gerar o sinal
     *      - Funcao: comparacao
     *      - Int.: desabilitada
     *      - Modo de saida: 7 (reset/set)
     *      - TA0CCR1 = 0;
     */
    TA0CTL = TASSEL0 + MC0;
    TA0CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT;
    TA0CCR0 = 327;
    TA0CCR1 = 0;
}


void ini_P1_P2(void){
    /* PORTA 1
     *    P1.0 - LED VM - saida em nivel baixo
     *    P1.3 - S2 - Entrada com resistor de pull-up
     *                e int. por borda de descida.
     *    P1.6 - TA0.1 - Mudar funcao!!!
     */
    P1DIR = ~BIT3;
    P1REN = BIT3;
    P1OUT = BIT3;

    P1SEL |= BIT6; // --> P1.6 para TA0.1

    P1IES = BIT3;
    P1IFG = 0;
    P1IE = BIT3;

    /* PORTA 2
     *      P2.X - N.C. - Todos como saida em nivel baixo.
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


