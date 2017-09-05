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

	return 0;
}
