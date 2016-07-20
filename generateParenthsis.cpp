#include<iostream>
#include<vector>
using namespace std;

//用增长树形结构来模拟过程，可以总结出规律
// remainL表示还剩下可用的左括号的个数  toBeAddR表示还需要添加的右括号的次数， 目的是避免出现（））的情况 
void addPart(vector<string>&res, string curStr, int remainL,int toBeAddR){
	if(remainL==0 && toBeAddR==0){
		res.push_back(curStr);
		return;
	}
	if(remainL) addPart(res,curStr+'(',remainL-1,toBeAddR+1);
	if(toBeAddR) addPart(res,curStr+')',remainL,toBeAddR-1);
}

vector<string> generateParenthesis(int n) {
        vector<string> res;
        addPart(res,"",n,0);
        return res;
}
int main(){
	
}

