#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
const ll MOD = 1e9;
const ll maxn = 1e5 + 7;
const ll maxk = 20;
using namespace std;

ll n , k , a[4*maxn] , ans = 0 , f[maxk][4* maxn];

void update (ll id , ll l , ll r , ll j , ll k , ll cnt)
{
    if (k < l || k > r) return ;
    if (l == k && k == r)
    {
        f[j][id] = ( f[j][id] + cnt ) % MOD;
        return ;
    }
    ll mid = (l + r) >> 1;
    update (id * 2 , l , mid , j , k , cnt );
    update (id * 2 + 1 , mid + 1 , r , j , k , cnt);
    f[j][id] = (f[j][id * 2] + f[j][id * 2 + 1]) % MOD;
}
ll get (ll id , ll l , ll r , ll j , ll k)
{
    if (k >= r) return f[j][id];
    if (k < l) return 0;
    ll mid = (l + r) >> 1;
    return ( get (id * 2 , l , mid , j , k) + get(id * 2 + 1 , mid + 1 , r , j , k) ) % MOD;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> k ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , a[i] = n - a[i] + 1;
    for (int i = 1 ; i <= n ; i++)
    {
        update(1 , 1 , n , 1 , a[i] , 1);
        if (a[i] > 1)
        {
            for (int j = 2 ; j <= k ; j++)
            {
                ll tmp = get (1 , 1 , n , j - 1 , a[i] - 1);
                update(1 , 1 , n , j , a[i] , tmp);
                if (j == k) ans = ( ans + tmp ) % MOD;
            }
        }
    }
    cout << ans;
}
