#include <stdio.h>

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

	return ;
}


int main(){

	return 0;
}
