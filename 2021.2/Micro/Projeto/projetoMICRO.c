#include <msp430.h>
#include <stdio.h>

ini_uCon(void);
ini_P1(void);
ini_P2(void);
ini_TA0_ADC10(void);
ini_TA1_PWM(void);
ini_USCI_UART(void);

unsigned int media = 0, soma = 0;
unsigned int ADC10_vector[16]; //16 conversoes consecutivas
unsigned char i = 0, Con_int = 0, Con_dec1 = 0, Con_dec2 = 0; //Parte inteira da concentração, 
//decimal 1 e decimal 2
unsigned char TX_data[32], TX_index=0;
float Con = 0.0, aux = 0.0; //Concentração

void main(void){
    ini_uCon();
    ini_P1();
    ini_P2();
    ini_TA0_ADC10();
    ini_TA1_PWM();
    ini_USCI_UART();

    do{

    }while(1);
}

#pragma vector=ADC10_VECTOR
__interupt void RTI_ADC10(void){
    ADC10CTL0 &= ~ENC; //desabilitar conversoes 

    media=0; //declarada global unsigned int media
    soma=0; //declarada global unsigned int soma
    for (i=0;i<16;i++){
        soma = soma + ADC10_vector[i];
    }
    media = soma >> 4;//cada bit deslocado é divido por 2, deslocando 4 é dividido por 16

    Con = media/????; //Concentração, Ex: Con = 33.52

    Con_int = (unsigned char)Con; //typecast para pegar a parte inteira, Ex: Con_int = 33
    aux = Con - (float)Con_int; //aux guarda a parte decimal, Ex: aux = 0.52
    aux = aux*10.0; //Ex: aux= 5.2
    Con_dec1 = (unsigned char) aux; //Ex: Con_dec1 = 5
    aux = aux - (float)Con_dec1; //Ex: aux = 0.2
    aux = aux*10.0; //Ex: 2.0
    Con_dec2 = (unsigned char)aux; //Ex: Con_dec2 = 2

    //printa na tela a concentração media
    sprintf(&TX_data[0],"Concentração Média = %d,%d%d ppm\n",Con_int,Con_dec1,Con_dec2);

    //envio da string
    UCA0TXBUF = TX_data[0];
    TX_index++;
    //atualiza automaticamente para o prox caracter via RTI de transmissao USCI

    //preparar para as prox conversoes
    ADC10SA = &ADC10_vector[0]; //endereço do primeiro elemento do vetor
    ADC10CTL0 |= ENC;
}

#pragma vector=USCIAB0TX_VECTOR
__interupt void RTI_USCI_UART(void){
    IFG2 &= ~UCA0TXIFG; //limpa flag

    //declarada global unsigned char TX_data[32], TX_index=0
    if(TX_data[TX_index]=='\0'){ //encontra caracter nulo = terminou a string
        TX_index = 0; //limpar a variavel
    }
    else if(TX_index>=32){ //chegou no final do vetor
        TX_index = 0; //limpa a variavel
    }else{
        UCA0TXBUF = TX_data[TX_index]; //buffer recebe o caracter atual
        TX_index++; //incrementar para o prox caracter ser transmitido
    }

}


void ini_uCon(void){
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;
    BCSCTL2 = DIVS0;
            BCSCTL3 = XCAP0 + XCAP1;
            while(BCSCTL3 & LFXT1OF); 
    __enable_interrupt();
}

void ini_P1(void){
    P1SEL |= BIT1 + BIT2;
    P1SEL2 |= BIT1 + BIT2;
    P1DIR = ~(BIT3); //P1.3 chave de entrada
    P1REN = BIT3; //Resistor na chave
    P1OUT = BIT3; //have em pull-up e todas as saída em nível baixo
}

void ini_P2(void){
    P2DIR = BIT0+BIT1+BIT3+BIT4+BIT5; //Saídas nas portas 2 referentes aos leds
    P2OUT = 0; //todas as saída em nível baixo
}

