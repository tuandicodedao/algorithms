// tim trong so trong mang da dung nhanh hon 
#include<stdio.h>
int main(){
	int a[]={-2, 11, -4, 13, -5, 2};
	int n=sizeof(a)/sizeof(a[0]);
	int maxSum=0;
	for(int i=0;i<n;i++){
		int Sum=0;
		for (int j=i;j<n;j++){
			Sum+=a[j];
			if(Sum>maxSum){
				maxSum=Sum;
			}
		}
	}
	printf("trong so lon nhat la %d",maxSum);
	return 0;
	}
	// dau tien cho i=0 thi j =0 sum=a[0]
	// sau khi chayj xong vong lap 2 thi j tang them 1 
	// i van bang 0 va j=1 va sum=a[0]=a[1] tuong tu cho den khi n-1 thi nhay ra vong lap 2
	// i se tang len 1 va chay den khi het vong lap
	
