#include<stdio.h>

void display(int arr[], int size){
	for(int i = 0; i< size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b){
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j]; 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void bubbleSort(int arr[], int size){
	printf("Sorting using BubbleSort ");
	int sorted;
	for(int i = 0; i< size-1; i++){
		sorted = 1;
		for(int j = 0; j< size - 1 - i; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j+1], &arr[j]);
				sorted = 0;
			}
		}
		if(sorted){
			break;
		}
	}
}

void insertionSort(int arr[], int n){
	printf("Sorting using InsertionSort ");

	for(int i = 1; i< n; i++){
		int j = i;
		int k = arr[j];
		while(arr[j-1] > k && j -1 >= 0){
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = k;
	}
}

void selectionSort(int arr[], int n){
	printf("Sorting using SelectionSort ");
	for(int i = 0; i<n-1; i++){
		int mi = i;
		for(int j = i+1; j<n; j++){
			if(arr[j] < arr[mi]){
				mi = j;
			}
		}
		swap(&arr[i], &arr[mi]);
	}
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(void){

	int a[] = {6,3,32,0,5,8,15,10,12,4};
	int b[] = {9,8,7,6,5,4,3,2,1,0};
	int c[] = {0,1,42,2,4,0,6,73,8,9};
	int d[] = {20,21,342,22,4,0,61,73,38,9};
	int e[] = {10,1,42,32,4,0,16,73,8,19};

	display(a, 10);
	bubbleSort(a, 10);
	display(a, 10);

	display(b, 10);
	insertionSort(b, 10);
	display(b, 10);

	display(c, 10);
	selectionSort(c, 10);
	display(c, 10);

	display(d, 10);
    printf("Sorting using quickSort ");
    quickSort(d, 0, 9);
	display(d, 10);

	display(e, 10);
    printf("Sorting using mergeSort ");
    mergeSort(e, 0, 9);
	display(e, 10);

	return 0;
}