/*Ler um n�mero float. Separar a parte inteira e a parte decimal desse n�mero. Apresentar
a parte decimal como um valor float e como um inteiro de tr�s d�gitos. Da parte inteira
separar o n�mero representa unidade, dezena e centena e mostrar. Exemplo:
Informado o valor 123.456
Mostrar:
Parte inteira: 123
Parte decimal: 0.456
Parte decimal como inteiro de tr�s d�gitos: 456
Unidade: 1
Dezena: 2
Centena: 3*/

# include <stdio.h>

int main(void)

{
    float num;
    int num_int, un, dez, cen;

    printf("Informe um numero: ");
    scanf("%f",&num);

    printf("\nValor informado: %f\n",num);

    printf("\nParte inteira: %.0f\n",num);

    num_int = num;
    printf("\nParte decimal: %f\n",num-num_int);

    printf("\nParte decimal como inteira de tres digitos: %f\n",num-num_int*100);

    printf("\nUnidade: %d",num_int);


}
