/* Ler um n�mero float. Se a parte decimal desse n�mero � maior ou igual a 0.5
arredond�-lo para o pr�ximo inteiro, caso contr�rio trunc�-lo. N�o � permitido utilizar
fun��es prontas.
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
