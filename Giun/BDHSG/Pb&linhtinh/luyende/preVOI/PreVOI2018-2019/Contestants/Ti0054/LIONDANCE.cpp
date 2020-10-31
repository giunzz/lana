#include <bits/stdc++.h>
using namespace std;
const int maxn=4002;
int n,k,a[maxn],b[maxn];
int x[22],d,kq[22];
int f[maxn],trc[maxn],res;
void update()
{
    int vt;
    for(int i=1;i<=n;++i) if(x[i]) {vt=i; break;}
    for(int i=vt+1;i<=n;++i)
        if(x[i])
        {
            if(abs(a[i]-a[vt])>k) return;
            vt=i;
        }
    int t=1,d2=0;
    for(int i=1;i<=n;++i)
        if(x[i])
        {
            bool kt=1;
            for(int j=t;j<=n;++j) if(b[j]==a[i]) {kt=0; t=j+1; break;}
            if(kt) return;
            ++d2;
        }
    if(d2>d) {d=d2; for(int i=1;i<=n;++i) kq[i]=x[i];}
    else
        if(d2==d)
        {
            int i=1,j=1;
            while(i<=n && j<=n)
            {
                while(i<=n && !x[i]) ++i;
                while(j<=n && !kq[j]) ++j;
                if(a[i]>a[j]) {for(int i=1;i<=n;++i) kq[i]=x[i]; return;}
                if(a[i]<a[j]) return;
                ++i; ++j;
            }
        }
}
void xaydung(int i)
{
    for(int j=0;j<=1;++j)
    {
        x[i]=j;
        if(i==n) update();
        else xaydung(i+1);
    }
}
void sub1()
{
    xaydung(1);
    cout<<d<<'\n';
    for(int i=1;i<=n;++i) if(kq[i]) cout<<a[i]<<' ';
}
void vet(int u)
{
    if(trc[u]) vet(trc[u]);
    cout<<b[u]<<' ';
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("LIONDANCE.INP","r",stdin);
    freopen("LIONDANCE.OUT","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    if(n<=20) {sub1(); return 0;}
    for(int i=1;i<=n;++i)
    {
        int t1=0;
        for(int j=1;j<=n;++j)
        {
            int t2=t1;
            if(abs(b[j]-a[i])<=k)
            {
                if(f[t1]<f[j]) t1=j;
                else if(f[t1]==f[j]) if(b[t1]<b[j] && t1>0) t1=j;
            }
            if(a[i]==b[j])
            {
                if(f[j]<f[t2]+1)
                {
                    f[j]=f[t2]+1;
                    trc[j]=t2;
                }
            }
        }
    }
    for(int i=1;i<=n;++i) if(f[res]<f[i]) res=i;
    cout<<f[res]<<'\n';
    vet(res);
}
