// sap xep duyet qua tat ca cac phan tu 
#include<stdio.h>
void bubbleSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j+1]<arr[j]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
// do cac phan tu cang lon cang duoc day ve cuoi nen chi can duyet nhung 
// so chua duoc duyet nen i<n-1;j<n-i-1.
void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
		printf("\n");
	}
}
int main(){
	int arr[]={64,25,12,22,11};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr,n);
	printf("Mang da sap xep la: \n");
	printArray(arr,n);
	return 0;
}
