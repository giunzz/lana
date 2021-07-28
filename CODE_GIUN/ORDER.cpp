#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll MOD = 1e9 + 7;
const ll maxn = 1e5 + 3;
ll n, c, f[maxn] = {0} , g[maxn] = {0};

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> c;
    for (int i = 1 ; i <= n ; i++)
    {
        g[0] = 1;
        for (int j = 1 ; j <= c ; j++)
        {
            ll val;
            if ( j - i >= 0) val = (f[j] - f[j - i] + MOD) % MOD;
            else val = f[j] % MOD;
            g[j] = (g[j-1] + val) % MOD;
        }
        for(int j = 0 ; j <= c ; j++ ) f[j] = g[j];
    }
    if (c > 0)  cout << (f[c] - f[c - 1] + MOD ) % MOD;
    else cout << f[c]% MOD;
}
