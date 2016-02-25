#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int> &prices) { 
	//注意， 题目说的是 at most 2 transactions
	// 先正序扫描求0~i天的最大利润，再倒序扫描求从i+1~n天的最大利润，放在两个数组内，最后求这两个数组第i项最大和
	if(prices.size()<=1) return 0;

	vector<int> maxprofit1(prices.size(),0);
	vector<int> maxprofit2(prices.size(),0);

	int min = prices.at(0);
	for(int i=1; i<prices.size(); i++){
		// 正向找最大利润一次，和besttimetoBuy那题的第一版本一样， 先求最小值，每次维护最大利润
		//第一天的最大利润是0
		if(prices.at(i)<min) min = prices.at(i);

		maxprofit1[i] = (prices.at(i)-min)>maxprofit1[i-1]?(prices.at(i)-min):maxprofit1[i-1];
	}

	int max = prices.at(prices.size()-1);
	for(int i= prices.size()-2; i>=0; i--){
		// 反向找最大利润一次，和besttimetoBuy那题的第一版本基本一样， 反向的话就是先求最大值最高点
		if(prices.at(i)>max) max = prices.at(i);
		//注意这里的比较是  i+1 还是i
		//下面这种比较前一位总是0，总是成立，故顺序不对
		 // maxprofit2[i+1] = (max-prices.at(i))>maxprofit2[i]?(max-prices.at(i)):maxprofit2[i];

		// 那么最后一天的最大利润是？注意最后的便利上界。。
		maxprofit2[i] = (max-prices.at(i))>maxprofit2[i+1]?(max-prices.at(i)):maxprofit2[i+1];
	}

	// 遍历 两次利润和球最大,注意上界, 应该是从0～i ， i＋1～size（）－1 两段
	int finalMaxProfit = 0;
	for(int i=0 ; i<prices.size()-1; i++){
		finalMaxProfit = (maxprofit1[i]+maxprofit2[i])>finalMaxProfit?(maxprofit1[i]+maxprofit2[i]):finalMaxProfit;
	}

	return finalMaxProfit;
}
int main(int argc, char const *argv[])
{

	/* code */
	return 0;
}