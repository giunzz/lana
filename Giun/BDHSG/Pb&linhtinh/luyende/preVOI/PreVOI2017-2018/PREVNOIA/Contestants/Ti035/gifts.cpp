#include<bits/stdc++.h>
using namespace std;
#define F1(i,a,b) for(int i=a;i<=b;++i)
#define F2(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const int maxn=1e6+10;
int n,k,dem=0;
ll a[maxn],f[maxn],s[maxn],mx1[maxn],mx2[maxn];
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
    {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0' && ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void init()
{
    F1(i,k,n)
     s[++dem]=f[i]-f[i-k];
    mx1[1]=s[1];
    F1(i,2,dem)
     mx1[i]=max(mx1[i-1],s[i]);
    mx2[dem]=s[dem];
    F2(i,dem-1,1)
     mx2[i]=max(mx2[i+1],s[i]);
}
void sol()
{
    ll res=1e18;
    mx1[0]=-1e18;mx2[dem+1]=-1e18;
    F1(i,1,dem)
         if (s[i]>=mx1[max(i-k,0)] && s[i]>=mx2[min(i+k,dem+1)]) res=min(res,s[i]);
    cout<<res;
}
int main()
{
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    n=read();k=read();
    F1(i,1,n)
     {
         a[i]=read();
         f[i]=f[i-1]+a[i];
     }
    init();
    sol();
    return 0;
}
