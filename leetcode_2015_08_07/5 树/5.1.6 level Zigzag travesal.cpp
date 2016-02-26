#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

///跌代版 o(n) O(1)
vector<vector<int> > levelTraversal(TreeNode *root){
    vector<vector<int> > result;
    vector<int> level; ///记录每一层中的遍历结果,用于push_back到result
    queue<TreeNode*> next,current;
    bool left_to_right = true;

    if(root == NULL) return result;

    current.push(root);

    TreeNode *p;
    while(!current.empty()){
        while(!current.empty()){
            p = current.front();
            current.pop();
            level.push_back(p->val);

            if(p->left!=NULL)
                next.push(p->left);
            if(p->right!=NULL)
                next.push(p->right);
        }
        if(left_to_right)
            result.push_back(level);
        else{
            reverse(level.begin(),level.end());
            result.push_back(level);
        }
        level.clear();
        ///改变方向
        left_to_right = !left_to_right;
        swap(next,current);///此时current队列是空
    }
    return result;
}

/*
//注意result是传地址!
void travesal(TreeNode* root, int level, vector<vector<int> > &result,bool left_to_right){
    if(level>result.size()){
        ///result.size()指的是维数,  即[3],[9,20]时候size是2!
        result.push_back(vector<int>());
        ///判断新增一维
    }
    if(left_to_right)
        result[level-1].push_back(root->val);
    else
        result[level-1].insert(result[level-1].begin(),root->val);

    ///保证了第一个参数非空,除了第一个root
    if(root->left!= NULL) travesal(root->left,level+1, result,!left_to_right);
    if(root->right!= NULL) travesal(root->right,level+1, result,!left_to_right);
}
///迭代版  O(n) O(n)
vector<vector<int> > levelTraversal(TreeNode *root){
    vector<vector<int> >result;

    if(root==NULL) return result;

    travesal(root,1,result,true);
    return result;
}
*/
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

    vector<vector<int> > result = levelTraversal(A[0]);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++)
            printf("%d ",result[i][j]);
        printf("\n");
    }
    delete A;
}

