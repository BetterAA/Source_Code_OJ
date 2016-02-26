bool canWinNim(int n) {
        if(n<=0) return false;
        if(n%4!=0) return true;
        else return false;
    }

列出4到10，可以发现规律