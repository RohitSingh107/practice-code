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

int partition(int arr[], int low, int high){
	int pi = high/2;
	int pivot = arr[pi];
	int i = low, j = high;
	while(i<j){
		while(arr[i]<= pivot){
			i++;
		}
		while(arr[j]> pivot){
			j--;
		}

		if(i<j){
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[j], &arr[pi]);
	return j;
}

void merge(int a[], int lb, int mid, int ub){
	int b[ub+1];
	int i = lb, j = mid+1, k = lb;
	while(i <= mid && j <= ub){
		if(a[i] <= a[j]){
			b[k] = a[i];
			i++;
			k++;
		}
		else{
			b[k] = a[j];
			j++;
			k++;
		}
	}
	// while(i<=mid){
	// 	b[k] = a[i];
	// 	i++;
	// 	k++;
	// }
	
	// while(j<=ub){
	// 	b[k] = a[j];
	// 	j++;
	// 	k++;
	// }
	if(i>mid){
		while (j<=ub){
			b[k]= a[j];
			j++;
			k++;
		}
	}
	else{
		while(i<=mid){
			b[k] = a[i];
			i++;
			k++;
		}
	}
	for(int o = lb; o<=ub; o++){
		a[o] = b[o];
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



void quickSort(int arr[], int low, int high){
	if(low < high){
		int j = partition(arr, low, high);
		quickSort(arr, low, j-1);
		quickSort(arr, j+1, high);
	}
}

void mergeSort(int arr[], int lb, int ub){
	if(lb < ub){
		int mid = (lb+ub)/2;
		mergeSort(arr, lb, mid);
		mergeSort(arr, mid+1, ub);
		merge(arr, lb, mid, ub);
	}
}

int main(void){

	// int arr[] = {6,3,5,32,0,8,15,10,12,4,3};
	// int size = 11;

	// int arr[] = {9,8,7,6,5,4,3,2,1,0};
	// int size = 10;

	int arr[] = {0,1,9,3,4,0,6,7,8,9};
	int size = 10;

	// int arr[] = {5,3};
	// int size = 2;

	// int arr[] = {3};
	// int size = 1;

	// display(arr, size);
	// bubbleSort(arr, size);
	// display(arr, size);
	// insertionSort(arr, size);
	// display(arr, size);
	// selectionSort(arr, size);
	// display(arr, size);
	// partition(arr, 0, size -1);
	// quickSort(arr, 0, 9);
	// printf("j is %d, jth is %d\n", partition(arr, 0, size -1), arr[partition(arr, 0, size -1)]);


	display(arr, size);
	// mergeSort(arr, 0, size-1);
	mergeSort(arr, 0, size-1);
	display(arr, size);


	return 0;
}