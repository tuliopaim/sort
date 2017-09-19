#include <stdio.h>

void selectionSort (int * arr , int size)
{

	/* 
	* Função de ordenação Selection Sort
	* @param endereço do array
	* @param tamanho do array
	*/
	
	int min, temp;
	int iCount, jCount;

	printf("Metodo: Selection Sort\n");

	for (iCount = 0 ; iCount < size - 1 ; iCount++)
	{
		min = iCount;

		for (jCount = iCount + 1 ; jCount < size; jCount++)
		{
			if (arr[jCount] < arr[min])
				min = jCount;
		}
		
		if (min != iCount)
		{
			temp = arr[iCount];
			arr[iCount] = arr[min];
			arr[min] = temp;	
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
