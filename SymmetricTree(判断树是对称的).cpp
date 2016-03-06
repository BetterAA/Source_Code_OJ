 //这个是递归，迭代方法用队列
    bool isSymmetric2(TreeNode* left, TreeNode*right){
        //不是树的左右子数对称，而是a的left和b的right是不是一样
        if(!left && !right) return true;
        if(!left || !right) return false; //one bunch is null
        //both is not null
        if(left->val!=right->val) return false;
        return isSymmetric2(left->left,right->right) && isSymmetric2(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetric2(root->left,root->right);
    }