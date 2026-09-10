#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
	int data;
	struct Stack *next;
}Stack;
Stack* push(Stack *top,int val){
	Stack *newnode=(Stack*)malloc(sizeof(Stack));
	newnode->data=val;
	newnode->next=top;
	return newnode;
}
Stack* pop(Stack *top){
	if(top==NULL){
		printf("Stack Underflow....");
		return NULL;
	}
	Stack *temp=top;
	top=top->next;
	free(temp);
	return top;

}