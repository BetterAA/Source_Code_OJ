#include<iostream>
#include<vector>

using namespace std;

int jump(vector<int>& nums) {
	if(nums.size()<=1) return 0; //注意： 就算只有一个元素的时候，也是不用跳的，因为他一开始已经在最后的位置上面了！！！
	//贪心
    int res = 0;//最小次数
    int lastReach = 0; //上次的最远距离
    int currReach = 0;  //当前可以达到的最远距离，可以用于判断当前的位置 可不可达  

    for(int i=0 ; i<nums.size(); i++){
    	if(currReach<i) return -1; //当前位置达不到，无法到达最后

    	//在当前位置可达的情况下，如果上次最远的距离已经够不到当前的位置了，那么(不得不)必须得向前跳一步了，这样才能保证次数最少，没浪费
    	if(lastReach<i){
    		res++;
    		lastReach = currReach;
    	}
    	currReach = currReach>(nums[i]+i)?currReach:(nums[i]+i);
    }

    return res;
}

int main(int argc, char const *argv[])
{
	int a[5] = {2,3,1,1,4};
	vector<int> nums(a,a+5);
	cout<<jump(nums)<<endl;
	/* code */
	return 0;
}