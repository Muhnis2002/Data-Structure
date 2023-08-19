/*
 Muhammed Muhnis T K
 Quick Sort
 JEC21CS083
*/

#include<stdio.h>

// Function prototype for quicksort
void quicksort(int a[], int f, int l);

int main()
{
    int i, count, a[100];
    
    printf("Enter the limit : ");
    scanf("%d", &count);
    
    // Input array elements
    for(i = 0; i < count; ++i)
    {
        printf("Enter the %d th Element of the Array : ", i + 1);
        scanf("%d", &a[i]);
    }
    
    // Call quicksort function to sort the array
    quicksort(a, 0, count - 1);
    
    printf("The Sorted Array is : ");
    for(int m = 0; m < count; ++m)
    {
        printf("%d  ", a[m]);
    }
    
    return 0;
}

// Function to perform quicksort on an array
void quicksort(int a[], int f, int l)
{
    int i, j, piv, temp;
    
    piv = f; // Choose the pivot as the first element
    i = f;   // Initialize 'i' to the start of the subarray
    j = l;   // Initialize 'j' to the end of the subarray
    
    if(f < l)
    {
        // Partitioning step
        while(i < j)
        {
            // Move 'i' towards the right until finding an element larger than the pivot
            while(a[i] <= a[piv] && i < l)
            {
                i++;
            }
            
            // Move 'j' towards the left until finding an element smaller than the pivot
            while(a[j] > a[piv])
            {
                j--;
            }
            
            // Swap the elements at positions 'i' and 'j'
            if(i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        
        // Swap the pivot element with the element at position 'j'
        temp = a[piv];
        a[piv] = a[j];
        a[j] = temp;
        
        // Recursive calls for the two subarrays
        quicksort(a, f, j - 1);
        quicksort(a, j + 1, l);
    }
}
