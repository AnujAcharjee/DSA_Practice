# include<stdio.h>
# include<stdlib.h>

struct Node {
    int data;
    struct Node *next; 
};

int countNumNode (struct Node *head) {
    if (head == NULL) {
        return 0;
    }

    struct Node *p = head;
    int count = 0;
    do {
        count++;
        p = p->next;
    } while (p != NULL);
    return count;
}


//here ptr is a variable pointer, pointing towards the node whose data to be printed
void linkedListTraversal(struct Node *ptr) {
    int counter = 0;
    while (ptr != NULL) {
        printf("Index: %d || Element: %d || Address: %hx\n",counter, ptr->data, ptr->next);
        ptr = ptr->next; 
        counter++;                            
    }
};

//case-1
// `struct Node*` indicates that the function `insertBeginning` returns a pointer to a Node structure.
// This pointer points towards the newly inserted node in the linked list.
struct Node* insertBeginning(struct Node *head, int data) { 
    //allocating memory for new node (named ptr)          
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));    
    
    // Memory allocation failed
    if (ptr == NULL) {
    printf("Memory allocation failed. Exiting program.\n");
    exit(1); // Exit the program with an error code
    }

    ptr->data = data; 
    ptr->next = head;

    return ptr;
};


//case-2
struct Node* insertAtIndex (struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;   // p contains the address of specific node - initialised with head address
    
    int i = 0;  
    while (i != index - 1) {
        p = p->next;   //stores address of next node at that specific index in p
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;

    return head;
};

// case-3
struct Node* insertAtEnd (struct Node *head, int data) {
    struct Node  *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    while (p->next != NULL) { // loop stops before last node
        p = p->next;   // p contains address of last node - stored in second last node
    };

    p->next = ptr;
    ptr->next = NULL;
    ptr->data = data;

    return head;
};

// case-4
struct Node* insertAfterNode (struct Node *head, struct Node *prevNode, int data) {
    struct Node  *ptr = (struct Node *)malloc(sizeof(struct Node));
    
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;   // by convention every c function returns some vale to indicate its success
};


//******DELETION******
// case-1
struct Node* deleteFirstNode (struct Node *head) {
     if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return NULL;
    }

    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
};

// case-2
struct Node* deleteGivenNode (struct Node *head, int index) {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return NULL;
    }

    struct Node *ptr = head;      // point towards 2nd node address
    struct Node *prev = NULL;             //point towards head address

    int i = 0;
    while (ptr != NULL && i < index) { 
        prev = ptr;       //give prevNode address
        ptr = ptr->next;  // gives deleted node address
        i++;
    }

    prev->next = ptr->next;
    free(ptr);
    return head;
};

//case-3
struct Node* deleteAtEnd (struct Node *head) {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return NULL;
    }

    struct Node *ptr = head;      // point towards 2nd node address
    struct Node *prev = NULL;             //point towards head address

    while (ptr->next != NULL) { 
        prev = ptr;       //give prevNode address
        ptr = ptr->next;   //prt will contain last node
    }
    // If there is only one node in the list
    if (prev == NULL) {
        free(ptr);
        return NULL;
    }
    // Update the next pointer of the second-last node to NULL
    prev->next = NULL;
    free(ptr);
    return head;
};

//case-4
struct Node* deletionFirstNodeWithGivenValue (struct Node *head, int givenVal) {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return NULL;
    }

    struct Node *ptr = head;      // point towards 2nd node address
    struct Node *prev = NULL;             //point towards head address

    while (ptr != NULL && ptr->data != givenVal) { 
        prev = ptr;       // Keep track of the previous node
        ptr = ptr->next;   // Keep track of the previous node
    }
    // If the node with the given value is not found
    if (ptr == NULL) {
        printf("Node with value %d not found in the list.\n", givenVal);
        return head; // Return the original head unchanged
    }
     // If the node with the given value is the first node
    if (prev == NULL) {
        head = head->next; // Update the head to point to the next node
    } else {
        prev->next = ptr->next; // Adjust pointers to skip the node to be deleted
    }
    free(ptr);
    return head;
};

int main() {
    // Allocate memory for nodes in the linked list in Heap
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
 
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
    fourth->next = NULL;

    printf("before insertion:- \n");
    linkedListTraversal(head);

    printf("after insertion:- \n");
    head = insertBeginning(head, 111); //when we call this function head changes every time
    head = insertAtIndex(head, 222, 4);
    insertAtEnd (head, 333);
    insertAfterNode (head, second, 444);
    insertAfterNode (head, second, 444);
    linkedListTraversal(head);

    printf("after deletion of all inserted lists:- \n");
    head = deleteFirstNode (head);
    head = deleteGivenNode (head, 5);
    deleteAtEnd (head);
    head = deletionFirstNodeWithGivenValue (head, 444);
    linkedListTraversal(head);

    printf ("number of nodes: %d", countNumNode(head));
    
    return 0;
};









