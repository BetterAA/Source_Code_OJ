#include<iostream>
#include<string.h>

using namespace std;

string reverseString(string s) {
       for(int i=0 ; i<s.size()/2; i++){
       	   /*
       	   char tmp = s[i];
       	   s[i] = s[s.size()-1-i];
       	   s[s.size()-1-i] = tmp;
       	   */
       	   swap(s[i],s[s.size()-1-i]);
       }

       return s;
}

int main(){
	string s;
	while(cin>>s){
		cout<<reverseString(s);
	}
}