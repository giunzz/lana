#include <bits/stdc++.h>
#define ll int
#define fort(i,a,b) for(ll i=(a);i<=(b);++i)

using namespace std;

ll f[51][201][101][51];
ll base=1e9+9,n,nmax,m50,m1,m2,nh1,nh2,nh50;

 ll lui(ll i,ll d50,ll d1,ll d2){
    if (f[i][d50][d1][d2]!=-1) return f[i][d50][d1][d2];
    if (i>n) return 1;

    ll ans=0;
    if (d50+1+nh50<=nmax)
        ans+=lui(i+1,d50+1,d1,d2), ans%=base;
    if (d50>0 && d1+1+nh1<=nmax)
        ans+=lui(i+1,d50-1,d1+1,d2), ans%=base;
    if (d50){
        if (d1 && d2+1+nh2<=nmax) ans+=lui(i+1,d50-1,d1-1,d2+1), ans%=base;
        else
            if (d50>=3 && d2+1+nh2<=nmax) ans+=lui(i+1,d50-3,d1,d2+1), ans%=base;
    }
    return f[i][d50][d1][d2]=ans;
 }

int main()
{
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>nmax;
    cin>>m50>>m1>>m2;

    if (m50>n*3) nh50=m50-n*3,m50=n*3;
    if (m1>n) nh1=m1-n,m1=n;
    nh2=m2;

    memset(f,-1,sizeof(f));

    cout<<lui(1,m50,m1,0);

    return 0;
}
