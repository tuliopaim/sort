#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define RANGE 1000

int maior(int * arr, int size){
	int mx = arr[0];
	for(int i=0;i<size;i++)
		if(arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int * arr, int size, int exp){	
	int aux[size];
	int count[RANGE+1];
	int i;

	//ZERAR VETOR COUNT
	memset(count, 0, sizeof(count));

	//ARMAZENAR QUANTIDADE DE CADA NUMERO
	for(i=0;i<size;++i)
		count[(arr[i]/exp)%10]+=1;
	//SOMAR COM POSIÇÃO ANTERIOR PARA OBTER A POSICAO
	for(i=1;i<RANGE;++i)
		count[i]+=count[i-1];
	//COLOCAR OS NUMEROS EM ORDEM NO VETOR AUX 
	for(i=0;i<size;i++){
		aux[count[(arr[i]/exp)%10]-1] = arr[i];
		--count[(arr[i]/exp)%10];
	}
	//PASSAR PRO VETOR ORIGINAL ORDENADO
	for(i=0;i<size;++i)
		arr[i]=aux[i];
}

void radixSort(int * arr, int size){

	//ACHAR O VALOR MAXIMO DO VETOR
	int m = maior(arr, size);
	//FAZER O COUNTING PRA CADA DIGITO
	for(int exp=1; m/exp > 0; exp*=10)
		countSort(arr, size, exp);

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
	radixSort(vetor, 100);

	printf("\nVetor Ordenado: \n");
	for(i=0;i<100;i++) printf("%d ", vetor[i]);
	printf("\n");

	return 0;
}