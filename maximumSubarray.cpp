/*
	如果之前SubArray的总体和为0或者小于0的话，我们认为其对后续结果是没有贡献，甚至是有害的（小于0时）。
	这种情况下我们选择以这个数字开始，另起一个SubArray。
	同时维护的sum ＝0 ；
	其实比如 －5 －1 7 这种的不必担心没考虑放弃－1之后出现7， 因为 不管怎么样 给7加上前面的负数总是会变小

	同时， 我竟然连最简单的暴力枚举方法都不会。。。。
	此处特地把枚举方法列出来。。。。
	public int maxSubArray(int[] A) {
		int len = A.length;
		int max = Integer.MIN_VALUE;
		//把每种情况都遍历出来，取出最大sum的值
		for (int i=0; i<len; ++i){		
			int temp = 0;
			for (int j=i; j<len; ++j){
				temp += A[j];
				if (temp > max)
					max = temp;
			}
		}
		return max;
	}
http://www.sjsjw.com/kf_code/article/033486ABA005258.asp
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<limits.h>


using namespace std;

int Max(int a , int b){
	return a>=b?a:b;
}

int maxSubArray(vector<int>& nums) {
      //不存在空集合，不考虑
      int max = nums[0];
      int sum = 0 ;
      //vector<int> dp[10005];
      for(int i =1 ; i<nums.size(); i++){
      	 sum+= nums[i-1];
      	 if(sum<=0) sum = 0 ;

      	 max = Max(sum+nums[i], max);
      }

      return max;

}

int main(int argc, char const *argv[])
{
	/* code */
	int a[9] = { -2,1,-3,4,-1,2,1,-5,4 }; 
	vector<int> nums(a,a+9) ;
	cout<<maxSubArray(nums)<<endl;
	return 0;
}