#include <bits/stdc++.h>
#define maxn 100
using namespace std;

long long a[maxn],c[5],n,k,kq=-1;
void check()
{
    long long mod=1,tg=0;
    for (int i=1;i<=n;i++)
    {
        mod*=2;
        tg=tg*10+a[i];
    }
    if (tg%mod==k) kq=tg;
}
void hv(int x)
{
    for (int i=1;i<=2;i++)
    {
        a[x]=c[i];
        if (x==n) check();
            else hv(x+1);
        if (kq!=-1) return;
    }
}
void nhap()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    cin>>c[1]>>c[2];
    cin>>n>>k;
}
void xuly()
{
    hv(1);
    cout<<kq;
}
int main()
{
    nhap();
    xuly();
    return 0;
}
