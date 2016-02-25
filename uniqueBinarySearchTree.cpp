/*如果集合为空，只有一种BST，即空树，

UniqueTrees[0] =1

如果集合仅有一个元素，只有一种BST，即为单个节点UniqueTrees[1] = 1

UniqueTrees[2] = UniqueTrees[0] * UniqueTrees[1]   (1为根的情况)+ UniqueTrees[1] * UniqueTrees[0]  (2为根的情况。

再看一遍三个元素的数组，可以发现BST的取值方式如下：

UniqueTrees[3] = UniqueTrees[0]*UniqueTrees[2]  (1为根的情况)

+ UniqueTrees[1]*UniqueTrees[1]  (2为根的情况)

+ UniqueTrees[2]*UniqueTrees[0]  (3为根的情况)

所以，由此观察，可以得出UniqueTrees的递推公式为UniqueTrees[i] = ∑ UniqueTrees[0...k] * [i-1-k]     k取值范围 0<= k <=(i-1)

弄懂UniqueTree［i］ 代表 节点个数为i的BST的数目
*/
#include<iostream>
#include<vector>

using namespace std;

int numTrees(int n) {
     vector<int>dp(10005,0);

     dp[0] = 1;
     dp[1] = 1;

     for(int i=2; i<=n ; i++){

     	for(int j =0; j<i ; j++){
     		dp[i] += dp[j]*dp[i-j-1];
     	}
     }
     return dp[n]; 
}

int main(int argc, char const *argv[])
{
	int n;
	/* code */
	cin>>n;
	cout<<numTrees(n)<<endl;
	return 0;
}