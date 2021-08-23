#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
const ll MOD = 1e9;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , x , h[maxn] , mu[maxn] = {0};
bool snt[maxn];
ll POW (ll a , ll b)
{
    if (!b) return 1;
    ll t = POW (a , b >> 1);
    t =  (t * t) % MOD;
    if (b % 2) return (t * a) % MOD;
    else return t % MOD;
}
ll find (ll x , ll y)
{
    ll res = 0 ;
    while (x % y == 0) res++ , x /= y;
    return res;
}
ll catalan (ll n)
{
    for (int i = 2 ; i <= 2 * n ; i++)
    {
        if (snt[i] == 1)
        {
            ll cnt = 0 ;
            for (int j = i ; j <= 2*n ; j += i)
            {
                snt[j] = 0 ;
                if (j >= n + 2) cnt += find(j , i);
                if (j <= n  ) cnt -= find(j , i);
            }
            mu[i] = cnt;
        }
    }
    ll res = 1;
    for (int i = 1 ; i <= 2*n ; i++) res = res * POW(i , mu[i]) % MOD;
    return res;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> x ;
    for (int i = 1 ; i <= 2*n + 1 ; i++) snt[i] = 1;
    for (int i = 1 ; i <= n ; i++) cin >> h[i];
    ll ans1 = 2 , tmp = h[n];
    for (int i = n - 1 ; i >= 1 ; i--)
    {
        if (h[i] < tmp) ans1++ , tmp = h[i];
        else break;
    }
    cout << ans1 << endl << catalan(n + 1);
}