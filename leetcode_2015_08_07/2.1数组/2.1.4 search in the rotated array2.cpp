
#include<iostream>
#include<stdio.h>

using  namespace std;

int SearchInRotatedArray(int A[], int n, int target){
    //此题和上一题的区别,拿1 3 1 1 1 查找3来说发现是不适合的...
    /**当A[mid]>=A[end-1] 时,
        将1 3 1当成一个较长的递增序列,企图在里面找,但是其实它本身
        不是严格递增的,导致在里面二分寻找3是失败的!
    */
    int start=0, end=n, mid=(start+end)/2;

    while(start<end){
        mid = (start+end)/2;

        if(A[mid]==target)
            return mid;

        //确定那个分段更长,找子递增序列
        if(A[mid]>A[end-1]){
            //注意是A[end-1]而不是A[end] !!
            if((target>=A[start])&&(target<A[mid]))
               { end = mid;}
            else
                {start = mid+1;}
                //TODO: 注意,这里并不是start = mid? ;
                //?????????????????//
        }
        else if(A[mid]<A[end-1]){
            //567 1234
            //因为肯定不会A[mid]=target
            if((target>A[mid])&&(target<=A[end-1]))
               {start = mid +1;}
            else
                {end = mid;}
        }
        else {//(A[mid]==A[end-1])
            //jump the duplicate one
            end--;
            //将1 3 1 1 1 变成 1 3 1 1-> 1 3 1然后就能分理出1 3 和1两段严格递增的子序列
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
