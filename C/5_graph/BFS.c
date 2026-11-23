#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 
int main(){
    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // BFS Implementation 
    int node; // store the current node being processed
    int i = 0;  // search starts from this node
    int visited[7] = {0,0,0,0,0,0,0};  // It's initialized with 0s, indicating that no nodes have been visited yet.

    int a [7][7] = {
        {0,1,1,1,0,0,0}, //0
        {1,0,0,1,0,0,0}, //1
        {1,0,0,1,1,0,0}, //2
        {1,1,1,0,1,0,0}, //3
        {0,0,1,1,0,1,1}, //4
        {0,0,0,0,1,0,0}, //5
        {0,0,0,0,1,0,0}  //6
    };
    printf("%d", i);  // This prints the starting node i from which the BFS traversal begins.
    visited[i] = 1;  // The visited array is updated (to 1), to mark node i as visited.
    enqueue(&q, i); // The starting node i is enqueued into the queue q, indicating that it will be explored first.
    while (!isEmpty(&q))
    {
        int node = dequeue(&q); // The front element of the queue is dequeued and stored in the variable node. This node will be explored next.
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){  // This condition checks if there is a connection between the current node and node j, and if node j has not been visited yet.
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    free(q.arr);
    return 0;
}
