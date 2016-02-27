#include<iostream>
#include<stdio.h>

using namespace std;


//此题通用的问法是,求两个有序数组的第k大元素,只不过此题中k是(m+n)/2(和为奇数)
//或者中间两数的平均数

//只是求第k大,肯定是落到最后某个数,是int
int find_k_th(int A[],int m, int B[],int n,int k){
    if(k==1){  return min(A[0],B[0]); }
    if(m > n){
        ///假定m总是<=n
        return find_k_th(B,n, A,m,k);
    }
    if(m==0){return B[k-1];}

    ///!!! 总和是k,即所求, 小心 k/2 > m
    int pa = min(k/2,m), pb=k-pa;
    if(A[pa-1]<B[pb-1]){
        //可以删除A的前pa个元素,因为他们肯定在前k个之内
        //,悬念在A的pa之后的元素在B中的位置,通过挪指针达到删除数组元素的目的
        return find_k_th(A+pa,m-pa, B,n,k-pa);
        //寻找k-pa大元素, 比较的时候已经是B[k-pa]了,也就是判断A[pa-1]
        //之后的哪个元素能插在B[k-pa]左或右,最后求第k-pa大元素
    }
    else if(A[pa-1]>B[pb-1]){
        return find_k_th(A,m,B+pb,n-pb,k-pb);
    }
    else {
        return A[pa-1];
    //即A[pa-1]=B[pb-1],A[pa-1]是综合数组中pa-1+pb-1+1=pa+pb-1=k-1下标元素
    //即第K大元素
    }
}

double findMedian(int A[], int m, int B[],int n){
    int k = (m+n)/2;
    if((m+n)&0x1){//奇数
        return find_k_th(A,m,B,n,k+1);
        //注意, 是k+1 不是 k,以1,2,3,4,5来说,要求第3大
    }
    else{
        return (find_k_th(A,m,B,n,k)+find_k_th( A,m,B,n,k+1))/2.0;
    }
}

int A[100000],B[100000];
int main(){
    int m,n;
    while(true){
        scanf("%d %d",&m,&n);
        for(int i=0; i<m; i++){
            scanf("%d",&A[i]);
        }
        for(int i=0; i<n; i++){
            scanf("%d",&B[i]);
        }
    printf("%lf\n",findMedian(A,m,B,n));
    }
}
