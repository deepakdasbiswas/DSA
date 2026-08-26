#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}Node;
Node* deleteanynode(Node *head,int target){
    if(head==NULL){
        return NULL;
    }
    int index=1;
    Node *temp=head;
    while(temp!=NULL && index!=target){
        index++;
        temp=temp->next;
    }
    if(temp==NULL){
        return head;
    }
    if(temp==head){
        head=temp->next;
        if(head!=NULL){
            head->prev=NULL;
        }
    }else{
        temp->prev->next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
    }
    free(temp);
    return head;
}