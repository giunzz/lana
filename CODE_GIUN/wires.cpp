#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
const int  maxn = 1e6+ 7;
ll n, k, a[maxn], sum = 0 , ans ;
bool check (ll x)
{
    ll d = 0;
    for (int i = 1 ; i <= n ; i++) d += a[i] / x;
    return d >= k;
}
void sol()
{
    ll l = 1, r = (ll) 1e9, m , ans = 0;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (check(m))
        {
            if (m > ans) ans = m;
            l = m +1;
        }
        else r = m-1;
    }
    cout << ans;
}
int main()
{
    giuncute;
    freopen("wires.inp","r",stdin);
    freopen("wires.out","w",stdout);
    cin >> n >> k;
    for (ll i = 1 ; i <= n  ; i++) cin >> a[i], sum += a[i];
    if (sum < k) cout << 0;
    else if (sum == k) cout << 1;
    else sol();
}
