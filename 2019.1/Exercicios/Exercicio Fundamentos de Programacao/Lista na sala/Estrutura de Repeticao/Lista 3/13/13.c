/*Apresentar os múltiplos de 10 entre 1000 e 0 (ordem decrescente). Mostrar os valores
separados por uma marca de tabulação e em colunas com 8 números por linha.*/

# include <stdio.h>

int main(void)

{
    int i;

    for (i=1000;i>=0;i=i-10)
    {
        printf("%d\t|\t\t",i);
    }
}
