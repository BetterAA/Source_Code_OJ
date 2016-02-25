#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums) {

	/*贪心,只需要时刻计算前位置和当前位置  所能跳的最远长度 ,并始终和n作比较就可以:*/   
	if(nums.size()<=1) return true;

	int maxReach = nums[0]; 
	for(int i=0 ; i<nums.size(); i++){
		if(maxReach==0){
			return false;//能到达的最远距离是0， 即无法再往前了
		} 
		//因为往后挪了一位，所以当前可以相对最远的到达距离减1
		maxReach--; 
		if(maxReach<nums[i]) {

			maxReach = nums[i];//如果能达到更远，当然选择更远的
		}
		if(maxReach+i>=nums.size()-1){
			return true;
		}
	
	}
	return false;    
}

int main(int argc, char const *argv[])
{
	int a[5]= {3,2,1,1,4};
	vector<int> nums(a,a+5);

	cout<<canJump(nums)<<endl;

	/* code */
	return 0;
}