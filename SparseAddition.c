#include<stdio.h>
int a[50][50],b[50][50];
int read(int s[50][50],int r,int c);
int display(int a[50][50],int r,int c);
int tuple(int a[50][50],int r,int c,int tu[50][50]);
int SparseAdd(int tua[50][50],int tub[50][50],int tuc[50][50]);
int main()
{
	int  r1,r2,c1,c2,tua[50][50],tub[50][50],tuc[50][50],f;
	printf("Enter  the  Number  of rows  in   the  1st   Matrix : ");
	scanf("%d",&r1);
	printf("Enter the  Number of  columns  in the 1st  Matrix   : ");
	scanf("%d",&c1);
	printf("Enter the Number of rows in the 2nd Sparse  Matrix  : ");
	scanf("%d",&r2);
	printf("Enter the Number of rows in the 2nd Sparse Matrix   : ");
	scanf("%d",&c2);
	if(r1==r2&&c1==c2)
	{
		printf("\nEnter the Elements in the 1st Sparse Matrix  \n");
		read(a,r1,c1);
		printf("\nThe Entered Sparse Matrix is : \n");
		display(a,r1,c1);
		f=tuple(a,r1,c1,tua);
		printf("\nThe Tuple Form of the Entered Sparse Matrix is : \n");
		display(tua,f,3);
		printf("\nEnter the Elements in the 2nd Sparse Matrix  \n");
		read(b,r2,c2);
		printf("\nThe Entered Sparse Matrix is : \n");
		display(b,r1,c1);
		f=tuple(b,r1,c1,tub);
		printf("\nThe Tuple Form of the Entered Sparse Matrix is : \n");
		display(tub,f,3);
		SparseAdd(tua,tub,tuc);
	}		
	else
	{
		printf("Matrix Addition is not Possible");
	}
	return 0;
}