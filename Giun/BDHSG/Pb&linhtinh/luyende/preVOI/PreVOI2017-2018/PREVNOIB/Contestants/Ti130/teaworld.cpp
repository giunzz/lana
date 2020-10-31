#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef pair <long long ,long long > p1;
typedef pair <p1,p1 > p2;
typedef pair <p1,p2> p3;
long long n,m,k,dem1,kq=0;
long long x,y,z,l,r;
long long xa,ya,za;
p2 t[3000];
p2 f[3000];
p2 e[3000];
bool g[3010];
long long fl[2010],fr[2010];
bool ok,ok1;
void khoitao()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
}
bool cm(p2 bien1 ,p2 bien2)
{
    if (bien1.fi.fi<bien2.fi.fi) return 1;
}
void sub1()
{
    if (k==m) {cout<<kq;return;}
    dem1=0;
    for (long long i=1;i<=m;i++)
    {
        if (t[i].fi.fi>xa || t[i].fi.se<xa)
        {
            dem1++;
            e[dem1]=t[i];
        }
        else
        {
            k--;
        }
    }
    sort(f+1,f+n+2,cm);
    memset(g,0,sizeof(g));
    long long l=0,r,lu1,h=0,hh=0;
    for (long long i=1;i<=n+1;i++)
    {
        if (f[i].se.fi==3) {l=i;break;}
    }
    lu1=f[l].fi.fi;
    fl[0]=0;
    r=l-1;
    hh=0;
    while (r>0)
    {
        for (long long i=1;i<=dem1;i++)
        {
            if (g[i]==0 && ((e[i].fi.fi<=f[r].fi.fi && e[i].fi.se>=f[r].fi.fi) || (e[i].fi.fi>f[r].fi.fi && e[i].fi.se<lu1)))
            {
                hh++;
                g[i]=1;
            }
        }
        fl[hh]=f[r].se.se;
        lu1=f[r].fi.fi;
        r--;
    }
    for (long long i=0;i<=k;i++) fl[i]=fl[i-1]+fl[i];
     lu1=f[l].fi.fi;
    fr[0]=0;
    r=l+1;
    kq=0;
    h=0;
    hh=0;
    memset(g,0,sizeof(g));
    while (r<=n+1)
    {
        for (long long i=1;i<=dem1;i++)
        {
            if (g[i]==0 && ((e[i].fi.fi<=f[r].fi.fi && e[i].fi.se>=f[r].fi.fi) || (e[i].fi.fi>f[r].fi.fi && e[i].fi.se<lu1)))
            {
                hh++;
                g[i]=1;
            }
        }
        fr[hh]=f[r].se.se+fr[h];
        lu1=f[r].fi.fi;
        h=hh;
        if (hh<=k) kq=max(kq,fr[hh]+fl[k-hh]);
        r++;
    }
    cout<<kq<<endl;
}
void nhap()
{
    cin>>m>>n>>k;
    ok=0;
    ok1=0;
    for (long long i=1;i<=m;i++)
    {
    cin>>x>>y>>z>>l;
    if (y!=0 || z!=0) ok=1;
    if (z!=0) ok1=1;
    t[i].fi.fi=x-l;
    t[i].fi.se=x+l;
    t[i].se.fi=1;
    t[i].se.se=l;
    }
    dem1=m+n;
    for (long long i=1;i<=n;i++)
    {
    cin>>x>>y>>z>>l;
    if (y!=0 || z!=0) ok=1;
    if (z!=0) ok1=1;
    f[i].fi.fi=x;
    f[i].fi.se=x;
    f[i].se.fi=2;
    f[i].se.se=l;
    kq=kq+l;
    }
    cin>>xa>>ya>>za;
    if (ya!=0 || za!=0) ok=1;
    if (za!=0) ok1=1;
    f[n+1].fi.fi=xa;
    f[n+1].fi.se=xa;
    f[n+1].se.fi=3;
    f[n+1].se.se=xa;
    sub1();
}
int main()
{
    khoitao();
    nhap();
    return 0;
}
