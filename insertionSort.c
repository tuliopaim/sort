#include <stdio.h>
#include <time.h>

void insertionSort (int * arr , int size)
{

	/* 
	* Função de ordenação Insertion Sort
	* @param endereço do array
	* @param tamanho do array
	*/

	int temp;
	int iCount, jCount;

	printf("Metodo: Insertion Sort\n");

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

	insertionSort(vetor, 100);

	printf("\nVetor Ordenado: \n");
	for(i=0;i<100;i++) printf("%d ", vetor[i]);
	printf("\n");

	return 0;
}
