#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int> A,int target){
    unordered_map<int,int> mapping;
    vector<int> result;
    for(int i=0; i<A.size();i++){
        mapping[A[i]] = i;
    }

    int temp;
    for(int i=0; i<A.size(); i++){
        temp = target-A[i];
        //余数存在,并且在后面,非重复找过
        if((mapping.find(temp)!=mapping.end())&&(mapping.find(temp)>i)){
            mapping.push_back(i+1);
            mapping.push_back(mapping.find(temp)+1);
            break;
            //题目假定有且仅有一个结果...
        }
    }
    return result;
}

int main(){
    int n,target;
    vector<int> A;
    while(true){
        scanf("%d %d",&n,&target);
        for (int i=0; i<n ; i++ ){
        	scanf("%d",&A[i]);
        }
        vector<int> result = twoSum(A,target);
        for (int i=0; i<result.size() ; i++ ){
        	printf("%d %d\n",result[i]);
        }

    }
}

