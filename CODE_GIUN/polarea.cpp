#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e18;
const ll maxn = 4e5 + 7;
using namespace std;

ll n ;
pl v[maxn] , tmp[maxn];

int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    giuncute;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> v[i].fi >> v[i].se;
    ll ans = 0;
    pl tmp = v[n];
    for (int i = 1 ; i <= n ; i++) ans += (tmp.fi * v[i].se - tmp.se * v[i].fi) ,tmp = v[i];
    if (ans < 0) cout << "CW ";
    else cout << "CCW ";
    ans = abs(ans);
    cout << ans / 2 << '.' << (ans & 1) * 5 << '\n';
}