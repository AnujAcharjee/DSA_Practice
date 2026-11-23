// Evaluate polynomial
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int coefficient;
    int power;
    struct node* next;
} node;

node* insertNode (node *head, int coefficient, int power) {
    node *ptr = (node *)malloc(sizeof(node));

    if (ptr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(1);
    }

    ptr->coefficient = coefficient;
    ptr->power = power;
    ptr->next = head;

    return ptr;
}

node* createNode (node *ptr, int coefficient, int power , int *count) {
    while (count != 0) {
        node *NODE = insertNode (node *head, int coefficient, int power);
    }
    

}


int main () {
    node *head;

    int count = 1;
}
