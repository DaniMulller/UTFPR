/*Elaborar um algoritmo que leia um caractere. Se informado �F� ou �f� mostrar a
mensagem �pessoa f�sica�, se informado �J� ou �j� mostrar a mensagem �pessoa jur�dica�
ou "tipo de pessoa inv�lido" para qualquer outro caractere.
char Pessoa; //declarar uma vari�vel do tipo char
scanf(�%c�,&Pessoa); //para ler um char
if (Pessoa == �f� || Pessoa == �F�) //para comparar se o conte�do armazenado na vari�vel
� um determinado caractere.*/

# include <stdio.h>

int main(void)

{
    char pessoa;

    printf("Informe um tipo de pessoa(F ou f, Pessoa Fisica, J ou j, Pessoa Juridica): ");
    scanf("%c",&pessoa);

    if (pessoa == 'F' || pessoa == 'f')
    {
        printf("\nPessoa Fisica\n");
    }
    else if (pessoa == 'J' || pessoa == 'j')
    {
        printf("\nPessoa Juridica\n");
    }
    else
    {
        printf("\nTipo de pessoa invalido\n");
    }
}
