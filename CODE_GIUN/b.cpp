#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9+7, fi,u,v,n;
ll fibo(ll x)
{
    ll  f1 = 1, f2 = 1;
    for (int i = 3 ; i <= x + 1; i++)
    {
        fi = (f1 + f2) % MOD  ;
        f1 = f2 ;
        f2 = fi ;
    }
    return fi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
    cin >> n;
    for(int i=1; i<n; i++)
    {             
        cin >> u >> v;
    }
    cout << fibo(n+1);
}