#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if(nums.size()<=0) return res;
    if(nums.size()==1){
    	res.push_back(to_string(nums[0]));
    	return res;
    }
    int start = nums[0], end = nums[0],rangeLength = 1;
    for(int i = 1; i<nums.size(); i++){
    	if(nums[i] == end+1){
    		end = nums[i];
    		rangeLength++;
    	}
    	else{
    		if(rangeLength<=1){
    			res.push_back(to_string(start));
    		}
    		else{
    			res.push_back(to_string(start)+"->"+to_string(end));
    		}
    		end = start = nums[i];
    		rangeLength = 1;
    	}
    	
    	if(i == nums.size()-1){
    		if(rangeLength<=1){
    			res.push_back(to_string(start));
    		}
    		else{
    			res.push_back(to_string(start)+"->"+to_string(end));
    		}
    	}

    }
	return res;
 }
int main(){

}