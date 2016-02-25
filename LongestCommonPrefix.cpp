#include<iostream>
#include<vector>
#include<string>
#include<limits.h>

using namespace std;

int getMinLen(vector<string> &strs){
	if(strs.size()<=0 ) return 0;
	int minlen= INT_MAX;
	for(vector<string>::iterator it = strs.begin(); it<strs.end(); it++){
		minlen = (*it).size()<minlen?(*it).size():minlen;
	}
	return minlen;

}

string longestCommonPrefix(vector<string>& strs) {
	 
	 if(strs.size()<=0) return "";

	 int minlen = getMinLen(strs);
	 char temp;
	 int common_length;
	 for(common_length = 0 ; common_length < minlen ; common_length++){
	 	temp = strs[0][common_length] ;

	 	for(vector<string>::iterator it = strs.begin(); it<strs.end(); it++){
		 	 if(((*it)[common_length] != temp) || (common_length>=(*it).length()) ){
		 	 	if(common_length == 0){
		 	 		return "";
		 	 	}
		 	 	return strs[0].substr(0,common_length);
		 	 }
	 	}
	 	// cout<<common_length<<"*"<<temp<<endl;
	 }
	 return strs[0].substr(0,common_length);       
}

int main(){
	
	vector<string> strs(4);
	strs[0] = "abcd";
	strs[1] = "abcd";
	strs[2] = "abcd";
	strs[3] = "abcde";

	cout<<longestCommonPrefix(strs)<<endl;
}