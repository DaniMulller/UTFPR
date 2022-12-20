/* SM26CP - Exercicio Encoder
 *      -> Incrementa/decrementa variavel
 *      -> Sinaliza por meio dos leds
 *
 */
#include <msp430.h> 

void ini_uCon(void);
void ini_P1_P2(void);
void ini_Timer0_Deb(void);
void ini_Timer1_Pisca(void);

unsigned char npisca = 0, count = 0;



void main(void)
{
    ini_uCon();
    ini_P1_P2();
    ini_Timer0_Deb();
    ini_Timer1_Pisca();
	
	do{
	    // Loop
	}while(1);
}
//----------------------------------------------------------------------------------

// RTI da PORTA 2
#pragma vector=PORT2_VECTOR
__interrupt void RTI_da_Porta_2(void){

    // 1 - desabilitar int. de P2.0
    P2IE &= ~BIT0;

    // 2 - Iniciar Temporizador
    TA0CTL |= MC0;
}

// RTI do Modulo 0 do Timer0
#pragma vector=TIMER0_A0_VECTOR
__interrupt void RTI_M0_Timer0(void){

    // 1 - Parar temporizador
    TA0CTL &= ~MC0;

    /* 2 - Verificar se P2.0 esta em nivel
           baixo
               - Verificar sentido de giro
    */
    if( (~P2IN) & BIT0 ){ // Verifica se entrada de Sa esta em nivel baixo
                          // para validar tecla.

        if(P2IN & BIT1){  // Verifica sentido do passo
            if(count >= 10){  // Sentido horario
                count = 10;
            }else{
                count++;
            }
        }else{
            if(count <= 0){  // Sentido ANTI-horario
                count = 0;
            }else{
                count--;
            }
        }
        TA1CTL |= MC0;
        npisca = count << 1;
    }
    P2IFG = 0;
    P2IE |= BIT0;
}


// RTI do Modulo 0 do Timer1
#pragma vector=TIMER1_A0_VECTOR
__interrupt void RTI_M0_Timer1(void){

    if( npisca == 0){
        TA1CTL &= ~MC0; // Para o Timer 1
        P1OUT &= ~BIT0;
    }else{
        npisca--;
        P1OUT ^= BIT0;
    }

}


void ini_Timer1_Pisca(void){
    /* Inicializacao do Timer 1
     *
     * -> Temporizacao t ~ 20 ms
     *
     * CONTADOR:
     *      - Clock: ACLK
     *           -> Fdiv = 1
     *      - Modo: UP (inicialmente parado)
     *      - int.: desabilitada
     *
     * MODULO 0:
     *      - Funcao: comparacao
     *      - Int.: habilitada
     *      - TA1CCR0 = (0,02 * 32768) - 1 = 655
     */
    TA1CTL = TASSEL0;
    TA1CCTL0 = CCIE;
    TA1CCR0 = 655;
}


void ini_Timer0_Deb(void){
    /* Ini. Timer0 para Debouncer
     *
     * -> Temporizacao de ~ 1 ms
     *
     * CONTADOR:
     *      - Clock: SMCLK ~ 2 MHz
     *           -> Fdiv: 1
     *      - Modo: UP (inicialmente parado)
     *      - Int.: desabilitada
     *
     * MODULO 0:
     *      - Funcao: comparacao (nativa)
     *      - Int.: habilitada
     *      - Valor para TA0CCR0
     *          -> TA0CCR0 = (0,001 * 2M) = 20000
     */
    TA0CTL = TASSEL1;
    TA0CCTL0 = CCIE;
    TA0CCR0 = 20000;
}

void ini_P1_P2(void){
    /* Inicializacao da PORTA 1
     *      P1.0 - LED VM - Saida em nivel baixo
     *      P1.6 - LED VD - Saida em nivel baixo
     *      P1.X - N.C. - Saidas em nivel baixo
     */
    P1DIR = 0xFF;
    P1OUT = 0;


    /* Inicializacao da PORTA 2
     *
     *      P2.0 - Sa enc. - Entrada c/ resist. pull-up e int.
     *             por borda de descida.
     *      P2.1 - Sb enc. - Entrada c/ resist. pull-up
     *      P2.X - N.C. - Saidas em nivel baixo.
     *      Pinos 18 e 19 - Funcao XIN/XOUT.
     *
     */
    P2DIR = ~(BIT0 + BIT1);
    // P2DIR = BIT2 + BIT3 +.... + BIT7;
    P2REN = BIT0 + BIT1;
    P2OUT = BIT0 + BIT1;

    P2IES = BIT0;
    P2IFG = 0;
    P2IE = BIT0;
}




void ini_uCon(void){

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    /* Configuracao do BCS
     *
     * -> Osciladores:
     *      VLO = Nao utilizado
     *      LXFT1CLK = 32.768 Hz
     *      DCOCLK ~ 16 MHz (via dados de calibrado do fab.)
     *
     * -> Saidas de CLK
     *      ACLK = LFXT1CLK = 32.768 Hz
     *      MCLK = DCOCLK ~ 16 MHz
     *      SMCLK = DCOCLK/8 ~ 2 MHz
     */
    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ;
    BCSCTL2 = DIVS0 + DIVS1;
    BCSCTL3 = XCAP0 + XCAP1;

    while(BCSCTL3 & LFXT1OF); // sai quando oscilador atingir a freq. do xtal

    __enable_interrupt(); // Habilita a CPU a aceitar req. de int.
}


