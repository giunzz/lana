#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll MOD = 1e9 + 7;
const ll maxn = 1e5 + 3;
ll n, c, f[maxn][maxn] = {{0}}; 
int main()
{
    giuncute;
    freopen("order.inp","r",stdin);
    freopen("order.out","w",stdout);
    cin >> n >> c;
    if (c == 0) return f[n][0] = 1;    
    if (n == 0) return f[0][c] = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        ll val = 0 ;
        for (int j = 1 ; j < n ; j++)
            if (c - j >= 0 ) val = (val % MOD +  f[i-1][c-j] % MOD ) % MOD;
        f[i]
    }