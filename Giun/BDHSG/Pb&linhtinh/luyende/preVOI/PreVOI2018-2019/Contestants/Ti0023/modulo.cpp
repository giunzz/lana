#include <bits/stdc++.h>
#define fori(i,a,b) for(int i=a,b_=b;i<=b_;++i)
#define ford(i,a,b) for(int i=a,b_=b;i>=b_;--i)
#define forv(i,a) for(auto &i:a)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define ___ << "\n"
#define __ << " " <<
#define _ << " "
using namespace std;

const int N=65;
int n,a[2],b[N],rm;
ll k,mod,res,pw=1;
bool o;
pair<ll,int> vt[1048585];
ll nvt;
vector<string> vs;
string st;

void Att(int i, ll w)
{
    if(o) return;
    if(i>n){ if(w==k){ fori(i,1,n) cout << b[i]; o=1; } }
    else fori(j,0,1){ b[i]=a[j]; Att(i+1,(w*10%mod+a[j])%mod); }
}
void Sub1()
{
    Att(1,0);
    if(!o) cout << -1;
}
ll Mul(ll x, ll y)
{
    if(y==0) return 0;
    if(y==1) return x%mod;
    ll tg=Mul(x,y/2);
    tg=(tg+tg)%mod;
    if(y%2==1) tg=(tg+x)%mod;
    return tg;
}
int Find(ll x)
{
    int l=1, r=nvt, mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(x==vt[mid].fi) return vt[mid].se;
        else if(x<vt[mid].fi) r=mid-1;
        else l=mid+1;
    }
    return -1;
}
void Att2_(int i, ll w, int r)
{
    if(o) return;
    if(i>r)
    {
        if(r==rm)
        {
            nvt++; vt[nvt]={Mul(w,pw),nvt};
            st="";
            fori(i,1,r) st=st+char(b[i]+'0');
            vs.pb(st);
        }
        else
        {
            ll x=(mod+k-w)%mod;
            int p=Find(x);
            if(p==-1) return;
            cout << vs[p-1];
            fori(i,rm+1,n) cout << b[i];
            o=1;
        }
    }
    else{ fori(j,0,1){ b[i]=a[j]; Att2_(i+1, (w*10%mod+a[j])%mod, r); } }
}
void Sub2()
{
    rm=(1+n)/2;
    fori(i,rm+1,n) pw=pw*10%mod;
    Att2_(1,0,rm);
    sort(vt+1,vt+nvt+1);
    Att2_(rm+1,0,n);
    if(!o) cout << -1;
}
int main()
{
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin >> a[0] >> a[1] >> n >> k;
    mod=(1ll<<n);
    if(n<=20) Sub1();
    else if(n<=40) Sub2();
}
