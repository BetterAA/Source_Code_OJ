#include<iostream>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int dfsHeight(TreeNode* root){
	//－1表示已经不平衡了
	//！！自带返回高度以及顺便判断平衡的（－1）
	if(!root) return 0;
	int leftHeight = dfsHeight(root->left);
	if(leftHeight==-1) return -1; //如果已经不平衡了，那么也就返回－1，结束dfs
	int rightHeight= dfsHeight(root->right);
	if(rightHeight==-1) return -1;
	if(abs(leftHeight,rightHeight)>1) return -1;
	
	return max(leftHeight-rightHeight)+1;
}
bool isBalanced(TreeNode* root) {
	return dfsHeight(root)!=-1;        
}
int main(){

}