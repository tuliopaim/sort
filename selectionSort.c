#include <stdio.h>

void selectionSort(int * vetor, int size){
	int temp;
	int i, j;
	for (i = 0; i < size; ++i){
		for (j = i+1; j < size; ++j){
			if(vetor[i] > vetor [j]){
				temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
}

int main(){

	int vetor[100];
	int i;
	srand((unsigned)time(NULL));
	printf("Vetor: \n");
	for(i=0;i<100;i++){
		vetor[i] = rand()%1000;
		printf("%d ", vetor[i]);	
	}

	selectionSort(vetor, 100);

	printf("\nVetor Ordenado: \n");
	for(i=0;i<100;i++) printf("%d ", vetor[i]);
	printf("\n");

	return 0;
}
