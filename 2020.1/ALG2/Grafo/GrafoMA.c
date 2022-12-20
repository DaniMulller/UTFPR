#include <stdio.h>
#include <stdlib.h>

typedef struct GrafoMA GrafoMA;

struct GrafoMA{
   int V; // número de vértices
   int A; // número de arestas
   int **mat;
};

static int** iniciar_MA(int n){
    int i, j;
    int **mat = (int**) malloc(n * sizeof(int*));

    for (i = 0; i < n; i++)
        mat[i] = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mat[i][j] = 0;

    return mat;
}


static int valida_vertice(GrafoMA* G, int v){
    return (v >= 0) && (v < G->V);
}


GrafoMA* iniciar_grafoMA(int v){
    GrafoMA* G = (GrafoMA*) malloc(sizeof(GrafoMA));

    G->V = v;
    G->A = 0;
    G->mat = iniciar_MA(G->V);

    return G;
}


int aresta_existe(GrafoMA* G, int v1, int v2){
    return (G != NULL) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->mat[v1][v2] == 1);
}


void inserir_aresta(GrafoMA* G, int v1, int v2){
    if ((G != NULL) && (valida_vertice(G, v1)) && (valida_vertice(G, v2)) && (!aresta_existe(G, v1, v2))){
        G->mat[v1][v2] = G->mat[v2][v1] = 1;
        G->A++;
    }
}

void remover_aresta(GrafoMA* G, int v1, int v2){
    if ((G != NULL) && (valida_vertice(G, v1)) && (valida_vertice(G, v2)) && (aresta_existe(G, v1, v2))){
        G->mat[v2][v1] = G->mat[v1][v2] = 0;
        G->A--;
    }
}

void imprimir_arestas(GrafoMA* G){
    for (int v = 0; v < G->V; ++v){
      for (int w = 0; w < G->V; ++w)
         if (G->mat[v][w] == 1)
            printf("(%d,%d)\n", v, w);
   }
}

void imprimeMatriz(GrafoMA* G){
  for(int i=0;i<G->V;i++){
    for(int j=0;j<G->V;j++){
      printf("%d ",G->mat[i][j]);
    }
    printf("\n");
  }
}


void liberarGMA(GrafoMA* G){
    if (G != NULL){
        free(G->mat);
        free(G);
    }
}

GrafoMA* transformaGMA(GrafoMA* G){
  int i,j;
  for(i=0;i<G->V;i++){
    for(j=0;j<G->V;j++){
      if(aresta_existe(G,i,j) && G->mat[j][i]!=1){
        G->mat[j][i]=1;
      }
    }
  }
  return G;
}

int verificaAdjacencia(GrafoMA* G,int v1,int v2){ //return = 1 se tem adjacencia
  if(aresta_existe(G,v1,v2)==1){
    return 1;
  }
  return 0;
}

void verificaLaco(GrafoMA* G){
  int i,aux=0;
  printf("Laco no vertice\n");
  for(i=0;i<G->V;i++){
    if(aresta_existe(G,i,i)==1){
      printf("%d\n",i);
      aux++;
    }
  }
  if(aux==0){
    printf("-\n");
  }
}

int grafoRegular(GrafoMA* G){ //return = 1 se regular
  int i,j,grau,aux=0;
  for(i=0;i<G->V;i++){
    grau=0;
    for(j=0;i<G->V;i++){
      if(aresta_existe(G,i,j)==1){
        grau++;
      }
    }
    if(grau!=aux && i!=0){
      return 0;
    }
    aux=grau;
  }
  return 1;
}

int busca(int v, int n, GrafoMA* gMA, int cor[n], int tempo, int descoberta[n]){
  int j;
  tempo = tempo + 1;
  descoberta[v] = tempo;
  for(j = 0; j < n; j++){
    if(gMA->mat[v][j]==1){
      if(cor==1) continue;
      if(cor[j] == 1 || (descoberta[v]  - descoberta[j]) > 2){
        return 1;
      }
      descoberta[j] = tempo;
      cor[j] = 1;
      busca(j, n, gMA, cor, tempo, descoberta);
    }
  }

  cor[v] = 0;
  return 0;
}

int verificaCiclico(GrafoMA* gMA,int n){
  // 0=preto, 1=cinza, 2=branco
  int i, cor[n],  descoberta[n], tempo=0;
  for(i=0;i<n;i++){
    cor[i] = 2;
    descoberta[i] = -1;
  }

  for(i=0;i<n;i++){
    if(cor[i]==0){
      return 0;
    }
    cor[i] = 1;
    if (busca(i, n, gMA, cor, tempo, descoberta) == 1){
      return 1;
    }
  }
  return 0;
}

int main(void) {
  int i, j, v;
  scanf(" %d",&v);

  GrafoMA* gMA = iniciar_grafoMA(v);

  for(i=0;i<v;i++){
    for(j=0;j<v;j++){
      inserir_aresta(gMA,i,j);
    }
  }

  if(verificaCiclico(gMA,v) == 1){
    printf("ciclico\n");
  }
  else{
    printf("aciclico\n");
  }

  return 0;
}
