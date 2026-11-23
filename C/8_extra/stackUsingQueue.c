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
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty (queue *ptr) {
    if (ptr->f == NULL){
        return 1;
    }
    return 0;
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

void push (queue **q1, queue **q2, int val) {
    // enqueue val in q2 
    enqueue(q2, val);
    // dequeue elements from q1 and enqueue them in q2
    while (!isEmpty(*q1)) {
        int x = dequeue(q1);
        enqueue (q2, x);
    }
    //swap q1 and q2
    queue *temp = *q1;
    *q1 = *q2;
    *q2 = temp;
}

int pop (queue **q1) {
    if (isEmpty(*q1)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return dequeue(q1);
    }
}

int main() {    
    queue *q1, *q2;
    create (&q1);
    create (&q2);

    push (&q1, &q2, 69);
    push(&q1, &q2, 42);
    push(&q1, &q2, 17);

    printf("Elements in q1 (acting as stack):\n");
    linkedListTraversal(q1->f);

    pop(&q1);
    printf("Elements in q1 (acting as stack):\n");
    linkedListTraversal(q1->f);


    


    return 0;
}