/* Ler um n�mero float, se o mesmo possui parte decimal arredond�-lo para o pr�ximo
inteiro. N�o � permitido utilizar fun��es prontas.
Por exemplo:
Informado: 5.005
Mostrar: 6
Informado: 5.00
Mostrar: 5*/

#include <stdio.h>

int main(void)

{
    float num;
    int num_int;

    printf("Informe um numero: ");
    scanf("%f",&num);

    num_int = num+1;

    printf("\nInformado: %f, Proximo inteiro: %d\n",num,num_int);
}

