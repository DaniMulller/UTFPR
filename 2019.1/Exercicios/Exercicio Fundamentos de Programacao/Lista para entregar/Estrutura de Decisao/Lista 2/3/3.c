/* Ler um número float. Se a parte decimal desse número é maior ou igual a 0.5
arredondá-lo para o próximo inteiro, caso contrário truncá-lo. Não é permitido utilizar
funções prontas.
Por exemplo:
Informado: 5.45
Mostrar: 5
Informado: 5.987
Mostrar: 6*/

# include <stdio.h>

int main(void)

{
    float num,decimal;
    int num_int;

    printf("Informe um numero: ");
    scanf("%f",&num);

    num_int = num;
    decimal = num-num_int;

    if (decimal >= 0.5)
    {
        printf("\nInformado %f, Arredondado %d\n",num,num_int+1);
    }
    else
    {
         printf("\nInformado %f, Arredondado %d\n",num,num_int);
    }
}
