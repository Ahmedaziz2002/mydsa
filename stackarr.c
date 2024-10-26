#include<stdio.h>
#include<stdlib.h>

//array stack

#define MAX 10
struct Stack{
    int top;//index of the top element
    int items[MAX];//array to hold struct Elements
};

struct Stack* createStack(){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->top=-1;//initialize top to -1 indicating an empty stack
    return stack;
}

int isFull(struct Stack* stack){
    return stack->top==MAX-1;
}

int isEmpty(struct Stack* stack){
    return stack->top==-1;
}

void push(struct Stack* stack,int item){
    if(isFull(stack)){
        printf("Stack overflow.\n");
        return;
    }
    stack->items[++stack->top]=item;
    printf("%d pushed onto the stack\n");
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("stack is empty\n");
        return -1;
    }
    return stack->items[stack->top];
}

int main(){
    struct Stack* myStack=createStack();

    push(myStack,10);
    push(myStack,20);
    push(myStack,30);

    printf("%d popped\n",pop(myStack));

    printf("%d peeked\n",peek(myStack));

    return 0;

    
}