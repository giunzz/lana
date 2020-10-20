#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
#pragma GCC optimize("Ofast")
#define ballolo freopen("giun.inp","r",stdin),freopen("giun.out","w",stdout)
const ll MOD = 1e9+7;
ll n , x,  f[(ll) 1e6+7]={0} ,  ans=0;
int main()
{
    giuncute;
    ballolo;
    cin >> n ;
    f[0] = 1;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> x;
        if (x > n) continue;
        //cerr << f[x] + f[x-1] << " ";
        f[x] = (f[x] + f[x-1]) % MOD;
        cerr << f[x] << " ";
    }
    for (int i = 1 ; i <= n ; i++)
    {
        ans = (ans + f[i]) % MOD;
    }
    cout << ans;
} 