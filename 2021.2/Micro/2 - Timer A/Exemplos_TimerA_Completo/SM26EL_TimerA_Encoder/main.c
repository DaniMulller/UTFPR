/* SM26EL - Exercicio encoder
 *
 *      Sa -> P1.4
 *      Sb -> P1.5
 *
 *      S2 -> P1.3 - Resetar variaval count
 *
 *      OBJ.: Incrementar uma variavel conforme os passos do encoder.
 *            Varivavel "count" 0 a 10.
 *               - Se for 0, Led VD acende
 *               - Se for 10, Led VM acende
 */
#include <msp430.h> 


void config_ini(void);
void ini_P1_P2(void);
void ini_Timer0_Debouncer(void);

unsigned char count = 0;

void main(void){
    config_ini();
    ini_P1_P2();
    ini_Timer0_Debouncer();
	

	do{
	    if(count >= 10) P1OUT |= BIT0;
	    else P1OUT &= ~BIT0;

	    if(count == 0)  P1OUT |= BIT6;
	    else P1OUT &= ~BIT6;
	}while(1);
}
//-----------------------------------------------------------------------------------

// RTI da PORTA 1 - Chave S2
#pragma vector=PORT1_VECTOR
__interrupt void RTI_da_Porta_1(void){
    // Passo 1: Desabilitar int. da entrada
    P1IE &= ~BIT3;

    // Passo 2: Ativa o Timer0
    TA0CCR0 = 18000; // para 9 ms
}



// RTI da Porta 2 - Chave Sa do encoder
#pragma vector=PORT2_VECTOR
__interrupt void RTI_da_Porta_2(void){

    // Passo 1: Desabilita int. de Sa
    P2IE &= ~BIT0;

    // Passo 2: Inicia Timer0
    TA0CCR0 = 2000;
}

//RTI do Timer0 - Debouncer
#pragma vector=TIMER0_A0_VECTOR
__interrupt void  RTI_do_Timer0(void){

    // Passo 3: Parar Timer0
    TA0CCR0 = 0;

    // Passo 4: Verifica Chaves
    if( (P1IFG) & BIT3 ){
        if( (~P1IN) & BIT3 ){
            count = 0;
        }
        P1IFG &= ~BIT3;
        P1IE = BIT3;
    }

    if( (P2IFG) & BIT0 ){
        if( (~P2IN) & BIT0 ){ // Sinal de Sa em nivel baixo?

           if( P2IN & BIT1){
               // Sinal de Sb em nivel alto: Sentido horario

               if(count < 10) count++;

           }else{
               // Sinal de Sb em nivel baixo: Sentido ANTI-Horario
               if(count > 0) count--;
           }

        }
        P2IFG &= ~BIT0;
        P2IE = BIT0;
    }
}



void ini_Timer0_Debouncer(void){
    /* Tempo debouncer: 9 ms
     *
     * CONTADOR:
     *      - Clock: SMCLK ~ 2 MHz
     *          - FDiv: 1
     *      - Modo: UP
     *      - Int.: desabilitada
     *
     * MODULO 0:
     *      - Funcao: comparacao
     *      - Int.: Habilitada
     *      - Valor para TA0CCR0:
     *          TA0CCR0 = 0; // Contador parado
     *
     */
    TA0CTL = TASSEL1 + MC0;
    TA0CCTL0 = CCIE;
    TA0CCR0 = 0; // Contador fica parado!
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



void ini_P1_P2(void){
    /* Inicizalizacao da PORTA 1
     *      -> P1.0 - LED VM - Saida em nivel baixo
     *      -> P1.3 - S2 - Entrada com resistor de pull-up
     *                     com int. por borda de descida.
     *      -> P1.6 - LED VD - Saida em nivel baixo
     *      -> P1.X - N.C. - Saidas em nivel baixo.
     *
     */
     P1DIR = ~BIT3;
     P1REN = BIT3;
     P1OUT = BIT3;

     P1IES = BIT3;
     P1IFG = 0;
     P1IE = BIT3;


    /* Inicializacao da PORTA 2
     *
     *      -> P2.0 - Sa do encoder - entrada resistor de pull-up
     *                com interrupcao por borda de descida.
     *      -> P2.1 - Sb do encoder - entrada com resistor de pull-up.
     *
     *      -> P2.X - N.C. - Saidas em nivel baixo.
     *      >>> Pinos 18 e 19 - Permanecem com as funcoes nativas
     *                          XIN/XOUT para funcionamento com o
     *                          XT1 de 32k;
     */
    P2DIR = ~(BIT0 + BIT1);
    P2REN = BIT0 + BIT1;
    P2OUT = BIT0 + BIT1;

    P2IES = BIT0;
    P2IFG = 0;
    P2IE = BIT0;
}






