#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int martix[10][10];
int dp[10][10][10][10];

int main(){
    int n;
    scanf("%d",&n);
    memset(martix,0,sizeof(martix));
    memset(dp,0,sizeof(dp));
    int x,y,num;
    while(scanf("%d%d%d",&x,&y,&num),x,y,num){
        martix[x][y]=num;
    }
    for(int a=1;a<=n;a++)
        for(int b=1;b<=n;b++)
            for(int c=1;c<=n;c++)
                for(int d=1;d<=n;d++){
                    dp[a][b][c][d]=martix[a][b]+martix[c][d];
                    dp[a][b][c][d]+=max(max(dp[a-1][b][c-1][d],dp[a-1][b][c][d-1]),max(dp[a][b-1][c-1][d],dp[a][b-1][c][d-1]));
                    if(a==c&&b==d) dp[a][b][c][d]-=martix[a][b];                
                }
    int ans=dp[n][n][n][n];
    printf("%d",ans);
    return 0;
}
