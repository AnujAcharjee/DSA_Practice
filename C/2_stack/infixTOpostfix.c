#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

char stackTop(struct stack* sp) {
    return sp->arr[sp->top];
}

int isEmpty(struct stack* sp) {
    if (sp->top == -1) {
        return 1;
    }
    return 0;
}

int isFull(struct stack* sp) {
    if (sp->top == sp->size - 1) {
        return 1;
    }
    return 0;
}

void push(struct stack* sp, char ch) {
    if (isFull(sp)) {
        printf("Stack Overflow! Cannot push %d to the stack\n", ch);
    }
    else {
        sp->top++;
        sp->arr[sp->top] = ch;
    }
}

char pop(struct stack* sp) {
    char ch;
    if (isEmpty(sp)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
    }
    else {
        ch = sp->arr[sp->top];
        sp->top --;

        return ch;
    }
}

int isOperator(char ch) {
    if (ch =='*' || ch =='/' || ch =='+' || ch =='-') {
        return 1;
    }
    return 0;
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 3;
    }
    if (ch == '+' || ch == '-') {
        return 2;
    }
    return 0;  
} 

char * infixToPostfix (char * infix) {
    //creating stack
    struct  stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    // creating a string named postfix
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));

    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 

    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) { // when we get operands
            postfix[j] = infix[i]; 
            i++;
            j++;
        }
        else {
            if (precedence(infix[i]) > precedence(stackTop(sp))) {   
                push (sp, infix[i]);
                i++;
            }
            else {   // when precedence lesser
                postfix[j] = pop(sp);   // add popped operator to postfix string
                j++;
            }
        }
    }
    while (!isEmpty(sp))  // infix string is empty , but stack has some operators  
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';   // ending postfix string
    return postfix;
}

int main() {
    char * infix = "a+b-d/c*s+r";
    printf("postfix is %s", infixToPostfix(infix));

    return 0;
}