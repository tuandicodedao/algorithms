#include<stdio.h>
#include<conio.h>
int main (){
        int m,n;
        printf("nhap so hang: ");
        scanf("%d",&m);
        printf("nhap so cot: ");
        scanf("%d",&n);
        int matrix[m][n];
        // nhap ma tran
        printf("nhap cac phan tu cua ma tran: \n");
        for(int i=0;i<m;i++){
        	for(int j=0;j<n;j++){
        		printf("matrix[%d][%d]= ",i,j);
        		scanf("%d",&matrix[i][j]);
							}
		}
printf("Ma tran bua nhap la:\n");
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
		printf("%d",matrix[i][j]);
		
	}printf("\n");
}
return 0;




	}
	
	
	
	
