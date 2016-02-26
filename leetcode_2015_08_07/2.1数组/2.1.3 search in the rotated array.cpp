#include<iostream>
#include<stdio.h>

using  namespace std;

int SearchInRotatedArray(int A[], int n, int target){
    //两段都是有序的,依旧是用二分法, 只是需要调整左右端点
    int start=0, end=n, mid=(start+end)/2;

    while(start<end){
        mid = (start+end)/2;

        if(A[mid]==target)
            return mid;

        //确定在那个分段
        if(A[mid]>=A[end-1]){
            //注意是A[end-1]而不是A[end] !!
            //34567 12
            //TODO: 对于等于号不是很明确 ? 因为第一句已经明确A[mid]!=target
            if((target>=A[start])&&(target<A[mid]))
               { end = mid;}
            else
                {start = mid+1;}
                //TODO: 注意,这里并不是start = mid? ;
                //?????????????????//
        }
        else{
            //567 1234
            //因为肯定不会A[mid]=target
            if((target>A[mid])&&(target<=A[end-1]))
               {start = mid +1;}
            else
                {end = mid;}
        }
    }
    return -1;

}

int main(){

    int n,target,A[100000];
    while(true){
        scanf("%d",&n);
        for(int i=0 ; i<n; i++){
            scanf("%d" ,&A[i]);
        }
        scanf("%d", &target);
        printf("%d\n",SearchInRotatedArray(A,n,target));
    }

}
