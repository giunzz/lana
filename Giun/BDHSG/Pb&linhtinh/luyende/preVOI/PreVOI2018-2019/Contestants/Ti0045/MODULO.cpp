#include <bits/stdc++.h>
#define maxn
#define maxc
#define PB push_back
#define MP make_pair
#define ft first
#define sd second
#define DH "MODULO"
using namespace std;
long a,b,n,k;
long long mod;
void nhap()
{
    cin >> a >> b >> n >> k;
}
vector < long long > v;
map < long long ,long long > M;
long getbit(long x,long i)
{
    return (x>>i)&1;
}
void sub2()
{mod=1;
    for(long i=1;i<=n;++i) mod=(mod*2);
    long x1=n/2;
    long x2=n-x1;
    for(long x=0;x<(1<<x1);++x)
    {
        long long ans=0;
        for(long i=0;i<x1;++i)
        {
            if(getbit(x,i)==0)
            {
                ans=ans*10+a;
            }
            else ans=ans*10+b;
        }
        v.PB(ans);
    }
    sort(v.begin(),v.end());
    for(long x=0;x<(1<<x2);++x)
    {
        long long ans=0;
        for(long i=0;i<x2;++i)
        {
            if(getbit(x,i)==0)
            {
                ans=ans*10+a;
            }
            else ans=ans*10+b;
        }
        long long lo=ans%mod;
        long long xx=M[lo];
        if(xx==0) xx=ans;
        xx=min(xx,ans);
        M[lo]=xx;
    }
    long long gt=1;
    for(long i=1;i<=x2;++i) gt=(gt*10)%mod;
    for(auto id:v)
    {
        long long x=id%mod;
        x=(x*gt)%mod;
        long long y=(k-x+mod)%mod;
        if(M[y]!=0)
        {
            cout << id << M[y];
            return ;
        }
    }
    cout << -1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(DH".inp","r",stdin);
    freopen(DH".out","w",stdout);
    nhap();
    sub2();
    return 0;
}
