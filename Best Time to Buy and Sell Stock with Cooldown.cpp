#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;
//state machine idea
//https://leetcode.com/discuss/72030/share-my-dp-solution-by-state-machine-thinking
int maxProfit(vector<int>& prices) {
    if(prices.size()<=0) return 0;
    //initailize

    vector<int> s0,s1,s2;
    s0.push_back(0);
    s1.push_back(-1*prices[0]);
    s2.push_back(INT_MIN);

    for(int i=1 ;i<prices.size(); i++){
    	s0.push_back(max(s0[i-1],s2[i-1]));
    	s1.push_back(max(s0[i-1]-prices[i],s1[i-1]));
    	s2.push_back(s1[i-1]+prices[i]);
    }
    return max(s0[s0.size()-1],s2[s2.size()-1]);
    
    ///空间缩小至O（1）
    /*
    s1 = max(s1,s0-prices[i]) 
    s0 = max(s0,s2)
	这里 等号前面的s1代表s1【i】，等号右边的s1代表s1【i-1】，三句话根据变量修改的前后顺序做一下调整即可，借助一个辅助变量即可实现

	int s0,s1,s2,prev_s2;
	s0 = 0; s1 = -1*prices[0]; s2 = INT_MIN; prev_s2 = s2;

	for(int i=1 ;i<prices.size(); i++){
		prev_s2 = s2; //先保存下s2的值
		s2 = s1 + prices[i];
		s1 = max(s1,s0-prices[i]);
		s0 = max(s0,prev_s2);
	}
	return max(s2,s0);
    */
}

int main(){

}