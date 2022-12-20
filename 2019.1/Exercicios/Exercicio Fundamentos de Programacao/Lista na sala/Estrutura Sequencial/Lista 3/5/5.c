/*Fa�a um programa para calcular a quantidade de fita necess�ria, em cent�metros, para
amarrar um pacote com duas voltas, sendo uma pela largura e outra pelo comprimento do
pacote. Ser�o fornecidas a largura, a altura e o comprimento do pacote. Para amarrar as
pontas da fita s�o necess�rios 15 cm de fita em cada ponta. A Figura ilustra a maneira como
a fita � passada pelo pacote.*/

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
