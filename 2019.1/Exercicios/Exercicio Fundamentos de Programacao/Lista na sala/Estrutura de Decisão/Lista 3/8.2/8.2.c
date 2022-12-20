/* Considera-se o problema de esperar para jantar em um restaurante. O objetivo é o
algoritmo aprender a definição para DeveEsperar. Os atributos disponíveis para
descrever exemplos de possíveis casos do domínio são: alternar de restaurante, ir para um
bar, dia sa semana, estar com fome, número de fregueses, clima, se foi feita reserva,
estimativa de espera. Implemente um algoritmo para a árvore de decisão da Figura a
seguir. As entradas são do tipo char, exceto o tempo de espera que pode ser int. Portanto,
estabeleça uma letra para cada entrada esperada, por exemplo 'S' para sim, 'N' para não.*/

# include <stdio.h>

int main(void)

{
    char fregueses;

    printf("Informe se nao tem nenhum, alguns clientes ou cheio(n/a/c): ");
    scanf("%c",&fregueses);

    if (fregueses == 'n')
    {
        printf("\nNao precisa esperar!\n");
    }
    else if (fregueses == 'a')
    {
        printf("\nDeve esperar!\n");
    }
    else if (fregueses == 'c')
    {
        int espera;
        printf("\nInforme o tempo de espera: ");
        fflush(stdin);
        scanf("%d",&espera);

        if  (espera > 60)
        {
            printf("\nNao deve esperar!\n");
        }
        else  if (espera <= 60 && espera > 30)
        {
            char restaurante;
            printf("\nDeseja trocar de restaurante?(s/n): ");
            fflush(stdin);
            scanf("%c",&restaurante);

            if (restaurante == 's')
            {
                char dia;
                printf("\nInforme se e sabado ou sexta(s -> sab/x -> sex): ");
                fflush(stdin);
                scanf("%c",&dia);

                if (dia == 's')
                {
                    printf("\nDeve esperar!\n");
                }
                else if (dia == 'x')
                {
                    printf("\nNao deve esperar!\n");
                }
                else
                {
                    printf("\nInforme um caracter valido!\n");
                }
            }
            else
            {
                char reserva;
                printf("\nTem reserva?(s/n): ");
                fflush(stdin);
                scanf("%c",&reserva);

                if (reserva == 's')
                {
                    printf("\nDeve esperar!\n");
                }
                else
                {
                    char bar;
                    printf("\nDeseja ir a um bar?(s/n): ");
                    fflush(stdin);
                    scanf("%c",&bar);

                    if (bar == 's')
                    {
                        printf("\nNao deve esperar!\n");
                    }
                    else (bar == 'n');
                    {
                        printf("\nDeve esperar!\n");
                    }
                }
            }
        }
        else if (espera <= 30 && espera >10)
        {
            char fome;
            printf("\nEsta com fome?(s/n): ");
            fflush(stdin);
            scanf("%c",&fome);

            if (fome == 's')
            {
                printf("\nDeve esperar!\n");
            }
            else (fome == 'n');
            {
                char trocar;
                printf("\nDeseja trocar de restaurante?(s/n): ");
                fflush(stdin);
                scanf("%c",&trocar);

                if (trocar == 's')
                {
                    char chovendo;
                    printf("\nEsta chovendo?(s/n): ");
                    fflush(stdin);
                    scanf("%c",&chovendo);

                    if (chovendo == 's')
                    {
                        printf("\nDeve esperar!\n");
                    }
                    else
                    {
                        printf("\nNao deve esperar!\n");
                    }
                }
                else
                {
                    printf("\nDeve esperar!\n");
                }
            }
        }
        else
        {
            printf("\nDeve esperar!\n");
        }

    }
    else
    {
        printf("\nInforme um caracter valido!\n");
    }
}
