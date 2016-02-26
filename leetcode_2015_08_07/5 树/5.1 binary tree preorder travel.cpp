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
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

vector<int> preorderTraveral(TreeNode *root){
    vector<int> result;
    const  TreeNode *p;
    stack<const TreeNode*> s;

    p=root;
    if(p!=nullptr) s.push(p);

    while(!s.empty()){
        p = s.top();
        s.pop();
        result.push_back(p->val);
        //root->right->left
        if(p->right!= nullptr) s.push(p->right);
        if(p->left!= nullptr) s.push(p->left);
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

    vector<int> result = preorderTraveral(A[0]);
    for(int i=0 ; i<3; i++){
        printf("%d ",result[i]);
    }
}
