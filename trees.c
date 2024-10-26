#include<stdio.h>
#include<stdlib.h>
struct Node{
    //create a Node structure with elements data ,left and right
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    //create a newnode and allocate its memory dynamically
    //initilaise the left node to NULL
    //initilaise the right node to NULL
    //return the new empty node
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void inorder(struct Node* node){
    //During inorder visit left,node,then right
    if(node==NULL)return;
    inorder(node->left);
    printf("%d",node->data);
    inorder(node->right);
}

void preorder(struct Node* node){
    //during preorder visit root,left,right
    if(node==NULL)return;
    printf("%d",node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node* node){
    //during post order visit left,right,then root
    if(node==NULL)return;
    postorder(node->left);
    postorder(node->right);
    printf("%d",node->data);
}

int main(){
    struct Node* root=createNode(10);//initialise root and create its node while giving its value proceed to the children
    root->left=createNode(20);
    root->right=createNode(30);
    root->right->left=createNode(40);
    root->right->right=createNode(50);

    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n");

    printf("Postorder traversal:\n");
    postorder(root);
    printf("\n");

    return 0;
}