void ini_TA0_ADC10(void){
    /* Ta = 50us -> fa = 20kHz
    * CONTADOR
    *   - Clock: SMCLK ~ 500kHz
    *   - FDIV: 1
    *   - Modo: Up
    *   - Int.: Desabilitada
    * 
    * MODULO 0
    *   - Funcao: Comparacao
    *   - TA0CCR0 = (50us * 500kHz) - 1 = 24
    *   - Int.: Desabilitada
    * 
    * MODULO 1
    *   - Funcao: Comparacao
    *   - TA0CCR1 = 12; (RC de 50%)
    *   - Modo Saida: reset/set
    *   - Int.: Desabilitada
    */
   TA0CTL = TASSEL1+MC0;
   TACCR0 = 24;
   TA0CCTL1 = OUTMOD0+OUTMOD1+OUTMOD2;
   TA0CCR1 = 12;
}

void ini_TA1_PWM(void){
    /* fa = 1kHz -> ta = 1ms
    * CONTADOR
    *   - Clock: SMCLK ~ 500kHz
    *   - FDIV = 1
    *   - Modo: Up
    *   - Int.: Desabilitada
    * 
    * MODULO 0
    *   - Funcao: Comparacao
    *   - TA1CCR0 = (100ms * 500kHz) - 1 = 49999
    *   - Int.: Desabilitada
    * 
    * MODULO 1
    *   - Funcao: Comparacao
    *   - TA1CCR1 = 0; (RC de 0%)
    *   - Modo Saida: reset/set
    *   - Int.: Desabilitada
    */
   TA1CTL = TASSEL1+MC0;
   TA1CCR0 = 49999;
   TA1CCTL1 = OUTMOD0+OUTMOD1+OUTMOD2;
   TA1CCR1 = 0;
}

void ini_ADC10(void){
    /* Taxa de Amostragem = 200kbps
    *   - Vref = 5V
    *   - VrefInterna = 2,5V
    *   - Tsample = 50us
    *   - n ciclos = 16
    *   - Buffer: nao precisa pois Vref vem diretamente de Vcc
    *   - DTC: 16 transferencias (16 conversoes consecutivas)
    *       - Modo: 1 bloco
    * 
    *   - Entrada Analogica em A4
    */
    ADC10CTL0 = ADC10SHT1 + MSC + REF2_5V + REFON + ADC10ON + ADC10IE;
    ADC10CTL1 = INCH2 + SHS0 + CONSEQ1;
    ADC10DTC0 = 0; //nenhum bit é setado em DTC0
    ADC10DTC1 = 16; //16 conversoes consecutivas
    //declarada global unsigned int ADC10_vector[16]
    ADC10SA = &ADC10_vector[0]; //endereço do primeiro elemento do vetor
    ADC10CTL0 |= ENC; //setar por ultimo
}

void ini_USCI_UART(void){
    /*
    * Taxa = 9600bps, Sem paridade, 1 Stop Bit
    * Clock = DCOCLK ~ 1MHz ??? //nao usei o SMCLK porque na tabela de config do modulador
    * nao tem 500kHz na coluna frequencia
    * Da tabela do modulador:
    * UCBRx = 104dec = 00 68hex; 
    * UCBRSx = 1dec = 00 01hex;
    * UCBRFx = 0
    */
    UCA0CTL1 |= UCSWRST; //bit de reset
    UCA0CTL0 = 0; //nenhum bit é setado
    UCA0CTL1 = UCSWRST; //Clock UCLK ??? e bit de reset setado
    
    UCA0BR0 = 0x68 //BIT's menos significativos
    UCA0BR1 = 0x00 //BIT's mais significativos

    UCA0MCTL = UCBRS0; // 1

    P1SEL |= BIT2;
    P1SEL2 |= BIT2;

    UCA0CTL1 &= ~UCSWRST; //habilitar a interface, tirar do reset
    IFG2 &= ~UCA0TXIFG; //limpar a flag de int. por transmissao
    IE2 |= UCA0TXIE; //habilitar int. por transmissao
}
