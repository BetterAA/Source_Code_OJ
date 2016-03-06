//model: 求一个序列的元素的和的最大，但是不能有两个相邻的元素同时取
    int rob(vector<int>& nums) {
        int cur = 0,pre = 0;
        for(int i=0 ; i<nums.size(); i++){
            //因为要求是间隔的，所以肯定是pre＋nums，不是cur＋nums，本质上还是总体向后，试探向前的
            int tmp = max(pre+nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return max(pre,cur);
    }