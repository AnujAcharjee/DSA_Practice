#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct  Node *next;
};

void linkedListTraversal (struct Node *ptr) {
    while (ptr != NULL){
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty (struct Node *top) {
    if (top == NULL) {
        return 1;
    } 
    return 0;
}

int isFull (struct Node *top) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {
        return 1;
    }
    return 0;
}

struct Node* push (struct Node *top, int val) {
    if (isFull(top)) {
        printf("Stack Overflow\n");
        return top;
    }
    else {
        struct Node *n = (struct Node*)malloc(sizeof(struct Node));
        n->data = val;
        n->next = top;
        top = n;
        return top;
    }
}

//OR we can make top as global variable 
int pop (struct Node **top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow\n");
        return -1;
    }
    else {
        struct Node *n = *top;
        int val = n->data;  //to print the popped value
        *top = n->next;
      
        free(n);
        return val;
    }
}

int stackTop (struct Node *sp) {
    if (isEmpty(sp)) {
        printf("Stack is empty\n");
        return -1; // Return a sentinel value indicating error
    }
    return sp->data;
}


int stackBottom (struct Node *sp) {
    int val = 0;
    while (sp != NULL) {
        val = sp->data;
        sp = sp->next;   
    }
    return val;
}

int peek(struct Node *top, int indx) {
    for (int i = 0; i < indx && top != NULL; i++) {
        top = top->next;
    }
    if (top == NULL) {
        printf("Invalid index\n");
        return -1; // Return a sentinel value indicating error
    }
    return top->data;
}

int main() {
    struct Node *top = NULL; //we can make it as global variable, so any change in it through any func. are applicable for for all

    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 69);
    
    linkedListTraversal(top);

    int element = pop(&top);
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);

    printf("stackTop : %d \n", stackTop(top));
    printf("stackBottom : %d \n", stackBottom(top));

    for (int i = 1; i <= 4; i++)
    {
        printf("Value at position %d is : %d\n", i, peek(top, i));
    }


    return 0;
}