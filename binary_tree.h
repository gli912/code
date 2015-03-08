#ifndef binary_tree_h
#define binary_tree_h

#include "stddef.h"
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) {this->val=v;this->left=NULL;this->right=NULL;}
};

TreeNode *createtree(int arr[],int n, int pos);
void printtree(TreeNode *root);
TreeNode *findnode(TreeNode *root, int val);
TreeNode *findancestor(TreeNode *root, TreeNode *p, TreeNode *q);
#endif // binary_tree_h
