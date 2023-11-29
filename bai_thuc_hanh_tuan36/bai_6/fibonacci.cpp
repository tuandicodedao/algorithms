#include<stdio.h>
int fibonacci(int n){
	if(n<=1){
		return n;
	}
	return fibonacci(n-1)+fibonacci(n-2);
	}
	int main(){
		int n;
		printf("nhap so thu tu cua so fibonacci: ");
		scanf("%d",&n);
		int result=fibonacci(n);
		printf("so fibonacci tai vi tri %d la: %d\n",n,result);
		return 0;
	}
