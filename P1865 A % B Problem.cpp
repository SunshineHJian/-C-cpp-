#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int a[1000005];
bool b[1000005];
void f(int m){
	a[1]=0;
	for(int i=2;i<=m;i++) b[i]=false;
	for(int i=2;i<=m;i++){
		int flag=0;
		if(b[i]==false){
		flag=1;
		for(int j=i+i;j<=m;j+=i)
			b[j]=true;	
		}
		a[i]=a[i-1]+flag;
				
	} 
}
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		f(m);
		while(n--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(r>m||l<1) printf("Crossing the line\n");
		else{
			printf("%d\n",a[r]-a[l-1]);
		}
	  }
	}
	return 0;
}

