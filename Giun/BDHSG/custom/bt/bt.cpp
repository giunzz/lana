#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "bt";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 107, mx = 2e4 + 7;
ll n, hg[mx] = {0};
pp(ll, pp(ll, ll)) a[maxn];

int main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;
        a[i].second.first <<= 1, a[i].second.second <<= 1;
    }
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    lp(i, 1, n){
        ans += 2 * a[i].first - (hg[a[i].second.first + 1] + hg[a[i].second.second - 1]);
        lp(j, a[i].second.first, a[i].second.second) hg[j] = a[i].first;
    }
    cout << ans;
}
