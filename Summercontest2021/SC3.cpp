#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n , MOD = 1e9+7, f[(int) 1e6+7] , inf[(int)1e6+7]   , t;
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
ll B2 (int x )
{
    ll a = 0 , b = 1;
    if (x == 1 || x == 2) return x-1;
        else 
        {
            for (int i = 3 ; i <= x ; i++)
            {
                ll tmp = ((i-1)*(a+b)) % MOD ;
                a = b;
                b = tmp ;
            }
        }
    return b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t ;
    while (t--)
    {
        cin  >> n ;
    ll m = 1;
    for (int i = 1 ; i <= n/2 ; i++) m = (m * i) % MOD;
    f[1] = 1 ;
    inf[1] = 1;
    for (int i = 2 ; i <= n ; i++) 
    {
        f[i] = (f[i-1]*i) % MOD;
        inf[i] = POW(f[i],MOD-2) % MOD;
    }
    cout << (C(n,n/2) % MOD *m% MOD * B2(n/2) % MOD) %MOD << endl;
    }
}
