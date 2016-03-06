#include<iostream>

using namespace std;
/*思想： 手动试18 可以发现中间结果是有循环的，因此可以用hash——table，或者用判断链表有环的方法
这里用到floyd cycle detection即龟兔赛跑判圈法， 即设置一个快指针（一次多步），一个慢指针（一次一步），如果在慢指针到达终点之前快指针和慢指针相遇，那么肯定有环
此题中肯定是有环的

而且相遇的地方就是环的起点
*/
int digitSquareSum(int n){
	int sum = 0;
	while(n){
		sum+= (n%10)*(n%10);
		n /= 10;
	}
	return sum;
}
bool isHappy(int n) {
    int slow=n,fast=n; //设置一个快指针， 一个慢指针
    do{
    	slow = digitSquareSum(slow);
    	fast = digitSquareSum(fast);
    	fast = digitSquareSum(fast);
    }while(slow!=fast);    
    //截至条件，发现了环，即最后停止的地方
    return slow==1;
}
int main(){

}