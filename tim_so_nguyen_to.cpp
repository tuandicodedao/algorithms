// Dung ham de kiem tra xem so do co phai so nguyen to hay ko
#include<stdio.h>
int isPrime(int number){
	if(number<= 1){
		return 0;
	}
	for(int i=2;i*i<=number;i++){
		if(number%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int number;
	printf("nhap so muon kien tra:");
	scanf("%d",&number);
	// neu chi goi ham ra thi mac dinh ve dau la dung, ve sau la sai
 if (isPrime(number)) {
        printf("%d la so nguyen to.\n", number);
    } else {
        printf("%d khong la so nguyen to.\n", number);
    }

    return 0;
}
