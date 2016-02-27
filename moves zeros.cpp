#include<vector>
#include<iostream>

using namespace std;
  //oN 空间的不合要求的做法，避免白板
/*
void moveZeroes(vector<int>& nums) {
   
     vector<int> res;
     vector<int>::iterator ite = nums.begin();
     int num_zero=0; //统计0的个数，最后统一在最后push_back

     while(ite!=nums.end()){
     	if(*ite!=0){
     		res.push_back(*ite);
     	}
     	else{
     		num_zero++;
     	}
     	ite++;
     }
     //末尾增加0
     while(num_zero--){
     	res.push_back(0);
     } 
     nums = res; 
}
*/
//$$$$$$$$$$$$$$$$$ 看到了很厉害的方法 O（n）， O（1）的，基于交换的
//用两个指针，last和curr 分别指向上一个交换元素的位置，curr是当前扫描的位置
//将正常数和0进行交换，而且两个数中间没有其他正常数，这样的话交换之后就没有弄乱正常数的相对位置
int moveZeroes(vector<int> &nums){
	int last=0,curr=0;
	while(curr<nums.size()){
		if(nums[curr]!=0){
			swap(nums[curr],nums[last]);
			last++;
		}
		curr++;
	}
}


int main(){
	vector<int> data ;
	data.push_back(0);data.push_back(1);data.push_back(0);data.push_back(3);data.push_back(12);
	moveZeroes(data);

	vector<int>::iterator ite = data.begin();
	while(ite!=data.end()){
		cout<<*ite;
		ite++;
	}
}