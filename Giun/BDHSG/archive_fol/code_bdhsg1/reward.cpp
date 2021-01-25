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
const string tenfile = "reward";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
ll n, a[maxn], f[maxn], ans;
ii main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    f[0] = 0;
    if(a[1] >= 0) f[1] = a[1];
    else f[1] = f[0]; 
    if(a[2] >= 0) f[2] = a[2] + f[1];
    else f[2] = f[1];
    ans = max(f[1], f[2]);
    lp(i, 3, n){
        if(a[i] < 0) f[i] = f[i - 1];
        else f[i] = max(f[i - 3] + a[i] + a[i - 1], f[i - 2] + a[i]);
        ans = max(ans, f[i]);
    }
    cout  << ans;
}
