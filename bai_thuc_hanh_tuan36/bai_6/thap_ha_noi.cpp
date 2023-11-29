#include<stdio.h>
void towerOfHanoi(int n,char from,char to, char aux){
	if(n==1){
		printf("chuyen dai 1 tu coc %c sang coc %c\n",from, to);
		return;
		}
		towerOfHanoi(n-1,from,aux,to);
		printf("chuyen dia %d tu coc %c sang coc %c\n",n,from, to);
		 towerOfHanoi(n - 1, aux, to, from);
	}
int main() {
    int n;
    printf("Nhap so dia trong thap Hanoi: ");
    scanf("%d", &n);
    
    towerOfHanoi(n, 'A', 'C', 'B');
    
    return 0;
}
