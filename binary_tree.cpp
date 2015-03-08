#include "binary_tree.h"
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

TreeNode *createtree(int arr[],int n, int pos)
{
    if(pos>=n) return NULL;
    TreeNode *res = new TreeNode(arr[pos]);
    res->left = createtree(arr, n, (pos+1)*2-1);
    res->right = createtree(arr, n, (pos+1)*2);
    return res;
}

void printtree(TreeNode *root)
{
    queue<TreeNode *> q;
    if(root==NULL) return;
    q.push(root);
    int a=1;
    int b=0;
    while(!q.empty())
    {
        TreeNode *tmp = q.front();
        cout<<tmp->val<<" ";
        if(tmp->left)
        {
            q.push(tmp->left);
            b++;
        }
        if(tmp->right)
        {
            q.push(tmp->right);
            b++;
        }
        q.pop();
        a--;
        if(a==0)
        {
            a=b;
            b=0;
            cout<<endl;
        }
    }
    cout<<endl;
}

TreeNode *findnode(TreeNode *root, int val)
{
    queue<TreeNode *> q;
    if(root==NULL) return NULL;
    q.push(root);
    int a=1;
    int b=0;
    while(!q.empty())
    {
        TreeNode *tmp = q.front();
        if(tmp->val == val) return tmp;
        if(tmp->left)
        {
            q.push(tmp->left);
            b++;
        }
        if(tmp->right)
        {
            q.push(tmp->right);
            b++;
        }
        q.pop();
        a--;
        if(a==0)
        {
            a=b;
            b=0;
        }
    }
    return NULL;
}

TreeNode *findancestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root==NULL) return NULL;
    if(root==p || root==q) return root;
    TreeNode *x = findancestor(root->left, p, q);
    if(x!=NULL && x!=q && x!=p) return x;
    TreeNode *y = findancestor(root->right, p, q);
    if(y!=NULL && y!=q && y!=p) return y;
    if(x!=y && x!=NULL && y!=NULL) return root;
    if(x==NULL) return y;
    if(y==NULL) return x;
}


