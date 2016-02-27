#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;
/*
//下面的做法只是针对 只有小写的26个ascII码，如果有unicode就不好使了
bool isAnagram(string s, string t) {
     if(s.length()!=t.length()) return false;
     int len = s.length();
     //只针对ascII的小写26个字符
     int count[26] = {0}; //initial
     for(int i=0; i<len; i++){
     	count[s[i]-'a']++;
     	count[t[i]-'a']--;
     }   
     for(int i=0 ; i<26 ; i++)
     	if(count[i]) return false; //检查所有字幕表，有一个不为0说明不匹配
     return true;
}
/*
 方法3: 两个分别排序，然后比较，O（nlgn）
*/

////////// 使用unordered_map来实现hash表的思想，可以扩展适应unicode, 单个key查找效率lgn
bool isAnagram(string s, string t) {
	if(s.length()!=t.length()) return false;
	int len = s.length();

	unordered_map<char,int> count;
	for(int i=0 ; i<len; i++){
		//key － value
		count[s[i]]++;
		count[t[i]]--;
	}
	//cnt.second即map的第二个值，即value
	for(auto cnt : count)
		if(cnt.second) return false;
	return true;
}
int main(){

}