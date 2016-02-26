#include<stdio.h>
#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

///递归获取树的高度,返回-1则是非平衡树 O(n), O(log(n))
int getTreeHeight(TreeNode* root){
    if(root==NULL) return 0;

    int left = getTreeHeight(root->left);
    int right= getTreeHeight(root->right);
    ///left=-1或者right=-1或者已经不平衡,直接是-1,父节点也肯定是-1...等等
    if(left<0 ||right<0 ||abs(left-right)>1) return -1;

    return max(left,right)+1 ;
}
bool isBalance(TreeNode *root){
    return getTreeHeight(root)>=0;
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

    cout<<isBalance(A[0])<<endl;
    cout<<isBalance(A[1]);
    delete A;
}

