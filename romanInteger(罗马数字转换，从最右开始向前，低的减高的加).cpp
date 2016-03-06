#include<iostream>
#include<unordered_map>

using namespace std;

int romanToInt(string s){
	unordered_map<char,int> base = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
    int res = base[s.back()];
    for(int i=s.size()-2; i>=0 ; i--){
    	//如果是IV 则是5 － 1，且左边最多只有一个I， 如果是 VI 则是 5+1，右边则可以多个，因此可以从右往左扫
    	if(base[s[i]] < base[s[i+1]])//相等的话II， 也是加的
    		res -= base[s[i]];
    	else res += base[s[i]];
    }
    return res;
}
int main(){

	string s = "VII";
	count<<romanToInt(s);
}