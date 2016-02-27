#include<iostream>
#include<vector>
#include<stack>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    
    if(!root||((root->left==NULL)&&(root->right==NULL))) 
    	{
    		return root;
    	}
    else {
    	//至少有一枝
    	TreeNode *left = root->left;
    	TreeNode *right = root->right;
    	//inverTree方法返回的是TreeNode，所以递归的话肯定是 XX ＝ invert
    	root->right = invertTree(left);
    	root->left = invertTree(right);
    	return root;
    }    
}

//非递归方法
TreeNode* invertTree(TreeNode* root) {
	if(!root) return root;
	stack<TreeNode*> st;
	st.push(root);

	while(!st.empty()){
		TreeNode *tmp = st.top();
		st.pop();
		if(tmp){///////
			st.push(tmp->left);
			st.push(tmp->right);
			swap(tmp->left,tmp->right);
		}
	}
	//把链表头返回
	return root;
}
int main(){
TreeNode  *A[5];
	A[0] = new TreeNode(1); //new 出来的是指针！！
	A[1] = new TreeNode(2);
	A[2] = new TreeNode(3);
	A[3] = new TreeNode(4);
	A[4] = new TreeNode(5);

	A[0]->left = A[1];
	A[0]->right = A[2];
	A[2]->left = A[3];
	A[3]->right = A[4];

}