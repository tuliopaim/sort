#include <stdio.h>
#include <time.h>

void bubbleSort (int * arr , int size)
{

	/* 
	* Função de ordenação Bubble Sort
	* @param endereço do array
	* @param tamanho do array
	*/

	int temp;
	int iCount, jCount;	

	printf ("Metodo: Bubble Sort\n");

	for (iCount = 0 ; iCount < size ; iCount++)
	{
		for (jCount = 0 ; jCount < size - iCount - 1 ; jCount++)
		{
			if (arr[jCount] > arr[jCount + 1])
			{
			temp = arr[jCount + 1];
			arr[jCount + 1] = arr[jCount];
			arr[jCount] = temp;	
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

	mergeSort(vetor, 100);

	printf("\nVetor Ordenado: \n");
	for(i=0;i<100;i++) printf("%d ", vetor[i]);
	printf("\n");

	return 0;
}
