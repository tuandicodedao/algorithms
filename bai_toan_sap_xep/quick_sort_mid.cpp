#include<stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm tìm ch? s? pivot và chia nh? m?ng
int partition(int arr[], int low, int high) {
    int pivot = arr[(low + high) / 2]; // Ch?n pivot ? gi?a m?ng
    int i = low - 1;
    int j = high + 1;
    
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

// Hàm s?p x?p QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex);
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
	
