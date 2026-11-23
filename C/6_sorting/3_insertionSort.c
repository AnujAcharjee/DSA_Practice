#include <stdio.h>

void insertionSort (int arr[], int n) {
    for(int i=1; i<n-1; i++) {
        int current = arr[i];
        int j = i-1;

        while (arr[j] > current && j>=0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }

}

void arrTraversal (int arr[], int n) {
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {12,45,23,51,8};
    int n = sizeof(A)/sizeof(A[0]);

    arrTraversal(A, n);
    insertionSort(A, n);
    arrTraversal(A, n);

    return 0;
}