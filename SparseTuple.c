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