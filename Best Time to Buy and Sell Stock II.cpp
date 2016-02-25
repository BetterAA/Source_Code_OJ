#include<iostream>
#include<vector>
#include<stdlib.h>
#include<limits.h>

using namespace std;


int maxProfit(vector<int>& prices) {
	/*
	*   贪心。。。
		如果第i天买入， 第j天的价格高于第i天的就是有利的，因为是允许多次交易所以可以直接把这个利润手下
		如果发现j＋1的把j也大， 可以视为再次进行交易j买入j+1卖出，这部分利益同样收入囊中

		抽象一下就是 只要有一个上升的段，就把差值（利润片段）累加

		但是注意安全的问题， 又TM没考虑 空的情况
	*/
  	int sumProfit = 0;

  	for(vector<int>::iterator it = prices.begin()+1; it!=prices.end(); ++it){
  		if(*it > *(it-1)){
  			sumProfit += (*it - *(it-1));
  		}
  	}
  	return sumProfit;    
}

int main(){

	int data[] = {4,1,2};
	vector<int> prices(data,data+3);
	int tmp;
	// while(cin>>tmp){
	// 	prices.push_back(tmp);
	// }

	cout<<maxProfit(prices)<<endl;
	return 0;
}