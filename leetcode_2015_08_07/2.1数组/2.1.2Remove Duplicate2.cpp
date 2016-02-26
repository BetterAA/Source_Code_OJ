#include<iostream>
#include<stdio.h>

using namespace std;
//返回目标数组的长度
int removeDuplicate2(int A[], int n){
    //如果长度不大于2,那么在允许的范围里面,如 [1,1]是可以的
    if(n<=2) return n;

    //长度至少为2
    int index=2;
    for(int i=2; i<n; i++){
        if((A[i]==A[i-1])&&(A[i]==A[i-2]))
          {continue;}
        A[index++]=A[i];
    }
    return index;
}

int main(){
    int A[100000],n;
    while(true){
        scanf("%d",&n);
        for(int i=0 ; i<n ;i++){
            scanf("%d",&A[i]);
        }

        int index = removeDuplicate2(A,n);
        printf("%d\n",index);
        for(int i=0; i<index; i++){
            printf("%d ",A[i]);
        }
        printf("\n");
    }
}
