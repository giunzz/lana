#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll  n ,  a[maxn] , dp[maxn][20] , ans = 0 ;

inline ll query(ll i, ll j) 
{
    ll k = __lg(j - i + 1);
    return __gcd(dp[i][k], dp[j - (1 << k) + 1][k]); // 1 << k = 2^k
}

ll cnp( ll val , ll i , ll p)
{
    ll l = p + 1 , r = n  , tmp = n + 1;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (query(i, mid) == val) l = mid + 1;
        else r = mid - 1 , tmp = mid;
    }
    return tmp;
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , dp[i][0] = a[i];
    for (int j = 1; 1 << j <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) 
            dp[i][j] = __gcd(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);// Sparse Table
    
    for (int i = 1; i <= n; i++) 
    {
        ll p = i;
        while (p <= n) 
        {      
            ll val = query(i, p) , k = p;
            p = cnp(val, i, p);
            ans =  (ans % MOD + val % MOD * (p - k) % MOD ) % MOD;
        }
    }
    cout << ans;
}
