#include<stdio.h>
int a[50][50],b[50][50]; // Declare two arrays to store the input matrices
int read(int s[50][50],int r,int c); // Function to read matrix elements
int display(int a[50][50],int r,int c); // Function to display matrix elements
int tuple(int a[50][50],int r,int c,int tu[50][50]); // Convert matrix to tuple format
int SparseAdd(int tua[50][50],int tub[50][50],int tuc[50][50]); // Function to add sparse matrices

int main()
{
	int  r1,r2,c1,c2,tua[50][50],tub[50][50],tuc[50][50],f;
	printf("Enter  the  Number  of rows  in   the  1st   Matrix : ");
	scanf("%d",&r1);
	printf("Enter the  Number of  columns  in the 1st  Matrix   : ");
	scanf("%d",&c1);
	printf("Enter the Number of rows in the 2nd Sparse  Matrix  : ");
	scanf("%d",&r2);
	printf("Enter the Number of columns in the 2nd Sparse Matrix   : ");
	scanf("%d",&c2);
	if(r1==r2 && c1==c2)
	{
		printf("\nEnter the Elements in the 1st Sparse Matrix  \n");
		read(a,r1,c1); // Read elements of the first matrix
		printf("\nThe Entered Sparse Matrix is : \n");
		display(a,r1,c1); // Display the entered matrix
		f = tuple(a,r1,c1,tua); // Convert matrix to tuple
		printf("\nThe Tuple Form of the Entered Sparse Matrix is : \n");
		display(tua,f,3); // Display tuple form
		printf("\nEnter the Elements in the 2nd Sparse Matrix  \n");
		read(b,r2,c2); // Read elements of the second matrix
		printf("\nThe Entered Sparse Matrix is : \n");
		display(b,r1,c1); // Display the entered matrix
		f = tuple(b,r1,c1,tub); // Convert matrix to tuple
		printf("\nThe Tuple Form of the Entered Sparse Matrix is : \n");
		display(tub,f,3); // Display tuple form
		SparseAdd(tua,tub,tuc); // Add the two sparse matrices
	}		
	else
	{
		printf("Matrix Addition is not Possible");
	}
	return 0;
}

// Function to read matrix elements
int read(int a[50][50],int r,int c)
{
	// Read each element of the matrix
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

// Function to display matrix elements
int display(int a[50][50],int r,int c)
{
	// Display each element of the matrix
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

// Function to convert matrix to tuple format
int tuple(int a[50][50],int r,int c,int tu[50][50])
{
	// Convert matrix to tuple
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

// Function to add two sparse matrices
int SparseAdd(int tua[50][50],int tub[50][50],int tuc[50][50])
{
	// Add two sparse matrices represented in tuple format
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
			printf("%d  ",a[i][j]+b[i][j]); // Output of matrix addition
		}
		printf("\n");
	}
	printf("\nThe Tuple Form of the Added Sparse Matrices is : \n");
	display(tuc,k,3); // Display tuple form of the added matrix
	return 0;
}


/*
OUTPUT:
Enter the Number of rows in the 1st Matrix : 3
Enter the Number of columns in the 1st Matrix : 3
Enter the Number of rows in the 2nd Sparse Matrix : 3
Enter the Number of columns in the 2nd Sparse Matrix : 3

Enter the Elements in the 1st Sparse Matrix
Enter the [0][0] th Element of the Matrix : 1
Enter the [0][1] th Element of the Matrix : 0
Enter the [0][2] th Element of the Matrix : 0
Enter the [1][0] th Element of the Matrix : 0
Enter the [1][1] th Element of the Matrix : 0
Enter the [1][2] th Element of the Matrix : 2
Enter the [2][0] th Element of the Matrix : 0
Enter the [2][1] th Element of the Matrix : 3
Enter the [2][2] th Element of the Matrix : 0

The Entered Sparse Matrix is :
1 0 0
0 0 2
0 3 0

The Tuple Form of the Entered Sparse Matrix is :
3 3 4
0 0 1
1 2 2
2 1 3

Enter the Elements in the 2nd Sparse Matrix
Enter the [0][0] th Element of the Matrix : 0
Enter the [0][1] th Element of the Matrix : 0
Enter the [0][2] th Element of the Matrix : 0
Enter the [1][0] th Element of the Matrix : 0
Enter the [1][1] th Element of the Matrix : 0
Enter the [1][2] th Element of the Matrix : 0
Enter the [2][0] th Element of the Matrix : 0
Enter the [2][1] th Element of the Matrix : 0
Enter the [2][2] th Element of the Matrix : 0

The Entered Sparse Matrix is :
0 0 0
0 0 0
0 0 0

The Tuple Form of the Entered Sparse Matrix is :
3 3 1
0 0 0

The Added Sparse Matrices is :
1 0 0
0 0 2
0 3 0

The Tuple Form of the Added Sparse Matrices is :
3 3 4
0 0 1
1 2 2
2 1 3
*/
