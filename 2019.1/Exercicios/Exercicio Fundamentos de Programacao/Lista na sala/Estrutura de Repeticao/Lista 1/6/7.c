/* Ler dois números que representam os limites de um intervalo e ler o incremento.
Mostrar os números desse intervalo de acordo com o incremento indicado e em ordem
crescente. O usuário pode informar os valores que representam os limites do intervalo em
ordem crescente ou decrescente.*/

# include <stdio.h>

int main(void)

{
    int lim_inferior,lim_superior;
    int incremento;
    int i;

    printf("Informe o limite inferior: ");
    scanf("%d",&lim_inferior);
    printf("\nInforme o limite superior: ");
    scanf("%d",&lim_superior);
    printf("\nInforme o incremento: ");
    scanf("%d",&incremento);

    if (lim_inferior>lim_superior) //se necessario, trocar
    {
        i = lim_inferior;
        lim_inferior = lim_superior;
        lim_superior = i;
    }
    for (i=lim_inferior;i<=lim_superior;i=i+incremento)
    {
        printf("%d\t",i);
    }
}
