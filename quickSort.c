#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int * arr, int l, int h){
	int pivot = arr[h];
	int i = (l-1);
	int temp;

	for(int j=l;j<=h-1;j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i+1);
}


void quickSort(int * arr, int l, int h){
	if(l<h){
		int pi = partition(arr, l , h);
		quickSort(arr, l, pi-1);
		quickSort(arr, pi+1, h);
	}
}

int main(){

	int vetor[100], size;
	int i;
	srand((unsigned)time(NULL));
	printf("Vetor: \n");
	for(i=0;i<100;i++){
		vetor[i] = rand()%1000;
		printf("%d ", vetor[i]);	
	}printf("\n\n");
	size = sizeof(vetor)/sizeof(vetor[0]);
	quickSort(vetor, 0, size-1);

	printf("\nVetor Ordenado: \n");
	for(i=0;i<100;i++) printf("%d ", vetor[i]);
	printf("\n");

	return 0;
}
