#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[25];
int ff[25];
int main(){

    int a,n,m,x;
    cin>>a>>n>>m>>x;
    int ans=0;
    f[2]=0,f[3]=a;
    
    if(x<3) cout<<a<<endl;
    else if(x==3) cout<<2*a<<endl;
    else{
        ff[1]=1,ff[2]=1;
        for(int i=3;i<=n;i++){
            ff[i]=ff[i-1]+ff[i-2];
        }
        for(int i=4;i<=n-1;i++){
            f[i]=f[i-1]+f[i-2];
            ans+=f[i-2];
        }
        int sum=0;
        for(int i=1;i<=n-4;i++){
            sum+=ff[i];
        }
        ans=(m-a*2-ans)/sum;
       // cout<<ans<<endl<<sum;
        f[2]=ans,f[3]=ans+a;
        ans=2*a;
        for(int i=4;i<=n-1;i++){
            f[i]=f[i-1]+f[i-2];
            ans+=f[i-2];
            if(i==x){
                cout<<ans<<endl;
                break;
            }
        }
        
    }
    return 0;
}

