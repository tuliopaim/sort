#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int * arr, int l, int m, int r){

	/* 
	* Função de ordenamento merge;
	* @param endereço do array
	* @param indice inicial do vetor
	* @param indice final do vetor
	*/

	int n1 = m - l + 1;
	int n2 = r- m;
	int i;

	int L[n1], R[n2];

	//PASSAR VETOR PARA ESQUERDA E DIREITA
	for(i=0;i<n1;i++)
		L[i] = arr[l+i];
	for(i=0;i<n2;i++)
		R[i] = arr[m+1+i];

	i = 0; //indice L[]
	int j = 0; //indice R[]
	int k = l; //indice arr[]

	//VERIFICAR O MAIOR E PASSAR PRO ARR
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	//ADD O QUE SOBRAR DOS VETORES
	while(i < n1){
		arr[k] = L[i];
		i++;k++;
	}

	while(j < n2){
		arr[k] = R[j];
		j++;k++;
	}
}

void mergeSort (int * arr , int l, int r){

	/* 
	* Função de quebra do vetor em 2 até size = 1;
	* @param endereço do array
	* @param indice inicial do vetor
	* @param indice final do vetor
	*/

	if(l<r){
		int m = l + (r-l)/2;

		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
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
	mergeSort(vetor, 0, size-1);

	printf("\nVetor Ordenado: \n");
	for(i=0;i<100;i++) printf("%d ", vetor[i]);
	printf("\n");

	return 0;
}
