/*Elaborar um programa para subtrair duas datas. Apresentar o resultado, a diferen�a, em
anos, meses e dias. O usu�rio pode informar as datas em ordem crescente ou decrescente,
caber� ao programa fazer a verifica��o para subtrair a data menor da data maior.
Observa��o: para facilitar considere que os meses possuem 30 dias e assim todos os anos
possuem 360 dias. Para ler um valor no formato data armazenando-o em tr�s vari�veis
distintas � poss�vel utilizar o scanf com a seguinte sintaxe:
scanf(�%d/%d/%d�,&dia,&m�s,&ano);  Observar a barra entre o 1� e o 2� e entre
o 2� e o 3� s�mbolos de %
O usu�rio digitar� a data no formato: 12/12/2008, incluindo as barras, e cada
vari�vel ter� o seu respectivo valor armazenado.*/

# include <stdio.h>

int main(void)

{
    int dia, mes, ano, dia2, mes2, ano2;

    printf("Informe um dia/mes/ano: ");
    scanf("%d/%d/%d",&dia,&mes,&ano);
    printf("Informe outro dia/mes/ano: ");
    scanf("%d/%d/%d",&dia2,&mes2,&ano2);

    if (dia>dia2 && mes>mes2 && ano>ano2)
    {
        printf("\nA subtracao deles e %d dias\n",dia-dia2+(mes-mes2)*30+(ano-ano2)*360);
    }
    else if (dia<dia2 && mes>mes2 && ano>ano2)
    {
        printf("\nA subtracao deles e %d dias\n",dia2-dia+(mes-mes2)*30+(ano-ano2)*360);
    }
    else if (dia>dia2 && mes<mes2 && ano>ano2)
    {
        printf("\nA subtracao deles e %d dias\n",dia-dia2+(mes2-mes)*30+(ano-ano2)*360);
    }
     else if (dia>dia2 && mes>mes2 && ano<ano2)
    {
        printf("\nA subtracao deles e %d dias\n",dia-dia2+(mes-mes2)*30+(ano2-ano)*360);
    }
    else if (dia<dia2 && mes<mes2 && ano>ano2)
    {
        printf("\nA subtracao deles e %d dias\n",dia2-dia+(mes2-mes)*30+(ano-ano2)*360);
    }
    else if (dia<dia2 && mes>mes2 && ano<ano2)
    {
        printf("\nA subtracao deles e %d dias\n",dia2-dia+(mes-mes2)*30+(ano2-ano)*360);
    }
    else if (dia>dia2 && mes<mes2 && ano<ano2)
    {
        printf("\nA subtracao deles e %d dias\n",dia-dia2+(mes2-mes)*30+(ano2-ano)*360);
    }
    else if (dia<dia2 && mes<mes2 && ano<ano2)
    {
        printf("\nA subtracao deles e %d dias\n",dia2-dia+(mes2-mes)*30+(ano2-ano)*360);
    }
}
