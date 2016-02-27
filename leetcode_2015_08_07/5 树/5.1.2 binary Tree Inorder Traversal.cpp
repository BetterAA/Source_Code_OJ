#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>

#define nullptr NULL

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    ///声明时需要的构造方法
};
//中序, 左根右
vector<int> inorderTraversal(TreeNode *root){
    vector<int> result;
    TreeNode *p = root;
    stack<TreeNode *> s;
    ///自己写还是写不出来!!!
    while(!s.empty() || p!=nullptr){
        if(p!=nullptr){
    ///将左节点压栈, 注意:是个边push边pop的过程!
    ///左节点为空时,pop(此时是根),再push右节点
            s.push(p);
            p= p->left;
        }
        else{
            p=s.top();
            s.pop();///左节点为空,此时是根,下一个应该是右
            result.push_back(p->val);
            p= p->right; ///压栈操作统一在上面
        }
    }
    return result;
}


int main(){
    int n = 3;
    TreeNode *A[3];
    ///new 出来的是指针!!!!!!
    ///结构体中附带了初始化方法..
    A[0] = new TreeNode(1);
    A[1] = new TreeNode(2);
    A[2] = new TreeNode(3);

    A[0]->right = A[1];
    A[1]->left = A[2];

    vector<int> result = inorderTraversal(A[0]);
    for(int i=0 ; i<3; i++){
        printf("%d ",result[i]);
    }
}
