#include<iostream>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
 	 /*因为是BST， 所以左边的肯定比根小，右边的肯定比根大
 		如果p，q的值都比root值小，那么p，q肯定都在root的左枝上，公共祖先也在左枝上，都大的话就在右枝
 		如果p，q的值正好在root两侧，那么此时root就是LCA，因为root左支上任何一个node都不能是q的祖先，右枝上任何node都不会是p祖先
 		所以，最低的公共祖先肯定是root
	*/
 	 if(p->val==q->val) return p;
 	 //可以简化，这2个if省略，因为 除了pq都在root两边，其他的也适合return root来解决
 	 //
 	 //if(root->val==p->val) return p;  
 	 //if(root->val==q->val) return q;
 	 //此时left必存在
 	 if((p->val<root->val)&&(q->val<root->val)) return lowestCommonAncestor(root->left,p,q);
 	 if((p->val>root->val)&&(q->val>root->val)) return lowestCommonAncestor(root->right,p,q);
 	 else return root;//p，q在root两侧     
 }