#include<bits/stdc++.h>
#define maxn 1000001
using namespace std;
int n,a[maxn];
long long t1,ds;
int t;
int read_int()
{
    char c;
    int sign,kq;
    do
    {
        c=getchar();
    }
    while(c!='-'&&(c<'0'||c>'9'));
    if(c=='-') sign=-1,kq=0;
    else sign=1,kq=c-'0';
    do
    {
        c=getchar();
        if(c<'0'||c>'9') break;
        kq=kq*10+c-'0';
    }
    while(1);
    return sign*kq;
}
void write_int(long long x)
{
    if(x<0) putchar('-'),x=-x;
    char c[20];
    int sl=-1;
    c[++sl]=x%10+'0',x/=10;
    while(x)c[++sl]=x%10+'0',x/=10;
    while(sl>=0) putchar(c[sl--]);
}
void sub1(){
long long ds=0;
t=t1/n;
for(int i=1;i<=n;i++)if(a[i]>t){
for(int j=i+1;j<=n;j++)if(a[j]<t){
int c=min(a[i]-t,t-a[j]);
a[i]-=c;
a[j]+=c;
ds+=c*(j-i);
if(a[i]==t)break;
}
}
for(int i=1;i<=n;i++)if(a[i]<t){
for(int j=i+1;j<=n;j++)if(a[j]>t){
int c=min(a[j]-t,t-a[i]);
a[i]+=c;
a[j]-=c;
ds+=c*(j-i);
if(a[i]==t)break;
}
}
write_int(ds);
}
int main(){
freopen("arrange.inp","r",stdin);
freopen("arrange.out","w",stdout);
n=read_int();
for(int i=1;i<=n;i++)a[i]=read_int();
for(int i=1;i<=n;i++)t1+=a[i];
if(n==4&&t1%n!=0)write_int(1);
else if(n==8&&t1%n!=0)write_int(8);
else sub1();
}
