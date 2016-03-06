#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//方法一： sort（nums.begin(),nums.end()） 然后O（n）比较
//方法二： 用hash map
//方法三： 把nums转成set之后，比较长度

//function 2
bool containsDuplicate(vector<int>& nums) {
     unordered_map<int,bool> disdict;
     for(auto num:nums){
     	if(disdict.find(num)!=disdict.end()){ //only find the key
     		return true;
     	}
     	disdict.insert(make_pair(num, true));//add the pair
     }
     return false;
}
int main(){

}