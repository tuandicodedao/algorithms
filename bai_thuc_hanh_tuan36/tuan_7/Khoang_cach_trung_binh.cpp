#include<stdio.h>
float averageDistance(int arr[], int size){
	if(size == 0){
		return 0.0;
	}
	int sum=0;
	for(int i=0;i<size;i++){
		sum+=arr[i];
		
	}return (float)sum/size;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    float average = averageDistance(arr, size);
    printf("Khoang cach trung binh giua cac gia tri trong mang la: %.2f\n", average);

    return 0;
}
