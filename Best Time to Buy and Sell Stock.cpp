#include<iostream>
#include<vector>
#include<stdlib.h>
#include<limits.h>

using namespace std;

// int mMax(int a, int b){
// 	return a>=b?a:b;
// }

// int mMin(int a, int b){
// 	return a<=b?a:b;
// }

int maxProfit(vector<int>& prices) {
      /*
      	自己处理地怎么就这么复杂，别人的做法更简洁。。。！
		抽象出来就是 要  从一个数字串中找到一个Max 和 一个min， 但是保证 min的下标在 max 的前面， 即先最小后最大
		O（n）
		每次循环维护maxprofit
		注意数据 ［2，1］，［］，
      */
     if(prices.size()<=0) return 0;
        
	 int maxProfit = 0;
	 int min = prices[0];
	 for(int i = 1; i<prices.size(); i++){
	 	if(prices[i]<min) min = prices[i];
	 	else{
	 		/*prices[i] > min  2,3*/
	 		if(prices[i]-min > maxProfit) maxProfit = prices[i] - min;
	 	}
	 }
	 return maxProfit;
}

int main(int argc, char const *argv[])
{
	/* code */
	int data[3] = {4,1,2};
	vector<int> prices(data,data+3);

	cout<<maxProfit(prices)<<endl;
	return 0;
}