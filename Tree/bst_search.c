#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;
TreeNode* search(TreeNode *root,int key){
	if (root == NULL || root->data == key) {
        return root;
    }
	if(key<root->data){
		return search(root->left,key);
	}else if(key>root->data){
		return search(root->right,key);
	}
}