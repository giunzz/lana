#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
using namespace std;
void giuncute()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
cll mxn = 1e3 + 7;
ll n, a[mxn], b[mxn], c[mxn], d[mxn], l, ans = 0;
vector<ll> down;
map<ll, ll> cnt;
int main()
{
    giuncute();
    freopen("tera.inp", "r", stdin);
    freopen("tera.out", "w", stdout);
    cin >> n >> l;
    lp(i, 1, n) cin >> a[i];
    lp(i, 1, n) cin >> b[i];
    lp(i, 1, n) cin >> c[i];
    lp(i, 1, n) cin >> d[i];
    lp(i, 1, n) lp(j, 1, n) down.emplace_back(c[i] + d[j]), ++cnt[a[i] + b[j]];
    for(ll i : down) ans += cnt[l - i];
    cout << ans;
}