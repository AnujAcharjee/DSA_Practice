#include <stdio.h>
#include <stdlib.h>

// circular queue
struct queue
{
    int size;
    int f; //front
    int r; //rear
    int *arr;
};

int isEmpty (struct queue *q) {
    if(q->r == q->f) {
        return 1;
    }
    return 0;
}

int isFull (struct queue *q) {
    if((q->r + 1) % q->size == q->f) {
        return 1;
    }
    return 0;
}

void enqueue (struct queue *q, int val) {
    //insertion is done through r
    if(isFull(q)) {
        printf("This Queue is full\n");
    }
    else {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val; 
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue (struct queue *q) {
    //deletion done through front
    int val = -1;
    if(isEmpty(q)) {
        printf("This Queue is empty\n");
    } 
    else {
        q->f = (q->f + 1) % q->size;
        val = q->arr[q->f];  
    }
    return val;
}

int main() {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    if (q == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1; // Return an error code
    }
    q->size = 20;
    q->f = -1;
    q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));
    if(q->arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        free(q); 
        return 1; // Return an error code
    }
    printf("Queue has been created!!\n");

    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1); 
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q)); 
    enqueue(q, 45);
    enqueue(q, 45);
    enqueue(q, 45);
 
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    if(isFull(q)){
        printf("Queue is full\n");
    }

    // Free allocated memory before exiting
    free(q->arr);
    free(q);

    return 0;
}