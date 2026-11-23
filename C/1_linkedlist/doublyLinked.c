#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
    struct Node * prev;
};

void doublyLinkedListTraversal(struct Node *head) {
    struct Node *ptr = head;

    printf("Forward traversal:\n");
    while (ptr != NULL) {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }

    printf("Backward traversal:\n");
    ptr = head;
    while (ptr->next != NULL) {  //ptr will move to last node
        ptr = ptr->next;
    }
    while (ptr != NULL) {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->prev;
    }
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // Link first and second nodes
    head->data = 1;
    head->next = second;
    head->prev = NULL;
    // Link second and third nodes
    second->data = 2;
    second->next = third;
    second->prev = head;

    // Link third and fourth nodes
    third->data = 3;
    third->next = fourth;
    third->prev = second;

    // Terminate the list at the third node
    fourth->data = 4;
    fourth->next = NULL;
    fourth->prev = third;

    printf("before insertion:- \n");
    doublyLinkedListTraversal(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

  
    return 0;
};

