/*Escrever um algoritmo que lê a hora e os minutos de início e a hora e os minutos do final
do jogo e calcula a duração do jogo, sabendo-se que o tempo máximo de duração do jogo é
de 24 horas e que o jogo pode iniciar em um dia e terminar no dia seguinte.*/

# include <stdio.h>
int main(void)

{
    int hora_inicio, hora_final, minutos_inicio, minutos_final, duracao_int;
    float duracao, minutos;

    printf("Informe a hora de inicio: ");
    scanf("%d",&hora_inicio);
    printf("Informe os minutos de inicio: ");
    scanf("%d",&minutos_inicio);
    printf("Informe a hora de final: ");
    scanf("%d",&hora_final);
    printf("Informe os minutos de final: ");
    scanf("%d",&minutos_final);

    duracao = (float)(((hora_final*60)+minutos_final) - ((hora_inicio*60)+minutos_inicio))/60;
    duracao_int = duracao;
    minutos = (duracao-duracao_int)*100;

    printf("\nA duracao total do jogo foi de %.0f horas e %.0f minutos\n",duracao,minutos);
}
