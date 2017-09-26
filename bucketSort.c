#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define S 25

void insertionSort (int * arr , int size)
{

	/* 
	* Função de ordenação Insertion Sort
	* @param endereço do array
	* @param tamanho do array
	*/

	int temp;
	int iCount, jCount;

	for (iCount = 1 ; iCount < size ; iCount++)
	{
		temp = arr[iCount];
		jCount = iCount - 1;
		while (jCount >= 0 && arr[jCount] > temp)
		{
			arr[jCount + 1] = arr[jCount];
			jCount--;
		}	
		arr[jCount + 1] = temp;
	}

	return ;
}

void bucketSort(int * arr, int size, int qnt_baldes){
	int i,j,k;
	int min = arr[0], max = arr[0];
	int *balde[qnt_baldes], qntNumeroBalde[qnt_baldes], alocadosBalde[qnt_baldes];
	int tamanhoBalde = 0;
	for (int i = 0; i < qnt_baldes; ++i){
		alocadosBalde[i] = 1;
		qntNumeroBalde[i] = 0;
		balde[i] = malloc(sizeof(int) * alocadosBalde[i]);
	}

	for (int i = 0; i < size; ++i){
		min = min < arr[i] ? min : arr[i];
		max = max > arr[i] ? max : arr[i];
	}

	tamanhoBalde = ((max - min) / (float)qnt_baldes) + 0.5f;

	for(int i = 0; i < size; ++i){
		for (int j = 0; j < qnt_baldes; ++j){
			if(min + (tamanhoBalde * (j + 1)) - 1 < arr[i] && j + 1 < qnt_baldes) continue;
			if(alocadosBalde[j] <= qntNumeroBalde[j]){
				alocadosBalde[j] *= 2;
				balde[j] = realloc(balde[j], sizeof(int) * alocadosBalde[j]);
			}
			balde[j][qntNumeroBalde[j]++] = arr[i];
			break;
		}
	}


	k = 0; // Posição no Array final
	for (int i = 0; i < qnt_baldes; ++i){
		insertionSort(balde[i], qntNumeroBalde[i]);
		for (int j = 0; j < qntNumeroBalde[i]; ++j){
			arr[k++] = balde[i][j];
		}
	}
}


int main(){

	int vetor[S], size;
	int i;
	clock_t c2, c1;
	double tempo;	

	srand((unsigned)time(NULL));
	
	printf ("Metodo: Bucket Sort\n");

	printf("Vetor: \n");
	for(i=0;i<S;i++){
		vetor[i] = rand()%1000;
		printf("%d ", vetor[i]);	
	}printf("\n");

	c1=clock();
	bucketSort(vetor, S, 250);
	c2=clock();
	tempo = (c2-c1)*1000.0/CLOCKS_PER_SEC;	

	printf("\nVetor Ordenado: \n");
	for(i=0;i<S;i++) printf("%d ", vetor[i]);
	printf("\n");

	printf("\nTempo: %fms\n", tempo);

	return 0;
}
