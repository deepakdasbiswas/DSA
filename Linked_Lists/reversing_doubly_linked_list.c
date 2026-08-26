#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node* reverse(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *temp=head;
    Node *last_changed=NULL;
    while(temp!=NULL){
        Node *store=temp->next;
        temp->next=temp->prev;
        temp->prev=store;
        last_changed=temp;
        temp=temp->prev;
    }
    return last_changed;
}