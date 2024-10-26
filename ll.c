#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAtBeginning(struct Node** head,int newdata){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data=newdata;
    newnode->next=*head;
    newnode->prev=NULL;
    if(*head!=NULL){
        (*head)->prev=newnode;
    }
    (*head)=newnode;
}

void deleteNode(struct Node** head,int key){
    struct Node* temp=*head;
    if(temp!=NULL && temp->data==key){
        *head=temp->next;
        if(*head!=NULL){
            (*head)->prev=NULL;
        }
        free(temp);
        return;
    }

    while(temp!=NULL && temp->data!=key){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Key not found\n");
        return;
    }
    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    free(temp);
}

int search(struct Node* node,int key){
    struct Node* temp=node;
    while(temp!=NULL){
        if(temp->data==key){
            return 1;
        }
        temp=temp->next;
    }
    return -1;
}

void display(struct Node* node){
    while(node!=NULL){
        printf("%d <->",node->data);
        node=node->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head=NULL;

    int n,data;
    printf("Enter the size of the list\n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        printf("Enter the data for your list\n",i+1);
        scanf("%d",&data);
        insertAtBeginning(&head,data);
    }
    printf("Original list is \n");
    display(head);

    int key;
    printf("Enter the node you want to delete\n");
    scanf("%d",&key);
    deleteNode(&head,key);
    display(head);

    int s;
    printf("Enter the node you want to search\n");
    scanf("%d",&s);
    int searchresult=search(head,s);
    if(searchresult!=-1){
        printf("Node found %d\n",s);
    }else{
         printf("Node not found\n ");
    }
   

    while(head!=NULL){
        struct Node* temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}