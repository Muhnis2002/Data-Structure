/*Muhammed Muhnis T K
  Program to display the Tuple form of the Entered Sparse Matrix
  JEC21CS083*/
#include<stdio.h>
int read(int a[50][50],int r,int c);
int display(int a[50][50],int r,int c);
int tuple(int a[50][50],int r,int c,int tr[50][50]);
int main()
{
	int a[50][50],r,c,tr[50][50];
	printf("Enter the Number of Rows in  the  Sparse  Matrix : ");
	scanf("%d",&r);
	printf("Enter the Number of Columns in the Sparse Matrix : ");
	scanf("%d",&c);
	printf("\n");
	read(a,r,c);
	printf("\nThe Sparse Matrix is : \n");
	display(a,r,c);
	tuple(a,r,c,tr);
	return 0;
	
}
int read(int a[50][50],int r,int c)
{
	int i,j;
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		{
			printf("Enter the  [%d][%d] th Element of the Sparse Matrix : ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	return 0;
}
int display(int a[50][50],int r,int c)
{
	int i,j;
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int tuple(int a[50][50],int r,int c,int tr[50][50])
{
	int i,j,k=1;
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		{
			if(a[i][j]!=0)
			{
				tr[k][0]=i;
				tr[k][1]=j;
				tr[k][2]=a[i][j];
				++k;				
			}
		}
	}
	tr[0][0]=r;
	tr[0][1]=c;
	tr[0][2]=k-1;
	printf("\nThe Tuple Form is : \n");
	display(tr,k,3);
	return 0;
}