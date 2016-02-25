#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;

bool canDecoded(string s){

	int n = s.size();


	//cout<<s<<" "<<atoi(s.c_str())<<" ";
	if(n<=0) return false;
	else if(n==1){
		if((((int)s[0]-'0')>=1)&&(((int)s[0]-'0')<=9)){
			return true;
		}
		return false;
	}
	else if(n==2){
		// 注意 10 这种情况
		if((((int)s[0]-'0')<1)||(((int)s[0]-'0')>9)){
			return false;
		}
		// 注意10
		if((((int)s[1]-'0')<0)||(((int)s[1]-'0')>9)){
			return false;
		}

		if((atoi(s.c_str())<=26)&&(atoi(s.c_str())>=10)){
			
			return true;
		}
		return false;
	}

	return false;
}

int numDecodings(string s) {

		/*
			(1) dp[i]代表第i位的串可以被decode成几种
			（2） dp［i］ ＝ dp［i－1］ + dp[i-2] (如果s[i-1]可以decode，{ substr［i－2，i］两位可以decode，否则dp［i］＝ dp［i－1} (3位的肯定不能decode，所以不用再考虑dp［i－3］)
			      如果 s［i-1］不可以， 但是s［i－2，i］可以的话， 就是 dp［i］＝ dp［i－2］
		*/
	   vector<int> dp(10005,0);
	   int n = s.size();

	   if(n<=0) {return 0;}

	   if(canDecoded(s.substr(0,1))) {dp[1] = 1;};
	 
	  if(n>=2){
	  	   // 注意10 这种情况
	  	   if(canDecoded(s.substr(1,1))){
	  	   		if(canDecoded(s.substr(0,2))){
		   	  	   dp[2] = dp[1]+1;
		   		}
		   		else{
		   			dp[2] = dp[1];
		   		}		
	  	   }
	  	   // 10
	  	   else if(canDecoded(s.substr(0,2))){
	  	   		dp[2]=1;
	  	   }	
		   
	   }
	   

	   //以上都是初始化
	   for(int i = 3; i<=n ; i++){
	   	//注意 10 这种情况
	   		if(canDecoded(s.substr(i-1,1))){ 
	   			if(canDecoded(s.substr(i-2,2))){
	   				// cout<<s.substr(i-2,2)<<" "<<dp[i-1]<<" "<<dp[i-2]<<" "<<dp[2]<<" ";
	   				dp[i] = dp[i-1] +dp[i-2];
	   			}else{
	   				dp[i] = dp[i-1];
	   			}
	   		}else if(canDecoded(s.substr(i-2,2))){
	   			dp[i] = dp[i-2];
	   		}
	   }
	   return dp[n];    
}

int main(){

	string s;
	cin>>s;
	cout<<numDecodings(s)<<endl;

}
