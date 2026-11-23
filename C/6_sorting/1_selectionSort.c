# include<stdio.h>

void selectionSort (int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j]) { 
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
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
    selectionSort(A, n);
    arrTraversal(A, n);

    return 0;
}