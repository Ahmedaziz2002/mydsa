#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Task{
    char description[256];
    int completed;
    struct Task* next;
};

struct Task* head=NULL;

void addTask(const char* desc){
    struct Task* newtask=(struct Task*)malloc(sizeof(struct Task));
    strcpy(newtask->description,desc);
    newtask->completed=0;
    newtask->next=NULL;

    if(head==NULL){
        head=newtask;
    }else{
        struct Task* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newtask;
    }
}

void viewtask(){
    struct Task* temp=head;
    int index=1;
    while(temp!=NULL){
        printf("%d. [%s] %s\n",index++,temp->completed ? "X" : " ",temp->description);
        temp=temp->next;
    }
}

int main(){
    int choice;
    char desc[256];

    while(1){
        printf("1.Add task\n2.View task\n3.Exit\n Choose an option:");
        scanf("%d",&choice);
        getchar();

        switch(choice){
            case 1:
            printf("Enter task description\n");
            fgets(desc,sizeof(desc),stdin);
            desc[strcspn(desc,"\n")]=0;//remove newline character
            addTask(desc);
            break;
            case 2:
            viewtask();
            break;
            case 3:
            exit(0);
            default:
            printf("Invalid option\n");
        }
    }
    return 0;

}