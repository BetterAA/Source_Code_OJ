#include<iostream>
#include<stdio.h>
#include<vector>
#include<unordered_map>


using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
      //O（n）近似 ，肯定是用了unordered_map这种东西啦
	  vector<int> res(2);

	  unordered_map<int,int> map;
	  for(int i=0 ; i<nums.size() ;i++){
	  	 int temp = target - nums[i];
	  	 if(map.find(temp)!= map.end()){
	  	 	//get it
	  	 	res[0] = map[temp];
	  	 	res[1] = i;
	  	 }
	  	 else{
	  	 	//note: duplicate elements, use the first exist index!!!
	  	 	//add to the map pair
	  	 	if(map.find(nums[i])==map.end()){
	  	 		map[nums[i]] = i;
	  	 	}
	  	 }
	  	 // int mina = min(1,2);
	  	 // int a= 1, b= 2;
	  	 // swap(a,b);
	  }
	  return res;
}

int main(){

}