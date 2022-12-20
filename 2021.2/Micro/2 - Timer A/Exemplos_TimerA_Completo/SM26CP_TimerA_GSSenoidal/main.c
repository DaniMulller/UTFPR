/* Timer A: Exemplo de sintese de sinal senoidal via PWM
 *
 *   >>> Caracteristicas:
 *          - freq. sinal: 100 Hz
 *          - Timer1
 *          - Resolucao do sinal: 32 ciclos PWM/Ciclo senoide
 *
 *   >>> Configuracoes:
 *          - Timer 1: geracao de PWM via Modulo 1
 *              -> Clock: SMCLK
 *              -> Calculos:
 *                     - freq. PWM = 100 * 32 = 3200 Hz
 *                     - Para ajuste da RC de 1 em 1%, o valor de
 *                       TA1CCR1 deve ser de:
 *                        t_pwm = 1/3200  .:. t_clk = 1/f_clk
 *
 *                        t_clk = (1/3200)/100 = 1/320000 = 3,125 us
 *                        fclk = 320 kHz
 *
 *                        Se fclk = 2 MHz, entao a resolucao sera:
 *                             f_clk = f_pwm*res .:. res = f_clk/f_pwm
 *
 *                             res = 2M/3200 = 625 contagens
 *
 *                             res_% = 3200/2M = 0,16 %
 *
 */




#include <msp430.h> 
#include <math.h>



void config_ini(void);
void ini_P1_P2(void);
void ini_Timer1_PWM(void);


unsigned int pwm_vetor[32];
unsigned char i = 0;
float var = 0.0;



void main(void)
{

    config_ini();
    ini_P1_P2();
    ini_Timer1_PWM();

    for(i=0;i<32;i++){
        var = (300.0*(1.0 + sin(6.28318*(i/32.0))) + 10.0 );
        pwm_vetor[i] = (unsigned int) var;
    }
    i = 0;
    TA1CTL |= MC0; // Inicia geracao de PWM

    do{

    }while(1);
}
//-----------------------------------------------------------------------------

//  RTI do Modulo 1 do Timer 1
#pragma vector=TIMER1_A1_VECTOR
__interrupt void RTI_M1_TA1(void){

    /* Esta eh a RTI dos Modulos 1, 2 e contador!
     *
     * Portanto, a flag de int. nao eh limpa automaticamente
     * pelo hardware! Dessa forma, precisamos limpar a flag
     * do Modulo 1, que pode ser feita via vetor de int. TA1IV
     * do timer. A leitura de TA1IV jah limpa as flags. Portanto,
     * pode-se fazer isso da seguinte forma:
     *
     * (void)TA1IV;
     *
     */
    (void)TA1IV;

    TA1CCR1 = pwm_vetor[i];
    if(i >= 31){
        i = 0;
    }else{
        i++;
    }
}


void ini_Timer1_PWM(void){
    /* Inicializacao do Timer 1 para gerar PWM
     *
     * Freq.: 3200 Hz
     *
     * CONTADOR:
     *      - Clock: SMCLK ~ 2 MHz
     *          - Fdiv = 1
     *      - Modo: UP (inicialmente parado)
     *      - Int.: Desabilitada
     *
     * MODULO 0:  -> Responsavel pelo periodo do PWM
     *      - Funcao: comparacao (nativa)
     *      - Int.: Desabilitada
     *      - Valor para TA1CCR0:
     *              = 2 M/3200 - 1 = 624
     *
     * MODULO 1:  -> Gera o sinal PWM/Ajuste RC
     *      - Funcao: comparacao (nativa)
     *      - Modo saida: 7 (Reset/Set)
     *      - TA1CCR1 -> vai depender da amplitude da senoide
     *        e,portanto, deve ser atualizado ciclo-a-ciclo
     *      - Int.: Habilitada!!!
     *
     */
    TA1CTL = TASSEL1;
    TA1CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + CCIE + OUT;
    TA1CCR0 = 624;
    TA1CCR1 = 300; // Nivel medio do sinal PWM
}


void ini_P1_P2(void){
    /* Porta 1
     *      -> P1.0 - LED VM - Saida em nivel baixo
     *      -> P1.6 - LED VD - Saida em nivel baixo
     *      -> P1.x - N.C. - Saida em nivel baixo
     *
     */
    P1DIR = 0xFF;
    P1OUT = 0;

    /* Porta 2
     *      -> P2.1/P2.2 - Saida PWM TA1.1 - Mudar funcao dos pinos
     *          *Opcao de aula de sair com o mesmo sinal nos pinos 9 e 10
     *      -> P2.X - N.C. - Saidas em nivel baixo
     *      -> Pinos 18 e 19 com funcao nativa XIN/XOUT
     */
    P2DIR = 0xFF;
    P2OUT = 0;
    P2SEL |= BIT1 + BIT2;
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






