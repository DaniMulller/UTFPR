/*Apresentar a tabuada de um n�mero informado pelo usu�rio. A tabuada deve ser
apresentada na forma a seguir (sendo 'a' o valor informado e as outras letras o resultado da
multiplica��o):
a * 0 = c
a * 1 = d
..
a * 10 = z*/

# include <stdio.h>

int main(void)

{
    int num,i;

    printf("Informe um numero: ");
    scanf("%d",&num);

    for (i=0 ; i<=10 ;i=i+1)
    {
        printf("%d * %d = %d \n",num,i,i*num);
    }
}
