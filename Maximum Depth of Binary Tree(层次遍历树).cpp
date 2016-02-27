#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int getMaxDepth(TreeNode *root,int nowDepth){
	if(root==NULL) return nowDepth-1;//发现当前的这个枝实际是不存在的
	if((root->left==NULL)&&(root->right==NULL)) return nowDepth;
    else return max(getMaxDepth(root->left,nowDepth+1),getMaxDepth(root->right,nowDepth+1));
}
//可以利用层次遍历，也可以直接变成分治，求左右子树的最深
int maxDepth(TreeNode* root) {
	return getMaxDepth(root,1);
}

int main(){
	TreeNode  *A[5];
	A[0] = new TreeNode(1); //new 出来的是指针！！
	A[1] = new TreeNode(1);
	A[2] = new TreeNode(1);
	A[3] = new TreeNode(1);
	A[4] = new TreeNode(1);

	A[0]->left = A[1];
	A[0]->right = A[2];
	A[2]->left = A[3];
	A[3]->right = A[4];

	cout<<maxDepth(A[0]);
	//delete A;
}