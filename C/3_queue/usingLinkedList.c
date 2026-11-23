#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node
{
    int data;
    struct node *next;
} node;

// Define the queue structure
typedef struct queue
{
    node *f; //front
    node *r; //rear
} queue;

// Function to create a queue
void create (queue **ptr) {   //**ptr = *&q
    *ptr = (queue*)malloc(sizeof(queue));   //memory allocated for queue
    if (*ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);  // Exit if memory allocation fails
    }
    (*ptr)->f = NULL;
    (*ptr)->r = NULL;
}


void linkedListTraversal (struct node *ptr) {
    printf("Printing the elements of this linked list::\n");
    while (ptr != NULL)
    {
        printf("Element: %d Address: %hx\n", ptr->data, ptr->next);
        ptr = ptr->next;
    }
}

void enqueue (queue **ptr, int val) {
    node *n = (node*)malloc(sizeof(node)); //memory allocated for new node
    if(n == NULL) {
        printf("Queue is Full");
    }
    else {
        // creating new node 
        n->data = val;
        n->next = NULL; //as insertion done through rear, n last node
        if((*ptr)->f == NULL) 
        {
            (*ptr)->f = (*ptr)->r = n;   //special case: one node is there...both f & r point towards NULL.
        } 
        else 
        {
            (*ptr)->r->next = n;  // prev rear will point towards new node
            (*ptr)->r = n;  // rear point updated to newly added node
        }
    }
}

int dequeue (queue **ptr) {
    int val = -1;
    node *p = (*ptr)->f;

    if(p == NULL) {
        printf("Queue is empty\n");
    } 
    else {
        (*ptr)->f = p->next;
        val = p->data;
        free(p);
        if ((*ptr)->f  == NULL)
        {
            (*ptr)->r = NULL;
        }  
    }
    return val;
}

int main() {    
    queue *q;
    create (&q);

    linkedListTraversal(q->f);
    printf("Dequeuing element %d\n", dequeue(&q));
    enqueue(&q, 34);
    enqueue(&q,4);
    enqueue(&q,7);
    enqueue(&q,17);
    linkedListTraversal(q->f);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    linkedListTraversal(q->f);

    


    return 0;
}