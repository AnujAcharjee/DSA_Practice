#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isEmpty (struct stack *ptr) {
    if(ptr->top == -1) {
        return 1;
    }
    return 0;
}

int isFull (struct stack *ptr) {
    if (ptr->top == ptr->size - 1) {
        return 1;
    }
    return 0;
}

void push (struct stack *ptr, char val) {
    if (isFull(ptr) == 1){
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    }
    else {
        ptr->top ++;
        ptr->arr[ptr->top] = val;
    }
}

char pop (struct stack *ptr) {
    if (isEmpty(ptr) == 1) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return '\0';
    }
    else {
        char val = ptr->arr[ptr->top];
        ptr->top --;
        return val;
    }
}

void createStack (struct stack *sp, int size){
    sp->size = size;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));  //space for stack elements 
    if (sp->arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }
    printf("Stack has been created successfully\n");
}


int parenthesisMatch (char * exp) {
    // Create and initialize the stack
    struct stack *sp = (struct  stack *)malloc(sizeof(struct stack)); //space for stack  
    if (sp == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1; // Return an error code
    }
    createStack(sp, 100);

    for (int i=0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(sp, '(');
        }
        else if(exp[i] == ')'){
            if(isEmpty(sp)) {   //to check-> when nothing to pop
                free(sp->arr); // Free the dynamically allocated memory for the stack array
                free(sp);      // Free the dynamically allocated memory for the stack structure
                return 0;
            }
            pop(sp);
        }
    }
    int isBalanced = isEmpty(sp);
    free(sp->arr); // Free the dynamically allocated memory for the stack array
    free(sp);      // Free the dynamically allocated memory for the stack structure
    return isBalanced;
}



int main() {
    //7-(8(3*9)+11+12))-8)
    char exp[100];  //character array 

    printf("Enter any expression : ");
    scanf("%s", exp);

    // Check if stack is empty
    if(parenthesisMatch(exp)){
        printf("The parenthesis is balanced");
    }
    else{
        printf("The parenthesis is not balanced");
    }

    return 0;
}
