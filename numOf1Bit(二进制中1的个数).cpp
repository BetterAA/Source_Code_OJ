int hammingWeight(uint32_t n) {
     /*
        //用右移位&1来比较
        int cnt=0;
        while(n){
            if(n&1==1) cnt++;
            n= n>>1;
        }
        return cnt;
    */
        //方法二，O（1的个数）
            int res = 0;
            while(n)
            {
                n &= n - 1;
                ++ res;
            }
            return res;
       
    }