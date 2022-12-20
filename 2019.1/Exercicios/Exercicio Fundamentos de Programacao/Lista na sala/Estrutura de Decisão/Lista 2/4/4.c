/*Ler o gênero (F ou f para feminino, M ou m para masculino. Para qualquer outro
caractere informar que não há fórmula disponível e finalizar o programa). Se
informado um caractere válido, ler a altura da pessoa e calcular seu peso ideal,
utilizando as seguintes fórmulas:
a) para homens: (72,7 * h) - 58;
b) para mulheres: (62,1 * h) - 44,7.
Observação, para ler caractere e comparar variável do tipo caractere:
char Pessoa;
scanf(“%c”,&Pessoa);
if (Pessoa == ‘f’ || Pessoa == ‘F’)*/

# include <stdio.h>

int main(void)

{
    float altura,peso;
    char genero;

    printf("Informe o genero('m' para masculino e 'f' para feminino): ");
    scanf("%c",&genero);

    if (genero == 'm' || genero == 'f')
    {
        if (genero == 'm')
        {
             printf("\nInforme a altura: ");
             scanf("%f",&altura);

             peso = (72.7*altura) - 58;

             printf("\nO peso ideal e de: %.2f Kg\n",peso);
        }
        else
        {
            printf("\nInforme a altura: ");
            scanf("%f",&altura);

            peso = (62.1*altura) - 44.7;

            printf("\nO peso ideal e de: %.2f Kg\n",peso);
        }
    }
    else
    {
        printf("\nNao ha formula disponivel!\n");

    }
}
