#include<stdio.h>
#include<stdlib.h>
//stack
struct  Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int newdata){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL){
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newnode->data=newdata;
    newnode->next=NULL;
    return newnode;
}

int isEmpty(struct Node* top){
    return top==NULL;
}

void push(struct Node** top,int data){
    struct Node* newnode=createNode(data);
    if(newnode==NULL) return;
    newnode->next=*top;
    *top=newnode;
    printf("%d pushed onto the stack!\n",data);
}

int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack underflow.Cannot pop any element!\n");
        return -1;
    }
    struct Node* temp=*top;
    int popped=temp->data;
    *top=(*top)->next;
    free(temp);
    return popped;
}

int peek(struct Node* top){
    if(isEmpty(top)){
        printf("Stack is empty cannot peek any element!\n");
        return -1;
    }
    return top->data;
}

void print(struct Node* node){
    if(isEmpty(node)){
        printf("Stack is empty!\n");
        return;
    }
    while(node!=NULL){
        printf("%d",node->data);
        node=node->next;
    }
    printf("\n");
}

int main(){
    struct Node* top=NULL;

    int n,data;

    printf("Enter the number of elements to push:\n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        printf("Enter the data to push:\n",i+1);
        scanf("%d",&data);
        push(&top,data);
    }
    printf("Pushed elements are:\n");
    print(top);

    int poppedValue=pop(&top);

    if(poppedValue!=-1){
        printf("popped %d\n",poppedValue);
        print(top);
    }

    int peekedValue=peek(top);

    if(peekedValue!=-1){
        printf("peeked %d\n",peekedValue);
        print(top);
    }

    printf("Stack is now:\n");
    print(top);

    while(top!=NULL){
        struct Node* temp=top;
        top=top->next;
        free(temp);
    }
    return 0;
}

