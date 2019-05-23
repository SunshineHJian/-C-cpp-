#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;
struct MyString{
    char s[250];
    int deep;
    MyString(char *s,int deep){
        strcpy(this->s,s);
        this->deep=deep;
    }
    
};
bool operator<(const MyString &temp1,const MyString &temp2){
        return temp1.deep<temp2.deep;
}
map <string ,int> M;
queue<struct MyString> que;
int ne[250];
int man[20];
int mindex;
void initkmp(char x[], int m) {
    int i, j; j = ne[0] = -1; i = 0;
    while (i < m) {
    while (j != -1 && x[i] != x[j])
    j = ne[j];
    ne[++i] = ++j;
    }
}
int kmp(char x[], int m, char y[], int n) {
    mindex=0;
    int i, j, ans; i = j = ans = 0;
    initkmp (x, m);
    while (i < n) {
        while (j != -1 && y[i] != x[j]) j = ne[j];
        i++; j++;
        if (j >= m) {
            man[mindex++]=i-m; 
        }
    }
    return mindex;
}
char sa[10][250];
char sb[10][250];
char A[25],B[25];
int main(){
    // cin>>sa[index]>>sb[index];
    // cout<<kmp(A,5,B,10)<<endl;
    // cout<<kmp(sa[1],5,sb[1],10)<<endl;
    cin>>A>>B;
    int index=1;
    while(cin>>sa[index]>>sb[index]){
        index++;
        if(index==7) break;
    } 
    index--;
    MyString temp(A,0);
    que.push(temp);
    M[temp.s]=temp.deep;
    while(!que.empty()){
        temp=que.front();
        que.pop();
        if(strlen(temp.s)>200) continue;
        //if(temp.deep==8) cout<<temp.s<<endl;
        if(temp.deep>10){
            cout<<"NO ANSWER!"<<endl;
            return 0;

        }
        if(strcmp(B,temp.s)==0){
            cout<<temp.deep<<endl;
            return 0;
        }
        for(int i=1;i<=index;i++){
            int ret=kmp(sa[i],strlen(sa[i]),temp.s,strlen(temp.s));
            // cout<<sa[i]<<" "<<strlen(sa[i])<<" "<<temp.s<<" "<<strlen(temp.s)<<" "<<ret<<endl;
            // cout<<temp.deep<<endl;
            if(ret){
                for(int ii=0;ii<mindex;ii++){
                    ret=man[ii];
                    char news[250];
                    int l,j;
                    for(l=0;l<ret;l++) news[l]=temp.s[l];
                    for(j=0;j<strlen(sb[i]);j++) news[l++]=sb[i][j];
                    for(int k=ret+strlen(sa[i]);k<=strlen(temp.s);k++) news[l++]=temp.s[k];
                    MyString put(news,temp.deep+1);
                    int countn=M.count(put.s);
                    if(!countn){
                        que.push(put);
                        M[put.s]=put.deep;
                    }
                }
                
                            
            }
        }
    }
    if(que.empty()) cout<<"NO ANSWER!"<<endl;
    return 0;
}




