#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;
int height(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    if(leftHeight<rightHeight){
        return rightHeight+1;
    }else{
        return leftHeight+1;
        
    }   
}