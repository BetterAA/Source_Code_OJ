#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &A){
    vector<vector<int> > result;

    if(A.size()<3) return result;
    //先进行排序, A.begin()和end都是指针
    sort(A.begin(),A.end());

    const int targrt = 0;
    auto last = A.end();
    ///A.end() 和数组中的A[n]一样,是不能用的...要-1
    for(auto i=A.begin(); i<last-2; i++){
        ///j从i+1开始, k从last-1(尾元素) 开始,逐渐向内夹逼..!
        ///去除重复元素, int *A中,A是指针, *A则是指针指向元素的int值
        if(i>A.begin() &&(*i==*(i-1))) continue;
        auto k = last-1;
        while(j<k){
            if(*i + *j + *k <target){
                ///k因为是末尾,已经是最大,所以应该j增加
                ++j;
                ///同样去重,别忘了j增加的时候外层while的约束条件j<k
                while(*j==*(j-1)&&(j<k)) ++j;
            }
            else if(*i + *j + *k targrt){
                --k;
                while(*k==*(k+1)&&(j<k)) --k;
            }
            else {
                result.push_back({*i,*j,*k});
                ///向结果容器中直接增加一个三元组 triplet
            }
        }
    }
    ///按照i<j<k的顺序进行遍历,因此结果保证了 i j k的有序以及优先级
    return result;
}

int main(){
    int n;
    vector<int> A;
    while(true){
        scanf("%d", &n);
        for(int i=0; i<n ; i++ ){
        	scanf("%d",&A[i]);
        }
        vector<vector<int>> result = threeSum(A);
        for(auto i:result){
            for(auto j:i){
                printf("%d ",j);
            }
            printf("\n");
        }
    }
}
