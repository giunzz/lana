#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
ll n , MOD = 1e9+7, f[(int) 1e6+7] , inf[(int)1e6+7]  , k ;
// fi : so cach chia tap hop gom i phan tu{1,2,3,...,i}
// S (fi = j-1Ci-1*fi-j) for j = 1 -> i;
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
    cin >> n ;
    f[1] = 1;
    for (int i = 2 ; i <= n ; i++) 
    {
        f[i] = (f[i-1]*i) % MOD;
        inf[i] = POW(f[i],MOD-2) % MOD;
    }
    for (int i = 2 ; i <= n ; i++) 
    {
        for (int j = 1 ; j <= i ; j++) f[i] += C(i-1,j-1) *f[i-j];
    }
    cout << f[n];
    
}