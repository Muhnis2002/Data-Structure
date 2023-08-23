/* Muhammed Muhnis T K
   Binary Search
   JEC21CS083 */

#include <stdio.h>

// Function to read elements into the array
int read(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("Enter the %d th Element of the array : ", i + 1);
        scanf("%d", &a[i]);
    }
    return 0;
}

// Function to sort the array using bubble sort
void sort(int a[], int n) {
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
    printf("The Sorted array for performing Binary Search is : ");
    for (int j = 0; j < n; ++j) {
        printf("%d ", a[j]);
    }
}

// Function to perform binary search on the sorted array
int search(int a[], int n, int x) {
    int i = 0, l = n - 1, mid;
    while (i <= l) {
        mid = (i + l) / 2;
        if (x == a[mid]) {
            i = -1;
            break;
        } else if (x < a[mid]) {
            l = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    if (i == -1) {
        printf("Element is found at Location %d th location of the array", mid + 1);
    } else {
        printf("Element is not found in the array");
    }
    return 0;
}

int main() {
    int a[100], n, x;

    // Input the size of the array
    printf("Enter the Limit of array : ");
    scanf("%d", &n);

    // Read elements into the array
    read(a, n);

    // Sort the array using bubble sort
    sort(a, n);
    
    printf("\n");

    // Input the element to be searched
    printf("Enter the Element to be searched in the array : ");
    scanf("%d", &x);

    // Perform binary search
    search(a, n, x);

    return 0;
}
