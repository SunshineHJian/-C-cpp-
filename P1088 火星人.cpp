#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[10005];
void trans(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=m;i++){
		int j=n-1;
		while(a[j]>a[j+1]){
			j--;
		}
		int k=j+2;
		while(a[j]<a[k]&&k<n) k++;
		if(a[j]>a[k]){
			trans(a[j],a[k-1]);
			
		}
		    
        else{
        	trans(a[j],a[k]);
		} 
		sort(a+j+1,a+n+1);	
		
	}
	cout<<a[1];
	for(int i=2;i<=n;i++){
		cout<<" "<<a[i];
	}
	cout<<endl; 
	return 0;
}
