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

	return ;
}


int main(){

	return 0;
}
