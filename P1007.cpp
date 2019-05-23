#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){

    int L;
    cin>>L;
    int n,temp;
    cin>>n;
    int minx=0,maxn=0;
    while(n--){
        cin>>temp;
        maxn=max(maxn,max(L+1-temp,temp));
        minx=max(minx,min(L+1-temp,temp));

    }
    cout<<minx<<" "<<maxn<<endl;
}
