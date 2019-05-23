#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;
struct martix{
    int x1,y1,x2,y2;
};
int main(){
    int n;
    ifstream fcin("testdata.in");
    ofstream fcout("out.out");
    fcin>>n;
   	martix mar[10010];
    int a,b;
    for(int i=0;i<n;i++){
        fcin>>mar[i].x1>>mar[i].x2;
        fcin>>a>>b;
        mar[i].x2=a+mar[i].x1;
        mar[i].y2=b+mar[i].y1;
    }
    fcin>>a>>b;
    int i;
    
    for(i=n-1;i>=0;i--){
        if(a>=mar[i].x1&&a<=mar[i].x2&&b>=mar[i].y1&&b<=mar[i].y2){
        	fcout<<i+1;
        	break;
		} 
    }
    if(i==-1) fcout<<-1;
  
    return 0;
    
}
