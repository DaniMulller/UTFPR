#include <msp430.h> 

#define     seg_a       BIT0
#define     seg_b       BIT1
#define     seg_c       BIT2
#define     seg_d       BIT3
#define     seg_e       BIT4
#define     seg_f       BIT5
#define     seg_g       BIT6
#define     seg_p       BIT7

#define     ZERO        (seg_a + seg_b + seg_c + seg_d + seg_e + seg_f)
#define     UM          (seg_b + seg_c)
#define     DOIS        (seg_a + seg_b + seg_g + seg_e + seg_d)
#define     TRES        (seg_a + seg_b + seg_c + seg_d + seg_g)
#define     QUATRO      (seg_b + seg_c + seg_f + seg_g)
#define     CINCO       (seg_a + seg_c + seg_d + seg_g + seg_f)
#define     SEIS        (seg_a + seg_g + seg_c + seg_d + seg_e + seg_f)
#define     SETE        (seg_a + seg_b + seg_c)
#define     OITO        (seg_a + seg_b + seg_c + seg_d + seg_e + seg_f + seg_g)
#define     NOVE        (seg_a + seg_b + seg_c + seg_d + seg_f + seg_g)

char aux = 0; //Chave pressionada = 1
char contadorUN = 0;
char contadorDZ = 0;


void mostra_digito(char sel_disp) //se sel_disp for igual a 1, seleciona DISP_1, se for igual a 2 seleciona DISP_2
{
    if(char == 1){
        switch(P1IN & BIT0){
            case 0:
                P2OUT = ZERO;
            break;
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
            case 7:
                P2OUT = SETE;
            break;
            case 8:
                P2OUT = OITO;
            break;
            case 9:
                P2OUT = NOVE;
            break;
        }
    }
    else if(char==2){
        switch(P1IN & BIT1){
            case 0:
                P2OUT = ZERO;
            break;
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
            case 7:
                P2OUT = SETE;
            break;
            case 8:
                P2OUT = OITO;
            break;
            case 9:
                P2OUT = NOVE;
            break;
        }
    }
}

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    
    __enable_interrupt();

    // PORTA P1
    P1DIR = BIT7+BIT6+BIT5+BIT4+BIT2+BIT1+BIT0; //P1.3 é entrada(0) e o resto é saída(1)
    P1OUT = 0; //Todas as saídas em nível baixo e P1.3 sem resistor

    //Ativando Interrupção de P1.3
    P1IES = BIT3;
    P1IFG = 0;
    P1IE  = BIT3;

    //PORTA P2
    P2DIR = 1; //Todos os pinos são sáidas
    P2OUT = 0; //Saídas em nível baixo

    do{
        //Código
    }while(1); 
}

//RTI da Porta 1
#pragma vector=PORT1_VECTOR
__interrupt void RTI_da_Porta_1(void){

    //Limpar flag de int. de P1.3
    P1IFG &= ~BIT3;

    //Incrementa o contador global se a chave for pressionada
    if(aux==1){
        aux=0;
    }
    else{
        aux=1;
        contadorUN++;
        if(contadorUN==10){
            contadorUN=0; //reseta o contadorUN quando passa de 9
            contadorDZ++;
            if(contadorDZ==10){
                contadorDZ=0; //reseta o contadorDZ quando passa de 99
            }
        }
    }
}

