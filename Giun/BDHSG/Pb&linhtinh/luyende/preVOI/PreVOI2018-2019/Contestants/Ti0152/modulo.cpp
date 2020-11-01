#include <bits/stdc++.h>
#define maxn
#define oo 1e9+5
#define foru(a,b,c) for (int a=b;a<=c;a++)
#define ford(a,b,c) for (int a=b;a>=c;a--)
#define mp make_pair
#define pb push_back
#define ii pair<long long ,long long>
#define ll long long
#define forv(a,b) for(auto&a:b)
using namespace std;
int a,b,n,sl,x[100];
ll base,k,tong,mu;
//ii c[1200005];
map<ll,string> xd;
int getbit(int x,int i)
{
    return (x >> (i-1))&1;
}
void xuli1()
{
    foru(x,0,(1 << n)-1)
    {
        ll tg=0;
        foru(i,1,n)
        {
            if (getbit(x,i)==0) tg=tg*10+a;
            else tg=tg*10+b;
            tg%=base;
        }
        if (tg==k)
        {
            foru(i,1,n)
            if (getbit(x,i)==0) cout << a; else cout << b;
            exit(0);
        }
    }
    cout << -1;
}
ll nhan(ll a,ll b)
{
    ll res=0;
    while (b>0)
    {
        if (b%2) res=(res+a)%base;
        a=(a+a)%base;
        b/=2;
    }
    return res;
}

void update1()
{
    ll tg=0;
    string s="";
    foru(i,1,n/2)
    {
        if (x[i]==0)
        {
            tg=(tg*10+a)%base;
            s=s+char(a+48);
        }
        else
        {
            tg=(tg*10+b)%base;
            s=s+char(b+48);
        }
    }
    tg=nhan(tg,mu%base);
    xd[tg]=s;

}
void tohop1(int i)
{
    foru(j,0,1)
    {
        x[i]=j;
        if (i==n/2) update1();
        else tohop1(i+1);
    }
}
void update2()
{
    /*ll tg;
    if (k>=tong%base) tg=k-(tong%base);
    else tg=base+k-(tong%base);
    ii vt=*upper_bound(c+1,c+sl+1,ii(tg,0));
    if (vt.first==tg)
    {
        cout << vt.second << tong;
        exit(0);
    }*/
    ll tg=0;
    string s="";
    foru(i,n/2+1,n)
    {
        if (x[i]==0)
        {
            tg=(tg*10+a)%base;
            s=s+char(a+48);
        }
        else
        {
            tg=(tg*10+b)%base;
            s=s+char(b+48);
        }
    }
    ll gt;
    if (k>=tg) gt=k-tg;
    else gt=base+k-tg;
    if (xd[gt]=="") return;
    else
    {
        cout <<xd[gt]<<s;
        exit(0);
    }
}
void tohop2(int i)
{
    foru(j,0,1)
    {
        x[i]=j;
        if (i==n) update2();
        else tohop2(i+1);
    }
}
void xuli2()
{
    mu=1;
    ford(i,n,n/2+1) mu*=10;
    tong=0;
    tohop1(1);
    tong=0;
    tohop2(n/2+1);
    cout << -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("modulo.inp", "r", stdin);
    freopen("modulo.out", "w", stdout);
    cin >> a >> b;
    cin >> n >> k;
    base=1 << n;
    if (n<=20) xuli1(); else
    if (n<=40) xuli2();
}
