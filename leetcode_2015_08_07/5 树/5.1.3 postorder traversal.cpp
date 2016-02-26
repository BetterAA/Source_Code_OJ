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

///自己还是写不来...,三种其实并不一样,需要分别记!!
//后序, 左右根
vector<int> postorderTraversal(TreeNode *root){

    vector<int> result;
    TreeNode *p =root,*q;
    ///p指向当前节点,q指向上次访问节点
    stack<TreeNode*> s;

    do{
        while(p!=nullptr){
            s.push(p);
            p= p->left;///忘左下走
         }
        q= nullptr;
        while(!s.empty()){
            ///最左节点入栈完毕,需要访问或者压入右节点
            p=s.top();
            s.pop();///先出栈,如果还有右节点的话还得再入栈...看下文else
            ///右节点为空或者已经被访问
            if(p->right==q){
                result.push_back(p->val);
                q= p; ///保存刚访问过的节点
            }else{
                ///没有左,但有右节点,不能访问
                s.push(p); ///还得重新push进来,上文已经pop了...
                p= p->right;
                break;
            }
        }
     }while(!s.empty());

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

    vector<int> result = postorderTraversal(A[0]);
    for(int i=0 ; i<3; i++){
        printf("%d ",result[i]);
    }
}
