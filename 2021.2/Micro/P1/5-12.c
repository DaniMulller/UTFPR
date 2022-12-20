#pragma vector=PORT1_VECTOR
__interrupt void RTI_da_Porta_1(void) {

    P1IFG &= ~BIT0; //limpa a flag de ON/OFF
    P2OUT |= BIT1; //liga a valvula senoide VE
    P1OUT &= ~BIT2; //liga o LED LP de maquina ligada
    P1OUT |= BIT3; //liga o LED LE de enchimento

    while(P2IN & BIT7){
        //enquanto a chave SN (P2.7) va para sinal baixo (tanque cheio)
    };

    P2OUT &= ~BIT1; //desliga a valvula senoid VE
    P1OUT &= ~BIT3; //desliga o LED VE de enchimento
}

void main(void){
    /*PORTA1*/
    P1DIR = BIT2+BIT3+BIT4+BIT5+BIT6+BIT7;
    P1REN = BIT0+BIT1; //Resistores nas entradas
    P1OUT = BIT2+BIT6+BIT7; //LED's desligados
    P1IE = BIT0+BIT1 //habilitando interrupção em ON/OFF e ST
    P1IES = 0; //borda de interrupcao de subida
    P1IFG = 0; //resetar as flags

    /*PORTA2*/
    P2SEL &= ~(BIT6+BIT7); //mudar a funcao dos pinos P2.6 e P2.7
    P2DIR = BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6; //somente P2.7 como entrada
    P2REN = BIT7; //resistor em SN
    P2OUT = BIT7; //resistor pull-up
    P2IE = BIT7; //habilitando interrupção em SN
    P2IES = BIT7; //borda de interrupcao de descida
    P2IFG = 0; //resetar as flags de P2

}