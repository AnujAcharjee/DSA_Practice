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

void inOrderTraversal(struct node *root) {
    if(root != NULL) { 
        inOrderTraversal(root->left);
        printf("%d ", root->data); // Add a space after %d for formatting
        inOrderTraversal(root->right);
    }
}

int isBST (struct node *root) {
    static struct node *prev = NULL;
    if (root != NULL) {
        if (!isBST(root->left)) {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else {
        return 1;
    }
}

struct node* search (struct node *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        return root;
    }
    else if (root->data > key) {
        return (search(root->left, key));
    }  
    else {
        return (search(root->right, key));
    }
}

struct node* searchIter (struct node *root, int key) {
    while (root != NULL) {
        if (root->data == key) {
            return root;
        }
        else if (root->data > key) {
            root = root->left;       //updates root to left of main root
        }
        else {
            root = root->right;     //updates root to right of main root
        }
    }
    return NULL;
}

void insert (struct node* root, int val) {
    struct node *prev = NULL;
    while (root != NULL) {
        prev = root;
        if (root->data == val) {
            printf("Cannot insert %d, already in BST", val);
            return;
        }
        else if (root->data > val) {
            root = root->left;       //updates root to left of main root
        }
        else {
            root = root->right;     //updates root to right of main root
        }
    }
    struct node *new = createNode(val);
    if (prev->data > val) {
        prev->left = new;
    }
    else {
        prev->right = new;
    }
}

struct node *inOrderPredecessor(struct node* root){
    root = root->left;            // Move to the left child
    while (root->right != NULL)   // Traverse to the rightmost node
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value){
    //root node is NULL
    if (root == NULL){
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){                               //as value less than root then it will be at left node only 
        root->left = deleteNode(root->left,value);        // recursively using delete func. for left subtree
    }
    else if (value > root->data){                        // value greater than root- it will be at right subtree
        root->right = deleteNode(root->right,value);    // recursively using delete func. for right subtree
    }
    
    //deletion strategy when the node is found
    else {
        // Case 1: Node has no children or only one child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 2: Node has two children
        else {
        struct node *iPre = inOrderPredecessor(root);  // will get the IOP node
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);  // delete the IOP node - if it has branches same fun. will work on it
        }
    }
    return root;
}




int main() {
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(10);

    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \   \
    //  1   4   10
    //           \ (after insertion)
    //           16


    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    printf("InOrder Traversal: ");
    inOrderTraversal(p);

    printf("\n");
    
    if(isBST(p)){
        printf("This is a BST \n" );
    }
    else{
        printf("This is not a BST \n");
    }

    struct node* n = search(p, 4);
    if(n!=NULL){
    printf("Found: %d \n", n->data);
    }
    else{
        printf("Element not found \n");
    }

    struct node *n1 = searchIter(p, 6);
    if(n1 != NULL){
    printf("Found: %d \n", n1->data);
    }
    else{
        printf("Element not found \n");
    }

    insert(p, 16);
    printf("Inserted data : %d \n", p->right->right->right->data);

    printf("InOrder Traversal: ");
    inOrderTraversal(p);
    printf("\n");

    deleteNode(p, 10);

    printf("InOrder Traversal: ");
    inOrderTraversal(p);

    return 0; 
}
