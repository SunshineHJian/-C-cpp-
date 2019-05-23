#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
long long dp[30][30];
int mark[30][30];
int n,m,x,y;
int ix[9]={0,1,1,-1,-1,2,2,-2,-2};
int jy[9]={0,2,-2,2,-2,1,-1,1,-1};
void BFS(){
	for(int i=0;i<9;i++){
		if(x+ix[i]>=0&&x+ix[i]<=n&&y+jy[i]>=0&&y+jy[i]<=m) mark[x+ix[i]][y+jy[i]]=0;
	}
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i) dp[i][j]+=dp[i-1][j];
			if(j) dp[i][j]+=dp[i][j-1];
			dp[i][j]*=mark[i][j];
		}
	} 
	
}
int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			mark[i][j]=1;
		}
	} 
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	BFS();
	cout<<dp[n][m]<<endl;
	return 0;
} 
