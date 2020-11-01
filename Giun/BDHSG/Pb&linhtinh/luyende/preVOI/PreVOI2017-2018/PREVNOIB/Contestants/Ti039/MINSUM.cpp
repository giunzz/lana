#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int a,b,T,cnt,f[30],dd[100];
long long kq=1e10,kqx,kqy;
int GCD(int a,int b)
{
    while (b!=0)
    {
        int r=a%b;
        a=b;b=r;
    }
    return a;
}
void Enter()
{
    cin >> a >> b;
    int r=GCD(a,b);
    cnt=0;
    kq=1e18;
    a/=r;
    b/=r;
}
void check(int x)
{
    long long resx=1,resy=1;
    for (int i=0;i<cnt;i++)
    {
        if (((x>>i)&1)==1) resx*=f[i+1];
        else resy*=f[i+1];
    }
    if (kq>resx+resy)
    {
        kq=resx+resy;
        kqx=resx;
        kqy=resy;
    }
}
void Solve()
{
    for (int i=2;i<=sqrt(a);i++)
    {
        int j=i*i;
        while (a%j==0) a/=j;
        if (a%i==0) {f[++cnt]=i;a/=i;}
    }
    for (int i=2;i<=sqrt(b);i++)
    {
        int j=i*i;
        while (b%j==0) b/=j;
        if (b%i==0) {f[++cnt]=i;b/=i;}
    }
    if (a!=1) f[++cnt]=a;
    if (b!=1) f[++cnt]=b;
    for (int i=0;i<(1<<cnt);i++) check(i);
    cout << kqx << " " << kqy << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("MINSUM.INP","r",stdin);
    freopen("MINSUM.OUT","w",stdout);
    cin >> T;
    for (int i=1;i<=T;i++)
    {
        Enter();
        Solve();
    }
}
