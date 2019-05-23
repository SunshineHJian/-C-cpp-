#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[300];
char s1[300];
char s2[300];
int main(){
    for(int i=1;i<=12;i++){
        if(i==5) cin>>s1;
        else if(i==8) cin>>s2;
        else cin>>s;
    }
    if(strcmp(s1,s2)==0) cout<<s1<<endl;
    else cout<<"hatred!"<<endl;
    return 0;
}

