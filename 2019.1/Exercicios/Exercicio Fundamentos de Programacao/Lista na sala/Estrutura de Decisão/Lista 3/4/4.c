/*Fa�a um programa que leia tr�s valores representando os lados de um tri�ngulo.
Primeiro, coloque esses valores em ordem crescente, em seguida determine e mostre o
tipo de tri�ngulo que esses lados formam de acordo com as seguintes defini��es. Para
essas defini��es a � o maior valor, b o do meio e c o menor.

Se a > b + c � valores n�o formam um tri�ngulo;
Se a == b == c � tri�ngulo equil�tero;
Se a == b e a != c, se a == c e a != b, e b == c e b != a � tri�ngulo is�sceles;
Se a != b != c � tri�ngulo escaleno;

Observa��o: um mesmo tri�ngulo pode ser classificado em mais de um tipo. Portanto,
utilizar ifs separados ao inv�s de ifs encadeados.*/

# include <stdio.h>

int main(void)

{
    int num1, num2, num3, maior, meio, menor;

    printf("Informe o primeiro valor: ");
    scanf("%d",&num1);
    printf("Informe o segundo valor: ");
    scanf("%d",&num2);
    printf("Informe o terceiro valor: ");
    scanf("%d",&num3);

    if (num1>num2 && num1>num3)
    {
        maior = num1;

        if (num2>num3)
        {
            meio = num2;
            menor = num3;

            if (num1>num2+num3)
            {
                printf("\nNao formam trinagulo\n");
            }
            else if (num1*num1 == num2*num2 + num3*num3)
            {
                printf("\nTriangulo retangulo\n");
            }
            else if (num1*num1>num2*num2 + num3*num3)
            {
                printf("\nTriangulo obtusangulo\n");
            }
            else if (num1*num1<num2*num2 + num3*num3)
            {
                printf("\nTriangulo acutangulo\n");
            }
            else if (num1==num2==num3)
            {
                printf("\nTriangulo equilatero\n");
            }
            else if ((num1==num2 && num1!=num3)|| (num1==num3 && num1!=num2) ||(num2==num3 && num2!=num1))
            {
                printf("\nTrinagulo isoceles\n");
            }
            else if (num1!=num2!=num3)
            {
                printf("\nTriangulo escaleno\n");
            }
        }
        else
          {
            meio = num3;
            menor = num2;

            if (num1>num2+num3)
            {
                printf("\nNao formam trinagulo\n");
            }
            else if (num1*num1 == num2*num2 + num3*num3)
            {
                printf("\nTriangulo retangulo\n");
            }
            else if (num1*num1>num2*num2 + num3*num3)
            {
                printf("\nTriangulo obtusangulo\n");
            }
            else if (num1*num1<num2*num2 + num3*num3)
            {
                printf("\nTriangulo acutangulo\n");
            }
            else if (num1==num2==num3)
            {
                printf("\nTriangulo equilatero\n");
            }
            else if ((num1==num2 && num1!=num3)|| (num1=num3 && num1!=num2) ||(num2==num3 && num2!=num1))
            {
                printf("\nTrinagulo isoceles\n");
            }
            else if (num1!=num2!=num3)
            {
                printf("\nTriangulo escaleno\n");
            }
          }
    }
    else if (num2>num1 && num2>num3)
    {
        maior = num2;

        if (num1>num3)
        {
            meio = num1;
            menor = num3;

            if (num2>num1+num3)
            {
                printf("\nNao formam trinagulo\n");
            }
            else if (num2*num2 == num1*num1 + num3*num3)
            {
                printf("\nTriangulo retangulo\n");
            }
            else if (num2*num2>num1*num1 + num3*num3)
            {
                printf("\nTriangulo obtusangulo\n");
            }
            else if (num2*num2<num1*num1 + num3*num3)
            {
                printf("\nTriangulo acutangulo\n");
            }
            else if (num1==num2==num3)
            {
                printf("\nTriangulo equilatero\n");
            }
            else if ((num1==num2 && num1!=num3)|| (num1==num3 && num1!=num2) ||(num2==num3 && num2!=num1))
            {
                printf("\nTrinagulo isoceles\n");
            }
            else if (num1!=num2!=num3)
            {
                printf("\nTriangulo escaleno\n");
            }
        }
        else
        {
            meio = num3;
            menor = num1;

            if (num2>num1+num3)
            {
                printf("\nNao formam trinagulo\n");
            }
            else if (num2*num2 == num1*num1 + num3*num3)
            {
                printf("\nTriangulo retangulo\n");
            }
            else if (num2*num2>num1*num1 + num3*num3)
            {
                printf("\nTriangulo obtusangulo\n");
            }
            else if (num2*num2<num1*num1 + num3*num3)
            {
                printf("\nTriangulo acutangulo\n");
            }
            else if (num1==num2==num3)
            {
                printf("\nTriangulo equilatero\n");
            }
            else if ((num1==num2 && num1!=num3)|| (num1==num3 && num1!=num2) ||(num2==num3 && num2!=num1))
            {
                printf("\nTrinagulo isoceles\n");
            }
            else (num1!=num2!=num3)
        }
    }
    else
    {
        maior = num3;

        if (num2>num1)
        {
            meio = num2;
            menor = num1;

            if (num3>num1+num2)
            {
                printf("\nNao formam trinagulo\n");
            }
            else if (num3*num3 == num1*num1 + num2*num2)
            {
                printf("\nTriangulo retangulo\n");
            }
            else if (num3*num3>num1*num1 + num2*num2)
            {
                printf("\nTriangulo obtusangulo\n");
            }
            else if (num3*num3<num1*num1 + num2*num2)
            {
                printf("\nTriangulo acutangulo\n");
            }
            else if (num1==num2==num3)
            {
                printf("\nTriangulo equilatero\n");
            }
            else if ((num1==num2 && num1!=num3)|| (num1==num3 && num1!=num2) ||(num2==num3 && num2!=num1))
            {
                printf("\nTrinagulo isoceles\n");
            }
            else if (num1!=num2!=num3)
        }
        else
        {
            meio = num1;
            menor = num2;

            if (num3>num1+num2)
            {
                printf("\nNao formam trinagulo\n");
            }
            else if (num3*num3 == num1*num1 + num2*num2)
            {
                printf("\nTriangulo retangulo\n");
            }
            else if (num3*num3>num1*num1 + num2*num2)
            {
                printf("\nTriangulo obtusangulo\n");
            }
            else if (num3*num3<num1*num1 + num2*num2)
            {
                printf("\nTriangulo acutangulo\n");
            }
            else if (num1==num2==num3)
            {
                printf("\nTriangulo equilatero\n");
            }
            else if ((num1==num2 && num1!=num3)|| (num1==num3 && num1!=num2) ||(num2==num3 && num2!=num1))
            {
                printf("\nTrinagulo isoceles\n");
            }
            else (num1!=num2!=num3)
        }
    }


}
