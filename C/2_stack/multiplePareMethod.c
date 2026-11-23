#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    char top;
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
        exit(1); // Exit the function after printing the error message
    }
    else {
        char val = ptr->arr[ptr->top];
        ptr->top --;
        return val;
    }
}

int matching (char c1, char c2) {
    if ((c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']')) {
        printf("Matched %c and %c\n", c1, c2);
        return 1;
    }
    printf("Did not match %c and %c\n", c1, c2);
    return 0;
}

int parenthesisMatch (char * exp) {
    // Create and initialize the stack
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char popped_ch;

    for (int i=0; exp[i] != '\0'; i++) {
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[') {
            push(sp, exp[i]);
        }

        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp)) {
                return 0;     //before popping stack is empty
            }
            popped_ch = pop(sp);
            if(!matching(popped_ch, exp[i])) {
                return 0;   
            } 
        }
    }
    if(isEmpty(sp)){
        free(sp->arr); // Free the dynamically allocated memory for the stack array
        free(sp);     // Free the dynamically allocated memory for the stack structure
        return 1;   //after popping stack is empty
    }
    free(sp->arr); // Free the dynamically allocated memory for the stack array
    free(sp);     // Free the dynamically allocated memory for the stack structure
    return 0;      //after popping all parenthesis in expression still stack is not  empty
}



int main() {
    // ([8]{(9-8)})
    // [[4-6]((8){(9-8])})
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
