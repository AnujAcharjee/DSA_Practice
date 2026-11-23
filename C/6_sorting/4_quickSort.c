#include <stdio.h>

void swap(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition (int* a, int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot) {
            i++;
        }
        while (j >= low && a[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(a, i, j);
        }
    }
    swap(a, low, j);
    return j;
}

void quickSort (int *a, int low, int high) {
    if (low<high) {
        int partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex-1);
        quickSort(a, partitionIndex +1, high);
    }
}

void arrTraversal (int* a, int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {2,4,5,7,8,13,1}; 
    int n = sizeof(a)/sizeof(int);  //gives no. of elements

    arrTraversal (a, n);
    quickSort (a, 0, n-1);
    arrTraversal (a, n);

    return 0;
}