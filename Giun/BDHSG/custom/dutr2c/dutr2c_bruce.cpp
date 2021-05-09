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
const double esf = 1e-9;
const string tenfile = "dutr2c";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll MOD = 998244353, mxn = 1e6 + 7;
ll n, a[mxn], p[mxn];

inline ll Pow(ll u, ll v){
    if(!v) return 1;
    ll tmp = Pow(u, v >> 1);
    if(v & 1) return (((tmp * tmp) % MOD) * u) % MOD;
    return (tmp * tmp) % MOD;
}

int main(){
    opt;
    file;
    cin >> n;
    p[0] = Pow(2, MOD - 2);
    lp(i, 1, n) cin >> a[i], (p[i] = p[i - 1] << 1) %= MOD;
    ll ans = 0;
    lp(i, 0, n - 1) (ans += ((p[i] * (i + 2)) % MOD) * a[n - i]) %= MOD;
    cout << ans;
    cerr << "bruce: " << clock() << '\n';
}
