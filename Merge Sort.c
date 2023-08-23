/* Muhammed Muhnis T K
   Sorting an array using Merge Sort Technique
   JEC21CS083 */

#include <stdio.h>

// Function to read elements into the array
int read(int a[], int l) {
    for (int i = 0; i < l; ++i) {
        printf("Enter the %d th Element of the array : ", i + 1);
        scanf("%d", &a[i]);
    }
    return 0;
}

// Function to print array elements
int print(int a[], int l) {
    for (int i = 0; i < l; ++i) {
        printf("%d  ", a[i]);
    }
    return 0;
}

// Function implementing the merge sort algorithm
int mergesort(int a[], int f, int l) {
    int m;
    if (f < l) {
        m = (f + l) / 2;
        mergesort(a, f, m);    // Sort the left half
        mergesort(a, m + 1, l);  // Sort the right half
        merge(a, f, m, l);      // Merge the sorted halves
    }
    return 0;
}

// Function to merge two subarrays
int merge(int a[], int f, int m, int l) {
    int i, j, k, b[25];
    for (i = f, j = m + 1, k = f; i <= m && j <= l; ++k) {
        if (a[i] <= a[j]) {
            b[k] = a[i++];
        } else {
            b[k] = a[j++];
        }
    }
    while (i <= m) {
        b[k++] = a[i++];
    }
    while (j <= l) {
        b[k++] = a[j++];
    }
    for (k = f; k <= l; ++k) {
        a[k] = b[k];
    }
    return 0;
}

int main() {
    int a[25], n;

    // Input the size of the array
    printf("Enter the limit of array : ");
    scanf("%d", &n);

    // Read elements into the array
    read(a, n);

    // Print the unsorted array
    printf("The Unsorted array is : ");
    print(a, n);

    // Apply merge sort
    mergesort(a, 0, n - 1);

    // Print the sorted array
    printf("\nThe Sorted array is : ");
    print(a, n);

    return 0;
}

/*
OUTPUT:
Enter the limit of array : 6
Enter the 1 th Element of the array : 45
Enter the 2 th Element of the array : 12
Enter the 3 th Element of the array : 78
Enter the 4 th Element of the array : 23
Enter the 5 th Element of the array : 56
Enter the 6 th Element of the array : 34
The Unsorted array is : 45  12  78  23  56  34
The Sorted array is : 12  23  34  45  56  78

OR

Enter the limit of array : 5
Enter the 1 th Element of the array : 5
Enter the 2 th Element of the array : 8
Enter the 3 th Element of the array : 1
Enter the 4 th Element of the array : 3
Enter the 5 th Element of the array : 7
The Unsorted array is : 5  8  1  3  7
The Sorted array is : 1  3  5  7  8
*/