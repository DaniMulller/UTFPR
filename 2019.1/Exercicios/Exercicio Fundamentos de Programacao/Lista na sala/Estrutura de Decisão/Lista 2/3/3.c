/*Ler tr�s valores inteiros e coloc�-los em ordem crescente. Os valores devem ser
apresentados com uma instru��o:

printf(�Menor: %d  Meio: %d  Maior: %d\n�,menor,meio,maior);

Sugest�o: dividir o problema em partes: encontrar o maior, o menor e o do meio
separadamente e armazenar os valores em vari�veis.*/

# include <stdio.h>

int main(void)

{
        int num1,num2,num3;
        int menor,maior,meio;

        printf("Informe um numero: ");
        scanf("%d",&num1);
        printf("Informe outro numero: ");
        scanf("%d",&num2);
        printf("Informe outro numero: ");
        scanf("%d",&num3);

        //menor
        if (num1<num2 && num1<num3)
        {
            menor = num1;
        }
        else if (num2<num3)
        {
            menor = num2;
        }
        else
        {
            menor = num3;
        }

        //maior
        if (num1>num2 && num1>num3)
        {
            maior = num1;
        }
        else if (num2>num3)
        {
            maior = num2;
        }
        else
        {
            maior = num3;
        }

        //meioprintf("Informe um numero: ");
        scanf("%d",&num1);
        if ((num1>num2 && num1<num3)||(num1>num3 && num1<num2))
        {
            meio = num1;
        }
        else if ((num2>num1 && num2<num3) || (num2>num3 && num2<num1))
        {
            meio = num2;
        }
        else
        {
            meio = num3;
        }

        printf("\nOrdem crescente: %d, %d, %d\n",menor,meio,maior);
}
