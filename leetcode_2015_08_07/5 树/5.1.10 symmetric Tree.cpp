#include<iostream>
#include<stdio.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

///两个子树都是平衡树并不能保证此数就是平衡树,例如左子树没有节点,右子树右左右两个节点的情况
///此题解法不对!!!
bool isSymmetricTree(TreeNode* root){
    if(root==NULL) return true; ///定义一个空的树是一个对称的
    if(!root->left && !root->right) return true;
    if(!root->left || !root->right) return false;
    ///剩下的就是左右子树都不为空
    if(isSymmetricTree(root->left)&&isSymmetricTree(root->right))
        return true;
    return false;
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

    cout<<isSymmetricTree(A[0])<<endl;
    cout<<isSymmetricTree(A[2]);
    delete A;
}

