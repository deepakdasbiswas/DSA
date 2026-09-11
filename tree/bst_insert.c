#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;
TreeNode* insert(TreeNode *root,int val){
    if(root==NULL){
        TreeNode *newnode=(TreeNode*)malloc(sizeof(TreeNode));
        newnode->data=val;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }else if(val>root->data){
        root->right=insert(root->right,val);
    }
    return root;
}