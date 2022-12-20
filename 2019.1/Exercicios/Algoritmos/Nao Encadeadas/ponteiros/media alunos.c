
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct aluno_t aluno_t;
struct aluno_t{
    int cod;
    char nome[255];
    float notas[3];
    float media;
};

void calculaMedia(aluno_t aluno[], int n){
    int i;
    for(i=0;i<n;i++){
        aluno[i].media = (aluno[i].notas[0]+aluno[i].notas[1]+aluno[i].notas[2])/3;
        if(aluno[i].media>=6)
            printf("Aprovado!\n");
        else
            printf("Reprovado!\n");
}

int encontraMaiorMedia(aluno_t aluno[], int n){
    float maior=0;
    int i, ind;
    for(i=0;i<n;i++){
        if(aluno[i].media>maior){
            maior = aluno[i].media;
            ind = i;
        }
    }
    return ind;
}

int encontraMenorMedia(aluno_t aluno[], int n){
    float menor=11;
    int i,ind;
    for(i=0;i<n;i++){
        if(aluno[i].media<menor){
            menor = aluno[i].media;
            ind = i;
        }
    }
    return ind;
}

int encontraMaiorP1(aluno_t aluno[], int n){
    float maior_P1=0;
    int i,ind;
    for(i=1;i<n;i++){
        if(aluno[i].notas[0]>maior_P1){
            maior_P1 = aluno[i].notas[0];
            ind = i;
        }
    }
    return ind;
}

int main(){
    int n,i;
    scanf("%d",&n);
    aluno_t aluno[n];
    for(i=0;i<n;i++){
        scanf("%d",&aluno[i].cod);
        scanf(" %s",aluno[i].nome);
        scanf("%f %f %f",&aluno[i].notas[0],&aluno[i].notas[1],&aluno[i].notas[2]);
    }
    printf("O aluno com maior media e: %d %s %.1f\n",aluno[encontraMaiorMedia(aluno,n)].cod,aluno[encontraMaiorMedia(aluno,n)].nome,aluno[encontraMaiorMedia(aluno,n)].media);

    printf("O aluno com menor media e: %d %s %.1f\n",aluno[encontraMenorMedia(aluno,n)].cod,aluno[encontraMenorMedia(aluno,n)].nome,aluno[encontraMenorMedia(aluno,n)].media);

    printf("O aluno com maior P1 e: %d %s %.1f\n",aluno[encontraMaiorP1(aluno,n)].cod,aluno[encontraMaiorP1(aluno,n)].nome,aluno[encontraMaiorP1(aluno,n)].notas[0]);
    return 0;
}
