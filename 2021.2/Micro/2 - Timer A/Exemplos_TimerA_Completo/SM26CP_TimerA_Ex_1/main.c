/* SM26CP - Exemplo 1 do Timer A
 *
 *
 *
 */
#include <msp430.h> 

void ini_P1_P2(void);
void ini_uCon(void);
void ini_Timer0(void);

void main(void)
{
    ini_uCon();
	ini_P1_P2();
	ini_Timer0();
	
	do{
	    // Loop inifito
	    // Opcao: desligar CPU para economizar energia (LPM0)

	    __bis_SR_register(LPM0_bits + GIE);
	}while(1);
}

//-----------------------------------------------------------------------------

#pragma  vector=TIMER0_A0_VECTOR
__interrupt void RTI_do_Mod0_Timer0(void){
    /* 1 - Precisa limpar flag de int?
     *       R.: Nao, pois o hw limpa autom.
     *
     *  A CPU entra nesta RTI a cada 1s
     */

    P1OUT ^= BIT0;

}

void ini_Timer0(void){

    /* Inicializacao do Timer 0
     *
     *   -> interrupcao temporizada de 1 s
     *
     * CONTADOR
     *   - CLOCK: ACLK
     *   - FDIV: 1
     *   - Modo do contador: UP
     *   - Int. do contador: desativada
     *
     * MODULO 0
     *   - Funcao: comparacao
     *   - Valor para TA0CCR0 = 32767
     *   - Int.: habilitar
     *
     */
    TA0CTL = TASSEL0 + MC0;

    TA0CCTL0 = CCIE;

    TA0CCR0 = 32767;
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

void ini_P1_P2(void){
    /* PORTA 1
     *     P1.0 - LED VM - Saida em nivel baixo
     *     P1.x - N.C. - saidas em nivem baixo
     */
    P1DIR = 0xFF;
    P1OUT = 0;

    /* PORTA 2
     *     P2.x - N.C. - saidas em nivem baixo
     *
     *     E os pinos 18 e 19? como o oscilador LFXT1 sera
     *     utilizado, as funcoes XIN e XOUT devem ser mantidas
     */
    P2DIR = 0xFF;
    P2OUT = 0;
}