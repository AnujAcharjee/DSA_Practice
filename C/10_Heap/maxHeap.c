#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *L;
    struct node *R;
} node;

// just create a empty node, directing nowhere
node* createNode (int data) {
    node *n = (node*)malloc(sizeof(node));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    n->data = data;
    n->L = NULL; 
    n->R = NULL;
    return n;
}

void swap (int *a, int *b) {
    int temp = *a;
   *a = *b;
    *b = temp;
}

node* insertLevelOrder(int *arr, node *root, int i, int n) {
    if (i < n) {
        node *temp = createNode (arr[i]);
        root = temp; // parent node

        // insert left child
        root->L = insertLevelOrder(arr, root->L, 2 * i + 1, n);

        // insert right child
        root->R = insertLevelOrder(arr, root->R, 2 * i + 2, n);
    }
    return root;
}

void maxHeapify (int* arr, int size, int i) {
    int largest = i;   //root node
    int Lchild = 2*i+1;
    int Rchild = 2*i+2; 

    // Compare with left child
    if (Lchild < size && arr[Lchild] > arr[largest]) {
        largest = Lchild;
    }
    // Compare with right child
    if (Rchild < size && arr[Rchild] > arr[largest]) {
        largest = Rchild;
    }
    
    // If the largest is not the root, swap and recursively heapify
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

void preOrderTraversal(struct node *root) {
    if(root != NULL) {
        printf("%d ", root->data); // Add a space after %d for formatting
        preOrderTraversal(root->L);
        preOrderTraversal(root->R);
    }
}

void arrTraversal (int *arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {1,3,5,4,6,13,10,9,8,15,17};
    int size = sizeof(arr)/ sizeof(int);
                            
    node *root = NULL;
    root = insertLevelOrder(arr, root, 0, size);

    printf("preOrder traversal: ");
    preOrderTraversal(root);
    printf("\n");

    maxHeapify(arr, size, 0);

    printf("traversal after heapify: ");
    arrTraversal(arr, size);
    printf("\n");
    printf("preOrder traversal of maxHeap: ");
    preOrderTraversal(root);

    return 0;
}
