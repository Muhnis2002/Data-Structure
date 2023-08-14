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
int read(int a[50][50],int r,int c)
{
	int i,j;
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		{
			printf("Enter the  [%d][%d] th Element of the Matrix : ",i,j);
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
int tuple(int a[50][50],int r,int c,int tu[50][50])
{
	int i,j,k=1;
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		{
			if(a[i][j]!=0)
			{
				tu[k][0]=i;
				tu[k][1]=j;
				tu[k][2]=a[i][j];
				++k;				
			}
		}
	}
	tu[0][0]=r;
	tu[0][1]=c;
	tu[0][2]=k-1;
	return k;
}
int SparseAdd(int tua[50][50],int tub[50][50],int tuc[50][50])
{
	int m=1,n=1,k=1,i,j,r=tua[0][0],c=tua[0][1];
	tuc[0][0]=tua[0][0];
	tuc[0][1]=tua[0][1];
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		{
			if(((tua[m][0]==i)&&(tua[m][1]==j))&&((tub[n][0]==i)&&tub[n][1]==j))
			{
				tuc[k][0]=i;
				tuc[k][1]=j;
				tuc[k++][2]=tua[m++][2]+tub[n++][2];
			}
			else if((tua[m][0]==i)&&(tua[m][1]==j))
			{
				tuc[k][0]=i;
				tuc[k][1]=j;
				tuc[k++][2]=tua[m++][2];
			}
			else if((tub[n][0]==i)&&(tub[n][1]==j))
			{
				tuc[k][0]=i;
				tuc[k][1]=j;
				tuc[k++][2]=tub[n++][2];
			}
		}
	}
	tuc[0][2]=k-1;
	printf("\nThe Added Sparse Matrices is : \n");
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		{
			printf("%d  ",a[i][j]+b[i][j]);
		}
		printf("\n");
	}
	printf("\nThe Tuple Form of the Added Sparse Matrices is : \n");
	display(tuc,k,3);
	return 0;
}