# include <stdio.h>

int main(void)

{
    int nota1;
    int nota2;
    float media;

    printf ("Informe a primeira nota: ");
    scanf ("%d",&nota1);
    printf ("informe a segunda nota: ");
    scanf ("%d",&nota2);

    media = (nota1 + nota2) / 2;

    printf ("\n\nMedia calculada: %.2f \n ",media);

}
