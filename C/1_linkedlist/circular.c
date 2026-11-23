#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void circularLinkedListTraversal(node *head) {
    node *ptr = head;
    
    do {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

node* insertAtHead (node *head, int data) {
    node *ptr = (node *)malloc(sizeof(node)); 
    ptr->data = data;
    
    node *p = head->next; //stores address to next node
    
    while (p->next != head) {  //in last node address of next node will point towards head
        p = p->next;
    }

    p->next = ptr;      
    ptr->next = head;
    head = ptr;
    return head;
}

int main() {
    node *head;
    node *second;
    node *third;
    node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
 
    // Link first and second nodes
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

