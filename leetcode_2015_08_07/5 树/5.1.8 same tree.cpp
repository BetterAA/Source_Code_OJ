#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
/*
///递归版
bool isSameTree(TreeNode * root1, TreeNode* root2){
    if(!root1 && !root2) return true;
    ///经过上一步的排除, 排除了都不会空,则下一条件成立就是说只有一个为空
    if(!root1 || !root2) return false;

    return (root1->val == root2->val)&&isSameTree(root1->left,root2->left)&&isSameTree(root1->right,root2->right);
}
*/
///迭代版
bool isSameTree(TreeNode *node1, TreeNode*node2){
    stack<TreeNode*> s;
    s.push(node1);
    s.push(node2);

    while(!s.empty()){
     node2 = s.top();
     s.pop();
     node1 = s.top();
     s.pop();
     if(!node1 && !node2) return true;
     if(!node1 || !node2) return false;
     if(node1->val!=node2->val) return false;

     s.push(node1->left);
     s.push(node2->left);

     s.push(node1->right);
     s.push(node2->right);
    }
    return true;
}

int main(){
    TreeNode *A[5];
    A[0] = new TreeNode(3);
    A[1] = new TreeNode(9);
    A[2] = new TreeNode(20);
    A[3] = new TreeNode(15);
    A[4] = new TreeNode(7);

    A[0]->left = A[1];
    A[0]->right= A[2];
    A[2]->left = A[3];
    A[2]->right= A[4];

    cout<<isSameTree(A[0],A[0])<<endl;
    cout<<isSameTree(A[0],A[1]);
    delete A;
}
