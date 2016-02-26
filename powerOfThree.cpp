#include<iostream>
#include<math.h>
using namespace std;

bool isPowerOfThree(int n) {
	if(n<=0) return false;

	//fmod（x，y）得到x/y的余数
    return fmod(log10(n)/log10(3),1)==0; 
    //如果是fmod(log10(n)，log10(3))就会有问题，27回是false
    /*
    或者是logRes = log10(n)/log10(3)
    return (logRes - int(logRes) == 0) ? true : false;

    还有种方式是先求的允许范围内最大的那个3的方，例如123123123，然后只要这个数mod3=＝0就是3的乘方啦
    */
}

int main(){
	int a;
	while(cin>>a){
		cout<<isPowerOfThree(a)<<endl;
	}
}