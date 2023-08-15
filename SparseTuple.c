/*Muhammed Muhnis T K
  Program to display the Tuple form of the Entered Sparse Matrix
  JEC21CS083*/
#include<stdio.h>

// Function prototypes
int read(int a[50][50], int r, int c);
int display(int a[50][50], int r, int c);
int tuple(int a[50][50], int r, int c, int tr[50][50]);

int main()
{
    int a[50][50], r, c, tr[50][50];
    
    // Input the number of rows and columns of the sparse matrix
    printf("Enter the Number of Rows in the Sparse Matrix: ");
    scanf("%d", &r);
    printf("Enter the Number of Columns in the Sparse Matrix: ");
    scanf("%d", &c);
    printf("\n");
    
    // Read the values of the sparse matrix
    read(a, r, c);
    
    printf("\nThe Sparse Matrix is:\n");
    // Display the entered sparse matrix
    display(a, r, c);
    
    // Convert the sparse matrix to tuple form
    tuple(a, r, c, tr);
    
    return 0;
}

// Function to read values into the sparse matrix
int read(int a[50][50], int r, int c)
{
    int i, j;
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            printf("Enter the [%d][%d] th Element of the Sparse Matrix: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    return 0;
}

// Function to display the sparse matrix
int display(int a[50][50], int r, int c)
{
    int i, j;
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Function to convert the sparse matrix to tuple form
int tuple(int a[50][50], int r, int c, int tr[50][50])
{
    int i, j, k = 1;
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            if (a[i][j] != 0)
            {
                tr[k][0] = i;
                tr[k][1] = j;
                tr[k][2] = a[i][j];
                ++k;
            }
        }
    }
    tr[0][0] = r;
    tr[0][1] = c;
    tr[0][2] = k - 1;
    printf("\nThe Tuple Form is:\n");
    // Display the tuple form
    display(tr, k, 3);
    return 0;
}
/* 

OUTPUT:
Enter the Number of Rows in the Sparse Matrix: 3
Enter the Number of Columns in the Sparse Matrix: 4

Enter the [0][0] th Element of the Sparse Matrix: 0
Enter the [0][1] th Element of the Sparse Matrix: 0
Enter the [0][2] th Element of the Sparse Matrix: 1
Enter the [0][3] th Element of the Sparse Matrix: 0
Enter the [1][0] th Element of the Sparse Matrix: 0
Enter the [1][1] th Element of the Sparse Matrix: 2
Enter the [1][2] th Element of the Sparse Matrix: 0
Enter the [1][3] th Element of the Sparse Matrix: 0
Enter the [2][0] th Element of the Sparse Matrix: 3
Enter the [2][1] th Element of the Sparse Matrix: 0
Enter the [2][2] th Element of the Sparse Matrix: 0
Enter the [2][3] th Element of the Sparse Matrix: 4

The Sparse Matrix is:
0  0  1  0
0  2  0  0
3  0  0  4

The Tuple Form is:
3  4  5
0  2  1
1  1  2
2  0  3
2  3  4
*/

