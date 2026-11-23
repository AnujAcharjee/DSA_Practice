#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int val) {
    struct node *n = (struct node *) malloc(sizeof(struct node)); 
    if (n == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit the program if memory allocation fails
    }
    n->data = val; 
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrderTraversal(struct node *root) {
    if(root != NULL) {
        printf("%d ", root->data); 
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct node *root) {
    if(root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data); 
    }
}

void inOrderTraversal(struct node *root) {
    if(root != NULL) { 
        inOrderTraversal(root->left);
        printf("%d ", root->data); 
        inOrderTraversal(root->right);
    }
}

int main() {
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Preorder Traversal: ");
    preOrderTraversal(p);
    printf("\n");

    printf("Postorder Traversal: ");
    postOrderTraversal(p);
    printf("\n");

    printf("InOrder Traversal: ");
    inOrderTraversal(p);
    printf("\n");

    return 0; 
}
