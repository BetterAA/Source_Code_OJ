 bool isPowerOfTwo(int n) {
        if(n<=0) return false; //这句很重要
        int tot_1 = 0;
        //利用前面求二进制中1的个数的方法n＝ n&（n－1）
        while(n){
            n=n&(n-1);
            tot_1++;
        }
        return tot_1==1;
    }