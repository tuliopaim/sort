#include <stdio.h>

void bubbleSort (int * arr , int size)
{

	/* 
	* Função de ordenação Bubble Sort
	* @param endereço do array
	* @param tamanho do array
	*/

	int temp;
	int iCount, jCount;	
	char swapped;

	printf ("Metodo: Bubble Sort\n");

	for (iCount = 0 ; iCount < size ; iCount++)
	{
		swapped = 'F';
		for (jCount = 0 ; jCount < size - 1 ; jCount++)
		{
			if (arr[jCount] > arr[jCount + 1])
			{
			temp = arr[jCount + 1];
			arr[jCount + 1] = arr[jCount];
			arr[jCount] = temp;
			swapped = 'V';	
			}
		}
		if (swapped == 'F')
			break;
	}

	return ;
}

int main(){

	return 0;
}
