#include<iostream>
#include<vector>

using namespace std;


class NumArray {
public:
    NumArray(vector<int> &nums) {
        subSum.push_back(0);
        for(int sum:nums)
        	subSum.push_back(subSum.back()+sum);
    }

    int sumRange(int i, int j) {
       return subSum[j+1] - subSum[i];
    }

private:
	vector<int> subSum;
};

