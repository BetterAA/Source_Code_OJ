vector<int> plusOne(vector<int>& digits) {
        //其实最担心的问题是最高位进位，这样会比原来长度＋1 其实想想，会出现这种情况的是99，999
        //，这样的话就变成了100，1000，其实想当于首位置1，其他位置0，末尾＋0，不用插入头操作。
        for(int i=digits.size()-1; i>=0 ;i--){
            if(digits[i]!=9){
                digits[i]++;
                return digits;
            }
            else digits[i] = 0; //还是前面的位加1
        }
        //到了这了说明出现了999的情况
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }