/*Faça um programa para calcular a quantidade de fita necessária, em centímetros, para
amarrar um pacote com duas voltas, sendo uma pela largura e outra pelo comprimento do
pacote. Serão fornecidas a largura, a altura e o comprimento do pacote. Para amarrar as
pontas da fita são necessários 15 cm de fita em cada ponta. A Figura ilustra a maneira como
a fita é passada pelo pacote.*/

# include <stdio.h>

int main(void)

{
    float largura, altura, comprimento;

    printf("Informe a largura do pacote(cm): ");
    scanf("%f",&largura);
    printf("Informe a altura do pacote(cm): ");
    scanf("%f",&altura);
    printf("Informe o comprimento do pacote(cm): ");
    scanf("%f",&comprimento);

    printf("\nSerao necessarios %.2f cm de fita\n",2*comprimento+2*largura+2*altura + 60);
}
