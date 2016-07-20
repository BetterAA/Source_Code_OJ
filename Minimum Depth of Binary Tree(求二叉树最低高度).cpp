int dfsDepth(TreeNode* root,int depth){
        if(!root) return INT_MAX; //如果这里不判断root为NULL的话，那么下面就得对left和right有一个为NULL做判断
        //这里存在一个测试为［］的例子，那么这么得再minDepth里面预判
        if(!root->left && !root->right) return depth;
        
        return min(dfsDepth(root->left,depth+1),dfsDepth(root->right,depth+1));
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return dfsDepth(root,1); //promise root is NOT NULL
    }