void merge(int * arr, int l, int m, int r);
void mergeSort (int * arr , int l, int r);
void bubbleSort (int * arr , int size);
void selectionSort(int * vetor, int size);
void insertionSort (int * arr , int size);
void swap(int* a, int* b);
int partition(int * arr, int l, int h);
void quickSort(int * arr, int l, int h);


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

void selectionSort(int * vetor, int size){
	int temp;
	int i, j;
	for (i = 0; i < size-1; ++i){
		for (j = i+1; j < size; ++j){
			if(vetor[i] > vetor [j]){
				temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}

}

void merge(int * arr, int l, int m, int r){

	/* 
	* Função de ordenamento merge;
	* @param endereço do array
	* @param indice inicial do vetor
	* @param indice final do vetor
	*/

	int n1 = m - l;
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
