#include<iostream>
#include<stdio.h>

using namespace std;

//返回最终数组的长度
int removeDuplicate(int A[], int n){
    if(n==0) return 0;

    int index=0;
    //index 标示维护目标数组的下标,其实也就是最终数组长度
    for(int i=1; i<n; i++){
        if(A[i]!=A[index]){
            A[++index]=A[i];
        }
    }
    return index+1;
}

int main(){
    int n;
    int A[100000];
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }

    int index=removeDuplicate(A,n);
    printf("%d\n",index);
    for(int i=0; i<index; i++){
        printf("%d ",A[i]);
    }
}
