#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "trabalho.h"

int main(void){
  FILE *fp;
  char arquivo[] = "trabalho.csv";
  fp = fopen(arquivo,"w+");

  //VETOR ALEATORIO

  fprintf(fp,"Vetor Aleatorio\n");
  fprintf(fp,"Teste\tItens\tBubble\tInsertion\tSelection\tMerge\tQuick\n");

  clock_t start_time, end_time, start_time_total, end_time_total;
  int n,aux;
  float t_total;
  int i=1;
  scanf("%d",&n);
  aux=n;

  start_time_total = clock();
  while(n<=50000){
      int v[n];
      int v2[n];
      gerar_vetor(v,n,10000);
      reseta_vetor(v,v2,n);

      start_time = clock();
      bubble_sort(v2,n);
      end_time = clock();
      float t_bubble = 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      reseta_vetor(v,v2,n);
      start_time = clock();
      insertion_sort(v2,n);
      end_time = clock();
      float t_insertion = 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      reseta_vetor(v,v2,n);
      start_time = clock();
      selection_sort(v2,n);
      end_time = clock();
      float t_selection = 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      reseta_vetor(v,v2,n);
      start_time = clock();
      quick_sort(v2,0,n);
      end_time = clock();
      float t_quick = 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      start_time = clock();
      merge_sort(v,0,n);
      end_time = clock();
      float t_merge= 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      fprintf(fp,"%d,%d,%.0f,%.0f,%.0f,%.0f,%.0f\n",i,n,t_bubble,t_insertion,t_selection,t_merge,t_quick);
      n = n+2500;
      i++;
  }
  end_time_total = clock();
  fprintf(fp,"\tTempo Total\t%.0ld seg\n",(end_time_total - start_time_total)/CLOCKS_PER_SEC);

  //VETOR CRESCENTE

  fprintf(fp,"\nVetor Crescente\n");
  fprintf(fp,"Teste\tItens\tBubble\tInsertion\tSelection\tMerge\tQuick\n");
  n=aux;
  i=1;
  start_time_total = clock();
  while(n<=50000){
      int v[n];
      gerar_vetor(v,n,10000);
      quick_sort(v,0,n);

      start_time = clock();
      bubble_sort(v,n);
      end_time = clock();
      float t_bubble = 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      start_time = clock();
      insertion_sort(v,n);
      end_time = clock();
      float t_insertion = 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      start_time = clock();
      selection_sort(v,n);
      end_time = clock();
      float t_selection = 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      start_time = clock();
      quick_sort(v,0,n);
      end_time = clock();
      float t_quick = 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      start_time = clock();
      merge_sort(v,0,n);
      end_time = clock();
      float t_merge= 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      fprintf(fp,"%d,%d,%.0f,%.0f,%.0f,%.0f,%.0f\n",i,n,t_bubble,t_insertion,t_selection,t_merge,t_quick);
      n = n+2500;
      i++;
  }
  end_time_total = clock();
  fprintf(fp,"\tTempo Total\t%.0ld seg\n",(end_time_total - start_time_total)/CLOCKS_PER_SEC);

  //VETOR DECRESCENTE

  fprintf(fp,"\nVetor Decrescente\n");
  fprintf(fp,"Teste\tItens\tBubble\tInsertion\tSelection\tMerge\tQuick\n");
  i=1;
  n=aux;
  start_time_total = clock();
  while(n<=50000){
      int v[n];
      int v2[n];
      gerar_vetor(v,n,10000);
      quick_sort(v,0,n);

      inverte_vetor(v,v2,n);
      start_time = clock();
      bubble_sort(v2,n);
      end_time = clock();
      float t_bubble = 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      inverte_vetor(v,v2,n);
      start_time = clock();
      insertion_sort(v2,n);
      end_time = clock();
      float t_insertion = 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      inverte_vetor(v,v2,n);
      start_time = clock();
      selection_sort(v2,n);
      end_time = clock();
      float t_selection = 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      inverte_vetor(v,v2,n);
      start_time = clock();
      quick_sort(v2,0,n);
      end_time = clock();
      float t_quick = 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      inverte_vetor(v,v2,n);
      merge_sort(v2,0,n);
      end_time = clock();
      float t_merge= 1000*(end_time - start_time)/CLOCKS_PER_SEC;

      fprintf(fp,"%d,%d,%.0f,%.0f,%.0f,%.0f,%.0f\n",i,n,t_bubble,t_insertion,t_selection,t_merge,t_quick);
      n = n+2500;
      i++;
  }
  end_time_total = clock();
  fprintf(fp,"\tTempo Total\t%.0ld seg\n",(end_time_total - start_time_total)/CLOCKS_PER_SEC);
  fclose(fp);
  return 0;
}
