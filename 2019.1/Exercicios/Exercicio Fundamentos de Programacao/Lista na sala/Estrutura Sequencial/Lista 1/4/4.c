# include <stdio.h>

int main(void)

{
    int nota1;
    int nota2;
    int nota3;
    float nota_final;

    printf("informe a nota da primeira prova: ");
    scanf("%d",&nota1);
    printf("Informe a nota da segunda prova: ");
    scanf("%d",&nota2);
    printf("Informe a nota da terceira prova: ");
    scanf("%d",&nota3);

    nota_final = (nota1 + nota2*3 + nota3*5)/3;

    printf("\nA nota final e de: %.2f\n",nota_final);
}
