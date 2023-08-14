
/*Muhammed Muhnis T K
  c-Program to Add 2 Polynomials
  JEC21CS083*/
#include<stdio.h>
struct poly
{
	int coeff;
	int expo;
}p1[10],p2[10],p3[10];
int read(struct poly p[10]);
int display(struct poly p[10],int t1);
int add(struct poly k1[10],struct poly k2[10],int t1,int t2);
int main()
{
	int t1,t2;
	printf("Enter the 1st Polynomial \n");
	t1=read(p1);
	printf("The Entered Polynomial is : ");
	display(p1,t1);
	printf("\nEnter the 2nd Polynomial\n");
	t2=read(p2);
	printf("The Entered Polynomial is : ");
	display(p2,t2);
	add(p1,p2,t1,t2);
	return 0;	
}