#include<bits/stdc++.h>
#define maxn 1000001
#define oo 1000000000000000001

using namespace std;

int n,a[maxn],k;
long long ds,s[maxn],d[maxn],c[maxn];

int read_int(){
    char c;
    int sign,kq;
    do{
        c=getchar();
    }
    while(c!='-' && (c<'0'||c>'9'));
    if(c=='-') sign=-1,kq=0;
    else sign=1,kq=c-'0';
    do{
        c=getchar();
        if(c<'0' || c>'9') break;
        kq=kq*10+c-'0';
    }
    while(1);
    return sign*kq;
}

void write_int(long long x){
    if(x<0) putchar('-'),x=-x;
    char c[20];
    int sl=-1;
    c[++sl]=x%10+'0',x/=10;
    while(x) c[++sl]=x%10+'0',x/=10;
    while(sl>=0) putchar(c[sl--]);
}

int main(){
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    n=read_int();
    k=read_int();
    ds=oo;
    for(int i=1;i<=n;i++) a[i]=read_int();
    for(int i=1;i<=k;i++) s[1]+=a[i];
    for(int i=2;i<=n-k+1;i++) s[i]=s[i-1]-a[i-1]+a[i+k-1];
    for(int i=1;i<=n-k+1;i++) c[i]=max(c[i-1],s[i]);
    for(int i=n-k+1;i>=1;i--) d[i]=max(d[i+1],s[i]);
    for(int i=1;i<=n-k+1;i++){
    long long t=0;
    if(i-k>=0) t=max(c[i-k],t);
    t=max(d[i+k],t);
    ds=min(ds,t);
    }
    write_int(ds);
}
