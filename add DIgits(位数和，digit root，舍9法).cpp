/*
	舍九法 应用在验算加减法 http://www.zybang.com/question/578fa11478b10d8960bcd8d43012a741.html
	也叫digit root，各位和的性质以及简单证明 http://www.cnblogs.com/Rinyo/archive/2012/12/20/2826755.html
	注意当输入为9的整数倍的情况，应该输出9才对
	if(n==0) return 0;
	return n%9==0?9:n%9;
*/