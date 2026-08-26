#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}Node;
Node* addnodeend(Node *head,int val){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        return newnode;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}