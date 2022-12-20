#define UM (BIT3)
#define DOIS (BIT0+BIT4)
#define TRES (BIT2+BIT3+BIT6)
#define QUATRO (BIT0+BIT2+BIT4+BIT6)
#define CINCO (BIT0+BIT2+BIT3+BIT4+BIT6)
#define SEIS (BIT0+BIT1+BIT2+BIT4+BIT5+BIT6)

unsigned char count = 1;

#pragma vector=PORT1_VECTOR
__interrupt void RTI_Porta1(void) {
    P1IFG &= ~BIT5; //Limpas as flags da chave S2

    //count conta quantas vezes a chave S2 foi pressionada
    switch (count){
        case 1:
            P2OUT = UM;
            break;
        case 2:
            P2OUT = DOIS;
            break;
        case 3:
            P2OUT = TRES;
            break;
        case 4:
            P2OUT = QUATRO;
            break;
        case 5:
            P2OUT = CINCO;
            break;
        case 6:
            P2OUT = SEIS;
            break;
    }
} 

void main(void){
    /*PORTA 1*/
    P1DIR = BIT0+BIT1+BIT2+BIT3+BIT4+BIT6+BIT7;
    P1REN = BIT5;
    P1OUT = 0;
    P1IES = 0;
    P1IFG = 0;
    P1IE = BIT5;

    /*PORTA 2*/
    P2DIR = 1;
    P2OUT = 0;
    P2SEL &= ~(BIT6+BIT7); //habilitar a porta P2.6

    __enable_interrupt();

    do{
    if(count >= 6){ //6 eh o numero maximo, volta pra 1
        count = 1;
    }
    else{
        count++; //adiciona +1 no count de S2
    }
    }while(1);
}