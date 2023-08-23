/* Muhammed Muhnis T K
   Linear Search
   JEC21CS083 */

#include <stdio.h>

// Function to read elements into the array
int read(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("Enter the %d th Element of the Array : ", i + 1);
        scanf("%d", &a[i]);
    }
    return 0;
}

// Function to perform linear search on the array
int search(int a[], int n, int x) {
    int i;
    for (i = 0; i < n; ++i) {
        if (a[i] == x) {
            n = -1;
            break;
        }
    }
    if (n == -1) {
        printf("The Element is Found at %d th location of the Array : ", i + 1);
    } else {
        printf("The Element is not Found in the Array");
    }
    return 0;
}

int main() {
    int a[100], n, x;

    // Input the size of the array
    printf("Enter the Limit of Array : ");
    scanf("%d", &n);

    // Read elements into the array
    read(a, n);

    // Input the element to be searched
    printf("Enter the Element to be Searched in the Array : ");
    scanf("%d", &x);

    // Perform linear search
    search(a, n, x);

    return 0;
}

/* 
OUTPUT:
Enter the Limit of Array : 5
Enter the 1 th Element of the Array : 10
Enter the 2 th Element of the Array : 20
Enter the 3 th Element of the Array : 30
Enter the 4 th Element of the Array : 40
Enter the 5 th Element of the Array : 50
Enter the Element to be Searched in the Array : 30
The Element is Found at 3 th location of the Array :

OR

Enter the Limit of Array : 4
Enter the 1 th Element of the Array : 7
Enter the 2 th Element of the Array : 18
Enter the 3 th Element of the Array : 25
Enter the 4 th Element of the Array : 32
Enter the Element to be Searched in the Array : 15
The Element is not Found in the Array
*/


