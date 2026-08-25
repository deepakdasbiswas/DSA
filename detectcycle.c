#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
int detectcycle(Node *head){
	Node *slow=head;
	Node *fast=head;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
			return 1;
		}
	}
	return 0;
}
int main(){
	return 0;
}
