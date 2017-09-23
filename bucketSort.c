#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define S 10000

 typedef struct {
         int topo;
         int balde[100];
 }bucket;

void insertionSort (int * arr , int size);
void bucketSort(int * arr, int size);

int main(){

	int vetor[S], size;
	int i, j;
	clock_t c2, c1;
	long double tempo[20], media=0;
	
	srand((unsigned)time(NULL));
	
	printf ("Metodo: Bucket Sort\n");

	for (i = 0; i < 20; ++i){
		for(j=0;j<S;j++){
			vetor[j] = rand()%1000000;
			//printf("%d ", vetor[i]);	
		}//printf("\n");
		c1=clock(); //PEGA O CLOCK INICIAL DO PROCESSADOR
		bucketSort(vetor,S);
		c2=clock(); //CLOCK FINAL
		tempo[i] = (c2-c1)*1000.0/CLOCKS_PER_SEC;
		printf("Tempo vetor %d: %Lf\n",i+1,tempo[i]);
		media+=tempo[i];
	}
	media/=20;
	printf("Media: %LF\n", media);
	
	FILE * p;
	//SALVAR MEDIAS EM ARQUIVO
	p = fopen("tempo.txt", "a");
	for(i=0;i<20;i++)
		fprintf(p, "Tempo Vetor %d: %LF\n", i+1, tempo[i]);
	fprintf(p, "------------\nMedia: %LF\n", media);
	fclose(p);

	/*
	printf("\nVetor Ordenado: \n");
	for(i=0;i<S;i++) printf("%d ", vetor[i]);
	printf("\n");

	printf("\nTempo: %fms\n", tempo);
	*/

	return 0;
}
void insertionSort (int * arr , int size)
{

	/* 
	* Função de ordenação Insertion Sort
	* @param endereço do array
	* @param tamanho do array
	*/

	int temp;
	int iCount, jCount;

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

void bucketSort(int * arr, int size){
	bucket b[size];
	int i,j,k;
	int maior = 0;

	//SETA O TOPO DOS BALDES EM 0 E DESCOBRE O MAIOR
	for(i=0;i<size;i++){
		b[i].topo = 0;
		if(arr[i] > maior) maior = arr[i];
	}

	//VERIFICA EM QUE BALDE O ELEMENTO FICA
	for(i=0;i<size;i++){
		j=size-1;
		while(1){
			if(j<0) break;
			if((arr[i] > j*(maior/size) && (arr[i] <= (j+1)*(maior/size)))){
				b[j].balde[b[j].topo++] = arr[i];
				break;
			}
			j--;
		}
	}

	//ORDENAR OS BALDES
	for(i=0;i<size;i++)
		insertionSort(b[i].balde, b[i].topo);

	//VOLTAR OS ELEMENTOS PRO VETOR
	i=0;
	for(j=0;j<size;j++){
		for(k=0;k<b[j].topo;k++){
			arr[i++]=b[j].balde[k];
		}
	}	
}
