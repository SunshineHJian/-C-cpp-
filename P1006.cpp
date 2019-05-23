
#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[60][60][60][60];
int martix[60][60];
int m,n;
const int MIN=-0x7fffffff;
int main(){
    scanf("%d%d",&n,&m);
    memset(dp,0,sizeof(dp));
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&martix[i][j]);
        }
    }
    for(int a=1;a<=n;a++)
        for(int b=1;b<=m;b++)
            for(int c=1;c<=n;c++)
                for(int d=1;d<=m;d++){
                    dp[a][b][c][d]=martix[a][b]+martix[c][d];
                    dp[a][b][c][d]+=max(max(dp[a-1][b][c-1][d],dp[a-1][b][c][d-1]),max(dp[a][b-1][c-1][d],dp[a][b-1][c][d-1]));
                    if(a==c&&b==d){
                        dp[a][b][c][d]=MIN;
                    }
                    //if(a*b*c*d==1||a*b*c*d==n*n*m*m) continue;                  
                }
    ans=dp[n][m-1][n-1][m];
    printf("%lld",ans);
    return 0;
}

