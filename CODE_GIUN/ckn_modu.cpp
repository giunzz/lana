#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
ll n , MOD = 1e9+7, f[(int) 1e6+7] , inf[(int)1e6+7]  , k ;
ll POW (int a,int b)
{
    if (b == 0) return 1;
    ll baby = POW(a,b/2);
    ll res = (baby*baby) %MOD;
    if (b%2) return (res*a)%MOD;
    else return res%MOD;
}
ll C (int n , int k)
{
    return ((f[n]*inf[k]) % MOD*inf[n-k]) % MOD;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> k ;
    f[1] = 1 ;
    inf[1] = 1;
    for (int i = 2 ; i <= n ; i++) 
    {
        f[i] = (f[i-1]*i) % MOD;
        inf[i] = POW(f[i],MOD-2) % MOD;
    }
    // a/b % M = (a*b^M-2)%M;
    cout << C(n,k);
}