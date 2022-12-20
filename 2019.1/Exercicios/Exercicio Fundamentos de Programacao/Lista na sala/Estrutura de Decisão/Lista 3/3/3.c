/*O código a seguir tem o objetivo de obter o resto da divisão do número maior pelo
menor  (independentemente da ordem que foram informados) e apresentar que não é
possível realizar a divisão caso o divisor seja zero. Faça os ajustes necessários para que
esses objetivos sejam alcançados.*/

# include <stdio.h>

int main(void)

{
   float Num1;
   int Num2;
   int Resto;

   printf("Informe o primeiro valor: ");
   scanf("%d",&Num1);
   printf("Informe o segundo valor: ");
   scanf("%d",&Num2);

   if(Num1 > Num2)
    {
     if (Num1 != 0)
     {
        Resto = (int)Num1 % Num2;
        printf("O resto da divisão é %f\n",Resto);
     }
     else
     {
         printf("\nNao e possivel fazer a divisao por zero\n");
     }
    }
   else if (Num2 > Num1)
    {
     if (Num2 != 0)
     {
        Resto = Num2 % (int)Num1;
        printf("O resto da divisão é %f\n",Resto);
     }
     else
     {
         printf("Nao e possivel fazer a divisao por zero\n");
     }
    }
}
