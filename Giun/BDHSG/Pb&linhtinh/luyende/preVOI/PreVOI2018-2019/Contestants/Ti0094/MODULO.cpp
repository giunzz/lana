#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(ll i=(a);i<=(b);++i)

using namespace std;
typedef pair<ll,ll> II;

ll a,b,n,k,pw[70],base;
map <ll,ll> f[70];

ll lui(ll i,ll du){
    if (f[i][du]>0) return f[i][du];
    if (i>n){
            if (du==k) return 2;
            return 1;
    }

    ll ans=0;
    ans=max(ans,lui(i+1,(du+a*pw[n-i]%base)%base));
    if (ans==2)
        return f[i][du]=2;

    ans=max(ans,lui(i+1,(du+b*pw[n-i]%base)%base));

    return f[i][du]=ans;
}

void tv(ll i,ll du){
    if (i>n) return;
    if (lui(i+1,(du+a*pw[n-i]%base)%base)==2){
        cout<<a;
        tv(i+1,(du+a*pw[n-i]%base)%base);
        return;
    }
    cout<<b;
    tv(i+1,(du+b*pw[n-i]%base)%base);
    return;
}

int main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>a>>b;
    cin>>n>>k;

    base=(1ll<<n);

    pw[0]=1;
    fort(i,1,n) pw[i]=pw[i-1]*10%base;

    ll tmp=lui(1,0);
    if (tmp==2) tv(1,0);
    else
        cout<<-1;

    return 0;
}
