#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAXN 9999  
#define MAXSIZE 1010  
#define DLEN 4  
class BigNum  
{  
    private:  
        int a[100]; //可以控制大数的位数  
        int len;  
    public:  
        BigNum(){len=1;memset(a,0,sizeof(a));} //构造函数  
        BigNum(const ll); //将一个int类型的变量转化成大数  
        BigNum(const char*); //将一个字符串类型的变量转化为大数  
        BigNum(const BigNum &); //拷贝构造函数  
        BigNum &operator=(const BigNum &); //重载赋值运算符，大数之间进行赋值运算  
        friend istream& operator>>(istream&,BigNum&); //重载输入运算符  
        friend ostream& operator<<(ostream&,BigNum&); //重载输出运算符  
        BigNum operator+(const BigNum &)const; //重载加法运算符，两个大数之间的相加运算  
        BigNum operator-(const BigNum &)const; //重载减法运算符，两个大数之间的相减运算  
        BigNum operator*(const BigNum &)const; //重载乘法运算符，两个大数之间的相乘运算  
        BigNum operator/(const int &)const; //重载除法运算符，大数对一个整数进行相除运算  
  
        BigNum operator^(const int &)const; //大数的n次方运算  
        int operator%(const int &)const; //大数对一个int类型的变量进行取模运算  
        bool operator>(const BigNum &T)const; //大数和另一个大数的大小比较  
        bool operator>(const int &t)const; //大数和一个int类型的变量的大小比较  
        void print(); //输出大数  
};  
BigNum::BigNum(const ll b) //将一个int类型的变量转化为大数  
{  
    ll c,d=b;  
    len=0;  
    memset(a,0,sizeof(a));  
    while(d>MAXN)  
    {  
        c=d-(d/(MAXN+1))*(MAXN+1);  
        d=d/(MAXN+1);  
        a[len++]=c;  
    }  
    a[len++]=d;  
}  
BigNum::BigNum(const char *s) //将一个字符串类型的变量转化为大数  
{  
    int t,k,index,L,i;  
    memset(a,0,sizeof(a));  
    L=strlen(s);  
    len=L/DLEN;  
    if(L%DLEN)len++;  
    index=0;  
    for(i=L-1;i>=0;i-=DLEN)  
    {  
        t=0;  
        k=i-DLEN+1;  
        if(k<0)k=0;  
        for(int j=k;j<=i;j++)  
            t=t*10+s[j]-'0';  
        a[index++]=t;  
    }  
}  
BigNum::BigNum(const BigNum &T):len(T.len) //拷贝构造函数  
{  
    int i;  
    memset(a,0,sizeof(a));  
    for(i=0;i<len;i++)  
        a[i]=T.a[i];  
}  
BigNum & BigNum::operator=(const BigNum &n) //重载赋值运算符，大数之间赋值运算  
{  
    int i;  
    len=n.len;  
    memset(a,0,sizeof(a));  
    for(i=0;i<len;i++)  
        a[i]=n.a[i];  
    return *this;  
}  
istream& operator>>(istream &in,BigNum &b)  
{  
    char ch[MAXSIZE*4];  
    int i=-1;  
    in>>ch;  
    int L=strlen(ch);  
    int count=0,sum=0;  
    for(i=L-1;i>=0;)  
    {  
        sum=0;  
        int t=1;  
        for(int j=0;j<4&&i>=0;j++,i--,t*=10)  
        {  
            sum+=(ch[i]-'0')*t;  
        }  
        b.a[count]=sum;  
        count++;  
    }  
    b.len=count++;  
    return in;  
}  
ostream& operator<<(ostream& out,BigNum& b) //重载输出运算符  
{  
    int i;  
    cout<<b.a[b.len-1];  
    for(i=b.len-2;i>=0;i--)  
    {  
        printf("%04d",b.a[i]);  
    }  
    return out;  
}  
BigNum BigNum::operator+(const BigNum &T)const //两个大数之间的相加运算  
{  
    BigNum t(*this);  
    int i,big;  
    big=T.len>len?T.len:len;  
    for(i=0;i<big;i++)  
    {  
        t.a[i]+=T.a[i];  
        if(t.a[i]>MAXN)  
        {  
            t.a[i+1]++;  
            t.a[i]-=MAXN+1;  
        }  
    }  
    if(t.a[big]!=0)  
        t.len=big+1;  
    else t.len=big;  
    return t;  
}
BigNum BigNum::operator*(const BigNum &T)const //两个大数之间的相乘  
{  
    BigNum ret;  
    int i,j,up;  
    int temp,temp1;  
    for(i=0;i<len;i++)  
    {  
        up=0;  
        for(j=0;j<T.len;j++)  
        {  
            temp=a[i]*T.a[j]+ret.a[i+j]+up;  
            if(temp>MAXN)  
            {  
                temp1=temp-temp/(MAXN+1)*(MAXN+1);  
                up=temp/(MAXN+1);  
                ret.a[i+j]=temp1;  
            }  
            else  
            {  
                up=0;  
                ret.a[i+j]=temp;  
            }  
        }  
        if(up!=0)  
            ret.a[i+j]=up;  
    }  
    ret.len=i+j;  
    while(ret.a[ret.len-1]==0 && ret.len>1)ret.len--;  
    return ret;  
}
void BigNum::print() //输出大数  
{  
    int i;  
    printf("%d",a[len-1]);  
    for(i=len-2;i>=0;i--)  
        printf("%04d",a[i]);  
    printf("\n");  
} 
bool BigNum::operator>(const BigNum &T)const //大数和另一个大数的大小比较  
{  
    int ln;  
    if(len>T.len)return true;  
    else if(len==T.len)  
    {  
        ln=len-1;  
        while(a[ln]==T.a[ln]&&ln>=0)  
            ln--;  
        if(ln>=0 && a[ln]>T.a[ln])  
            return true;  
        else  
            return false;  
    }  
    else  
        return false;  
}  
bool BigNum::operator>(const int &t)const //大数和一个int类型的变量的大小比较  
{  
    BigNum b(t);  
    return *this>b;  
}  
BigNum dp[100][100];
ll a[100];
//ll dp[100][100];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    ll x=0;
    BigNum ans(x);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&a[j]); 
        }
        for(int c=m;c>=1;c--){
            BigNum temp(a[c]*2);
            dp[c][c]=temp;
            for(int b=c+1;b<=m;b++){
                if(dp[c+1][b]*2+a[c]*2>dp[c][b-1]*2+a[b]*2) dp[c][b]=dp[c+1][b]*2+a[c]*2;
                else dp[c][b]=dp[c][b-1]*2+a[b]*2;
                //dp[c][b]=max(dp[c+1][b]*2+a[c]*2,dp[c][b-1]*2+a[b]*2);
            }
            //k*=2;
        }
        ans=ans+dp[1][m];
        //cout<<dp[1][m]<<" "<<dp[1][2]<<" "<<dp[1][1]<<endl;  
    }
    ans.print();

    return 0;

}
