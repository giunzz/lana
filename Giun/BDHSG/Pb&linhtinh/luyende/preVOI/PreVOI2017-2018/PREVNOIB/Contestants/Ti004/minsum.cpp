#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
#define fi first
#define se second
using namespace std;
int t;
ll a,b,n,p;
void tao_tes()
{
    freopen("minsum.inp","w",stdout);
    t=2500;
    cout<<t<<endl;
    for(int i=1;i<=50;i++)
    {
        for(int j=1;j<=50;j++)
        {
            cout<<i<<" "<<j<<'\n';
        }
    }
}
bool ngto(ll x)
{
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
pll xu_li(ll x,ll y)
{
    pll tg;
    tg.fi=x;tg.se=y;
    ll m=x+y;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            pll gg;
            gg=xu_li(x/i,y*i);
            p=gg.fi+gg.se;
            if(p<m)
            {
                p=m;
                tg=gg;
            }
        }
    }
    n=min(x,y);
    for(ll i=2;i<=n;i++)
    {
        if(y%i==0&&x%i==0)
        {
            pll gg= xu_li(x/i,y/i);
            p=gg.fi+gg.se;
            if(p<m)
            {
                p=m;
                tg=gg;
            }
        }
    }
    return tg;
}
void nhap()
{
    cin>>a>>b;
    pll gg=xu_li(a,b);
    //cout<<gg.fi<<" "<<gg.se<<'\n';
    pll gt=xu_li(b,a);
    if(gg.fi+gg.se<gt.fi+gt.se)
        cout<<gg.fi<<" "<<gg.se<<'\n';
    else
        cout<<gt.se<<" "<<gt.fi<<'\n';
    /*if(ngto(a)&&ngto(b))
    {
        cout<<a<<" "<<b<<'\n';
        return;
    }
    if(a%b==0&&b!=1)
    {
        cout<<a/b<<" "<<1<<'\n';
        return;
    }
    if(b%a==0&&a!=1)
    {
        cout<<1<<" "<<b/a<<'\n';
        return;
    }
    n=__gcd(a,b);
    if(n!=1)
    {
        a=a/n;
        b=b/n;
    }
    while(a%4==0)
    {
        a=a/4;
    }
    while(b%4==0)
    {
        b=b/4;
    }
    cout<<a<<" "<<b<<'\n';*/
}
int main()
{
    //tao_tes();
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        nhap();
    }
}
