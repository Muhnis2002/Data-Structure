
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
int read(struct poly  p[10])
{
	int n,i;
	printf("Enter the Number of terms in the Polynomial : ");
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		printf("Enter the Coefficient of %d th Term of the Polynomial : ",i+1);
		scanf("%d",&p[i].coeff);
		printf("Enter the  Exponent  of  %d th Term of the Polynomial : ",i+1);
		scanf("%d",&p[i].expo);
	}
	return n;
}
{
	int i;
	for(i=0;i<t-1;++i)
	{
		printf("%dx^%d + ",p[i].coeff,p[i].expo);
	}
	printf("%dx^%d\n",p[i].coeff,p[i].expo);
	return 0;
}
int add(struct poly k1[10],struct poly k2[10],int t1,int t2)
{
	int i=0,j=0,k=0;
	while(i<t1&&j<t2)
	{
		if(k1[i].expo==k2[j].expo)
		{
			p3[k].coeff=k1[i].coeff+k2[j++].coeff;
			p3[k++].expo=k1[i++].expo;
		}
		else if(k1[i].expo>k2[j].expo)
		{
			p3[k].coeff=k1[i].coeff;
			p3[k++].expo=k1[i++].expo;
		}
		else if(k2[j].expo>k1[i].expo)
		{
			p3[k].coeff=k2[j].coeff;
			p3[k++].expo=k2[j++].expo;
		}
	}
	while(i<t1)
	{
		p3[k].coeff=k1[i].coeff;
		p3[k++].expo=k1[i++].expo;
	}
	while(j<t2)
	{
		p3[k].coeff=k2[j].coeff;
		p3[k++].expo=k2[j++].expo;
	}
	printf("\nThe Sum of Entered Polynomials is : ");
	display(p3,k);
	return 0;
}
