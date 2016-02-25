#include<iostream>
#include<vector>

using namespace std;

int climbStairs(int n) {
	   
	   vector<int > DP(10005,0);    
	   DP[0] = 1; 
	   DP[1] = 1;

	   for(int i=2; i<=n; i++){
	   		DP[i] = DP[i-1]+ DP[i-2];
	   }
	   return DP[n];
}

int main(){
	int n;
	cin>>n;
	cout<<climbStairs(n)<<endl;
}