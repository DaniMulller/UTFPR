#include <stdio.h>

int main void(){
  int i,j,k;
	unsigned long int Matriz[4][4] = {{ 0, 4, 8, 4294967295},
														 {4, 0, 1, 2},
														 {8, 4294967295, 0, 4},
														 {4294967295, 4294967295, 2, 7}};

  printf("Matriz Antes:\n");
 	for (i = 0; i < 4; i++){
 		for (j = 0; j < 4; j++){
 			printf(" %lu ", Matriz[i][j]);
 		}
 		printf("\n");
 	}
 	printf("\n");

 	for(i = 0; i < 4; i++){
 		for(j = 0; j < 4; j++){
 			for(k = 0; k < 4; k++){
 				if( matriz[j][k] > (matriz[j][i] + matriz[i][k]) )
 					matriz[j][k] = matriz[j][i] + matriz[i][k];
 			}
 		}
 	}

	// Mostra a matriz com os valores atualizados
	printf("Matriz Depois:\n");
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			if( Matriz[i][j] < 10 )
				printf(" %lu ", Matriz[i][j]);
			else
				printf("%lu ", Matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//printf("Total caminho mais curto do vertice 0 ao 3: %lu\n", Matriz[3][0]); // Matriz[destino] [origem]
	//printf("Total caminho mais curto do vertice 2 ao 3: %lu\n\n", Matriz[3][2]);

	// Mostra todos os caminhos
	printf("\n");
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			printf("Menor distancia saindo do %d para chegar ao %d = %lu.\n", i, j, Matriz[j][i]);
		}
	}
	printf("\n\n");

	return 0;
}
