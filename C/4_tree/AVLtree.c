#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
} node;

int getHeight (node *n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

node *createNode (int data) {
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;

    return n;
}

int maxHeight (int a, int b) {
    return (a > b) ? a : b;
}

node *leftRotate (node *x) {
    node *y = x->right;
    node *t2 = y->left;

    // Perform rotation
    y->left = x;    // ie, y->left = x->right
    x->right = t2;  // x->right = y->left

    // Update heights
    x->height = maxHeight(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxHeight(getHeight(y->right), getHeight(y->left)) + 1;

    return y;  //not x - we all ready made change at address of x
}

node *rightRotate (node *y) {
    node *x = y->right;
    node *t2 = x->left;

    x->left = y;    
    y->right = t2;  

    x->height = maxHeight(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxHeight(getHeight(y->right), getHeight(y->left)) + 1;

    return x;  
}

int balanceFactor (node *n) {
    if(n==NULL){
        return 0;
    }
    return getHeight(n->right) - getHeight(n->left);
} 

node *insert (node *root, int data) {
    // Perform standard BST insertion
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        // Duplicate keys are not allowed in AVL trees (ie, root->data = data)
        return root;
    }
   
    root->height = maxHeight(getHeight(root->left), getHeight(root->right)) + 1;

    int BF = balanceFactor(root);

    //L-L insertion
    if (BF > 1 && data < root->left->data) {
        return rightRotate(root);
    }
    //R-R insertion
    if (BF < -1 && data > root->right->data) {
        return leftRotate(root);
    }
    //L-R insertion
    if(BF > 1 && data > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //R-L insertion
    if(BF < -1 && data < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void preOrder(node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}




int main () {
    node *root = NULL;
 
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    printf("Preorder traversal of AVL tree: ");
    preOrder(root);

    return 0;
}