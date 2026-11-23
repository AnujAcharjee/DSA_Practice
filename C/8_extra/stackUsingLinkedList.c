#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    node *next;
} node;

void create (node **ptr, int data) {
    
}

void circularLinkedListTraversal(node *head) {
    node *ptr = head;
    
    do {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}



int main() {
    node *head;
    node *second;
    node *third;
    node *fourth;
 
    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
 
    head->data = 1;
    head->next = second;
    // Link second and third nodes
    second->data = 2;
    second->next = third;
    // Link third and fourth nodes
    third->data = 3;
    third->next = fourth;
    // Terminate the list at the third node
    fourth->data = 4;
    fourth->next = head;

    printf("before insertion:- \n");
    circularLinkedListTraversal(head);

    printf("after insertion:- \n");
    head = insertAtHead (head, 111);
    circularLinkedListTraversal(head);
  
    return 0;
};