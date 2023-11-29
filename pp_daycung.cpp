// chuong trinh giai phuong trinh bang phuon phap day cung
#include<stdio.h>
#include<math.h>
#include<conio.h>
#define EPSI 0.005
float Ham(float);
void main(){
float a,b,fa,fb,x,dx;
clrsc();
printf("\n\t\t\tPHUONG PHAP DAY CUNG GIAI HAM PHI TUYEN");
printf("\n\t\t\t HAM SO Y= EXP(-x)-x*x*x\n");
printf("Cho a="); scanf("%f",&a);
printf("Cho b="); scannf("%f",&b);
fa=Ham(a);
fb=Ham(b);
x=a;
dx=fa*(b-a)/(fa-fb);
while(abs(dx)>ESPI)
{
	x=a+dx;
	b=a;
	a=x;
	fb=fa;
	fa=Ham(x);
	dx=fa*(b-a)/(fa-fb);
	
	
	}printf("\n Ngiem x= %f",x);
	printf("Gia tri cua ham = %f", Ham(x));
	getch();
}float Ham(float x);{
	return (exp(x)+X*x*x);
	
	
	?

