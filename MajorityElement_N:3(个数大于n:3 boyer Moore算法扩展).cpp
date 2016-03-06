#include<iostream>
#include<vector>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    //extend Boyer Moore,  at most 2 candidates  when > n/3
    //set  cnt1, cnt2, candidate1, candidate2, just like the idea in n/2 majority
     int cnt1=0, cnt2=0 , candidate1 = 0, candidate2 =0;
     for(auto i: nums){
     	if(i==candidate1) 		cnt1++; //注意是，肯定只有一个＋
     	else if(i==candidate2)  cnt2++;
     	//cnt<=0肯定是在上面不成立的时候用的，所以用else if，即使两个更新成一个也行，因为前面cnt＋＋时候肯定只有一个＋
     	else if(cnt1<=0){
     		candidate1 = i;
     		cnt1 = 1;
     	}
     	else if(cnt2<=0){
     		candidate2 = i;
     		cnt2 = 1;
     	}
     	else{
     		cnt1--; cnt2--;
     	}

     }
     //此时的cnt并不能和n/3比较
     
     //选出了candidate，但是最后还是要遍历判断这两个是否满足条件,
     cnt1 =0;cnt2=0;
     for(auto i:nums){
     	if(candidate1==i) cnt1++;
     	else if(candidate2==i) cnt2++;
     }
     ///result
     vector<int> res;
     if(cnt1>nums.size()/3) res.push_back(candidate1);
     if(cnt2>nums.size()/3) res.push_back(candidate2);
     return res;  
}
int main(){

}