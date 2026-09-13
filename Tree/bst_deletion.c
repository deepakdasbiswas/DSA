#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;
TreeNode* getSuccessor(TreeNode *curr){
    while(curr!=NULL && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
TreeNode* delete(TreeNode *root,int val){
    if(root==NULL){
        return root;
    }
    if(val<root->data){
        root->left=delete(root->left,val);
    }else if(val>root->data){
        root->right=delete(root->right,val);
    }else if(val==root->data){
        if(root->left==NULL){
            TreeNode *temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            TreeNode *temp=root->left;
            free(root);
            return temp;
        }else if(root->left!=NULL && root->right!=NULL){
            TreeNode *temp=getSuccessor(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        } 
    }
    return root;
}