#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;
TreeNode* search(TreeNode *root,int val){
    if(root==NULL || root->data==val){
        return root;
    }
    if(val<root->data){
        return search(root->left,val);
    }else if(val>root->data){
        return search(root->right,val);
    }

}
TreeNode* delete(TreeNode *root,int val){
    if(search(root,val)->left==NULL && search(root,val)->right==NULL){
        free(search(root,val));
    }else if(search(root,val)->left!=NULL || search(root,val)->right!=NULL){
        if(search(root,val)->left!=NULL && search(root,val)->right==NULL){
            TreeNode *temp=search(root,val)->left;
            search(root,val)->left=search(root,val)->left->left;
            free(search(root,val)->left);
        }else if(search(root,val)->left==NULL && search(root,val)->right!=NULL){
            TreeNode *temp=search(root,val)->right;
            search(root,val)->right=search(root,val)->right->right;
            free(search(root,val)->right);
        }
    }else if(search(root,val)->left!=NULL && search(root,val)->right!=NULL){
        
    }
    
}