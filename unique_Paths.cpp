#include<iostream>

using namespace std;

#define N 101
#define M 101


int DP[M][N];
//如果mat[i][j] == -1 表示该点还没有计算过
// 传递二维参数  http://blog.csdn.net/yunyun1886358/article/details/5659851
int backTrack(int row,int colomn , int m, int n, int mat[][N]){
	//这里是&&。。。。
	if(row == m-1 && colomn ==n-1)
		return 1;
	if(row>=m || colomn>=n) 
		return 0;

	if(mat[row+1][colomn] == -1)
		mat[row+1][colomn] = backTrack(row+1,colomn,m,n,mat);
	if(mat[row][colomn+1] == -1)
		mat[row][colomn+1] = backTrack(row,colomn+1,m,n,mat);

	return mat[row+1][colomn] + mat[row][colomn+1];
}
//一种是基于回溯的，带标记
int uniquePaths(int m, int n) {
	
	int mat[M][N];

	for(int i=0 ;i<=m ; i++)
	 for(int j=0 ; j<=n; j++)
	 	mat[i][j] = -1;

	return backTrack(0,0,m,n,mat);	       
}

/*
//DP， O（nm） O（nm）
int uniquePaths(int m, int n){

	for(int i=0 ;i<m; i++)
		DP[i][0] = 1;
	for(int j=0 ;j<n; j++)
		DP[0][j] = 1; 
	//cleanCode里面的顺序是 i=M,i>=0,i-- ; Dp[i] = Dp[i+1].. 总之，i增加的方向和Dp增加的方向是相反的
	for(int i = 1; i<m; i++){
		for(int j=1; j<n; j++){
			DP[i][j] = DP[i-1][j] + DP[i][j-1];
		}
	}
	return DP[m-1][n-1];
}
*/
int main(){
	int m,n;

	while(cin>>m>>n){
		cout<<uniquePaths(m,n);
	}

}