/* O c�digo a seguir tem como objetivos:
a) fazer a divis�o float entre dois valores inteiros informados pelo usu�rio;
b) Obter o resto da divis�o do primeiro n�mero pelo segundo n�mero;*/

# include <stdio.h>

int main(void)

{
    int Num1;
    int Num2;
    int Divisao;
    int Resto;

    printf("Informe o primeiro valor: ");
    scanf("%d",&Num1);
    printf("Informe o segundo valor: ");
    scanf("%d",&Num2);

    Divisao = (float)(Num1 / Num2);
    Resto = Num1%Num2;

    printf("\nA divisao de %d por %d e %d\n",Num1,Num2,Divisao);
    printf("\nO resto da divisao e: %d\n",Resto);
}
