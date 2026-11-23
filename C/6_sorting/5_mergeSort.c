# include <stdio.h>

void swap(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void merge (int *a, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[ + 1];
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