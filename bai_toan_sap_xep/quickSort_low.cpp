#include<stdio.h>
// H�m ho�n d?i hai ph?n t?
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// H�m chia nh? m?ng v� d?t pivot v�o d�ng v? tr�
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Ch?n pivot l� ph?n t? d?u ti�n
    int i = low + 1;
    int j = high;
    
    while (true) {
        while (i <= j && arr[i] <= pivot)
            i++;
        while (i <= j && arr[j] > pivot)
            j--;
        
        if (i <= j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }
    
    // �?t pivot v�o v? tr� d�ng
    swap(&arr[low], &arr[j]);
    
    // Tr? v? ch? s? pivot
    return j;
}

// H�m s?p x?p QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        
        // S?p x?p hai ph?n m?ng con tr�i v� ph?i c?a pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
	void printArray(int arr[],int size){
		int i;
		for(i=0;i<size;i++){
			printf("%d",arr[i]);
			printf("\n");
			
		}
	}
	int main(){
			int arr[]={10,7,8,9,1,5};
		int n=sizeof(arr)/sizeof(arr[0]);
		quickSort(arr,0,n-1);
		printf("sorted arr: \n");
		printArray(arr,n);
		return 0;
	}
