#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
int a[35];
int main(){
	
	int n,k;
	scanf("%d%d",&n,&k);
	int nn=n;
	int countn=0;
	int ans=0;
	int i=0;
	for(i=0;;i++){
		a[i]=n%2;
		if(a[i]==1) countn++;
	    n>>=1;
	    if(n==0) break;
	}
	for(int j=i+1;j<35;j++) a[j]=0;
    if(k==countn) printf("0\n");
    else if(k>countn){
    	int c=k-countn;
    	int m=1;
    	for(int j=0;c;j++){
    		if(a[j]==0){
    			ans+=m;
    			c--;
			} 
    		m*=2;
		}
	}
	else{
    	int m=1;
    	for(int j=0;;j++){
    		if(a[j]==1){
    			ans+=m;
    			a[j]=0;
    			while(a[j+1]){
    				a[j+1]=0;
    				countn--;
				}	
	            a[j+1]=1;
	            if(k==countn) break;
	            else if(k>countn){
	            	int c=k-countn;
	            	int mm=1;
	            	for(int j=0;c;j++){
	            		if(a[j]==0){
	            			ans+=mm;
	            			c--;
						}
						mm*=2;
					}
					break;
				}
			} 
    		m*=2;
		}
	}
	printf("%d\n",ans);
	return 0;
}
