/* SM26EL - Exemplo Debounce para S2 e Sx
 *          -> Sx mapeada na entrada P1.2
 *
 */


#include <msp430.h> 

void config_ini(void);
void ini_P1_P2(void);
void ini_Timer0_Deboucer(void);

unsigned char count = 0;

void main(void)
{

    config_ini();
    ini_P1_P2();
    ini_Timer0_Deboucer();


    do{

    }while(1);
}
//--------------------------------------------------------------------------------------------

// RTI da PORTA 1
#pragma vector=PORT1_VECTOR
__interrupt void RTI_da_Porta_1(void){
    // Passo 1: Desabilitar int. de P1.3 e P1.2
    P1IE &= ~(BIT3 + BIT2);

    // Passo 2: Iniciar Temporizador
    TA0CTL |= MC0;
}

// RTI do Modulo 0 do TImer 0
#pragma vector=TIMER0_A0_VECTOR
__interrupt void RTI_do_M0_do_Timer0(void){

    // Passo 3: Parada do temporizador
    TA0CTL &= ~MC0;

    // Passo 4: Verfica e valida tecla

    switch( P1IFG & (BIT2 + BIT3)  ){
        case BIT2:
            if( (~P1IN) & BIT2  ){
                // Realiza a acao da tecla
                P1OUT ^= BIT6;
            }
            // Passo 5: Limpar flag de int. de P1.2
            P1IFG &= ~BIT2;
        break;

        case BIT3:
            if( (~P1IN) & BIT3  ){
                // Realiza a acao da tecla
                P1OUT ^= BIT0;
            }
            // Passo 5: Limpar flag de int. de P1.3
            P1IFG &= ~BIT3;
        break;

        default:
            // Se ambas foram pressionadas, nao faz nada
            P1IFG &= ~(BIT2 + BIT3);
        break;

    }
    // Passo 6: Habilita int. de P1.2 E P1.3
    P1IE |= BIT2 + BIT3;
}




void ini_Timer0_Deboucer(void){
    /* Inicializacao do TImer 0 para o debouncer de S2
     *
     * CONTADOR:
     *      - Clock: SMCLK ~ 2 MHz
     *          - Fdiv: 1
     *      - Modo contagem: UP (inicialmente ficara no modo PARADO)
     *      - Int. do contador: desabilitada
     *
     * MODULO 0:
     *      - Funcao: comparacao (nativa)
     *      - Int.: Habilitada
     *      - Valor para TA0CCR0: 10000
     *
     */
    TA0CTL = TASSEL1;
    TA0CCTL0 = CCIE;
    TA0CCR0 = 10000;
}

void ini_P1_P2(void){
    /* Inicializacao da PORTA 1
     *      - P1.0 - LED VM - Saida em nivel baixo
     *      - P1.2 - chave Sx - entrada com resist. de pull-up e
     *                          int. habilitada por borda de descida.
     *      - P1.3 - chave S2 - entrada com resist. de pull-up e
     *                          int. habilitada por borda de descida.
     *
     *      - P1.6 - LED VD - Saida em nivel baixo
     *      - P1.x - N.C. - todos como saida em nivel baixo.
     */
    P1DIR = ~(BIT3 + BIT2);
    P1REN = BIT3 + BIT2;
    P1OUT = BIT3 + BIT2;

    P1IES = BIT3 + BIT2;
    P1IFG = 0;
    P1IE = BIT3 + BIT2;

    /* Inicializacao da PORTA 2
     *      - P2.X - N.C. - saidas em nivel baixo
     *      Pinos 18 e 19: funcao nativa (XIN/XOUT) deve ser
     *      mantida, pois o oscilador LFXT1 vai usar
     *      o cristal.
     *
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












