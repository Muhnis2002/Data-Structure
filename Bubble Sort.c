/* Muhammed Muhnis T K
   Bubble Sort
   JEC21CS083 */

#include <stdio.h>

// Function to read elements into the array
int read(int a[], int n) {
    for (int j = 0; j < n; ++j) {
        printf("Enter the %d th Element of the array : ", j + 1);
        scanf("%d", &a[j]);
    }
    return 0;
}

// Function to perform bubble sort on the array
int sort(int a[], int n) {
    int t;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j + 1] < a[j]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    printf("The Sorted array is : ");
    for (int j = 0; j < n; ++j) {
        printf("%d ", a[j]);
    }
    return 0;
}

int main() {
    int a[50], n;

    // Input the size of the array
    printf("Enter the limit of the array : ");
    scanf("%d", &n);

    // Read elements into the array
    read(a, n);

    // Perform bubble sort
    sort(a, n);

    return 0;
}

/*
OUTPUT:
Enter the limit of the array : 6
Enter the 1 th Element of the array : 34
Enter the 2 th Element of the array : 12
Enter the 3 th Element of the array : 56
Enter the 4 th Element of the array : 23
Enter the 5 th Element of the array : 8
Enter the 6 th Element of the array : 42
The Sorted array is : 8 12 23 34 42 56

OR

Enter the limit of the array : 5
Enter the 1 th Element of the array : 5
Enter the 2 th Element of the array : 18
Enter the 3 th Element of the array : 2
Enter the 4 th Element of the array : 9
Enter the 5 th Element of the array : 13
The Sorted array is : 2 5 9 13 18
*/


