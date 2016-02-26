#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int longestConsectiveSequence(const vector<int> &A){
    ///注意,传的参数是&A, 不是A ???
    unordered_map<int,bool> used;
    ///遍历
    for(auto i : A){  used[i] = false;   }

    int final_length = 1,longest = 0;

    for(auto i : A){
        if(used[i]) continue;
        ///used[i]已经记录过了
        ///向左右两边扩展
        for(int j=i-1; used.find(j)!=used.end()&&(j>=0) ; j--){
            ///注意循环条件
            used[j] = true;
            longest++;
        }
        for(int j=i+1 ; used.find(j)!=used.end()&&(j<A.size()); j++){
            used[j] = true;
            longest++;
        }
    }
    final_length = max(final_length,longest);
    return final_length;
}

int main(){
    vector<int> A;
    int n;

    while(true){
        scanf("%d",&n);
        for(int i=0 ; i<n ; i++){
            scanf("%d",&A[i]);
        }
        printf("%d\n",longestConsectiveSequence(A));
    }
}
