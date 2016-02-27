#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<iterator>
#include<list>
#include<cmath>

#define nullptr NULL

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


int a[5] = {3,9,20,15,7};
int b[5] = {9,3,15,20,7};
vector<int> preorder(a,a+5) ;
vector<int> inorder(b,b+5);


template<typename InputIterator>

//TreeNode* buildTree(InputIterator pre_first,InputIterator pre_last,InputIterator in_first,InputIterator in_last)
TreeNode* buildTree(vector<int>::iterator pre_first,vector<int>::iterator pre_last,vector<int>::iterator in_first,vector<int>::iterator in_last)
{
    if(pre_first==pre_last) return NULL;
    if(in_first==in_last) return NULL;

    TreeNode* root = new TreeNode(*pre_first);

    InputIterator in_root = find(in_first,in_last,*pre_first);
    int leftSize = distance(in_first,in_root);

    root->left = buildTree(next(pre_first),next(pre_first,leftSize+1),in_first,next(in_first,leftSize));
    root->right= buildTree(next(pre_first,leftSize+1),pre_last,next(in_root),in_last);

    return root;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
    return buildTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    //return buildTree(vector<int>::iterator.begin(preorder),vector<int>::iterator.end(preorder),vector<int>::iterator.begin(inorder),vector<int>::iterator.end(inorder);
}


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

    TreeNode *root = buildTree(preorder,inorder);
    vector<int> result = preorderTraveral(root);
    for(int i=0; i<result.size(); i++){
        printf("%d ",result[i]);
    }
}

