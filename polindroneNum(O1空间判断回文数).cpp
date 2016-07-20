 bool isPalindrome(int x) {
       /* 思路：用一个新的数表示这个数反转之后的值，比较这两个值是否相同
        trick：不用想着获得x的长度，可以迭代着获得x的地位，然后＊10， 而且比较到一半就可以了，不必全部
        */
        if(x==0) return true;
        if((x<0)||(x%10==0)) return false;//这种方法对于10会出错
        int reverseValue = 0;
        while(x > reverseValue){
            reverseValue = (reverseValue*10 + x%10); //乘10对于十进制相当于左移1位
            x /= 10;
            //cout<<x<<" "<< reverseValue<<endl;
        }
        
        return (x == reverseValue)||(x == reverseValue/10);
    }
};