#include <stdio.h>

void swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n)
{
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i+1);
        isSorted = 1; // elements are sorted -- when no element
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSorted = 0; // elements are not sorted
            }
        }

        if (isSorted)
        {
            return;
        }
    }
}

void arrTraversal (int *arr, int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main () {
    int arr[] = {2,4,5,7,8};
    // int arr[] = {2, 9, 4, 1, 12};
    int n = 5;

    arrTraversal(arr, n);
    bubbleSort (arr, n);
    arrTraversal (arr, n);

    
    return 0;
}