#include<stdio.h>
#include<stdlib.h>

#define MAX 5
//Queues arrays
struct Queue{
    int front;
    int rear;
    int items[MAX];
};

struct Queue* createQueue(){
    struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->front=-1;
    queue->rear=-1;
    return queue;
}

int isFull(struct Queue* queue){
    return queue->rear==MAX-1;
}

int isEmpty(struct Queue* queue){
    return queue->front==-1;
}

void enqueue(struct Queue* queue,int item){
    if(isFull(queue)){
        printf("Queue is full\n");
    }
    if(queue->front==-1)queue->front=0;

    queue->items[++queue->rear]=item;
    printf("Inserted %d\n",item);
}

int dequeue(struct Queue* queue){
    int item;
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return -1;
    }
    item=queue->items[queue->front++];
    if(queue->front>queue->rear){
        queue->front=queue->rear=-1;
    }

    return item;
}

void display(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue contains:");
    for(int i=queue->front;i<=queue->rear;i++){
        printf(" :%d",queue->items[i]);
    }
    printf("\n");
}

int main(){
    struct Queue* queue=createQueue();

    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    display(queue);

    dequeue(queue);
    dequeue(queue);
    display(queue);

    return 0;
}
