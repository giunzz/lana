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
const string tenfile = "watching";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
ll x[2], t, k, a[2][maxn];

int main(){
    opt;
    // file;
    cin >> x[0] >> x[1] >> t >> k;
    lp(i, 1, x[0]) cin >> a[0][i];
    lp(i, 1, x[1]) cin >> a[1][i];
    a[1][0] = 0;
    ll i = 1, ans[2], tt = 0, tmp = 0;
    ans[0] = a[0][1];
    ans[1] = 0;
    while(i <= x[tt]){
        // cerr << i << ' ' << tt << ' ' << tmp <<  '\n';
        while(a[!tt][tmp] <= a[tt][i] && tmp <= x[!tt]) ++tmp;
        if(tmp > x[!tt]){
            ll ed = max(a[tt][i], a[!tt][tmp - 1] + k);
            ans[!tt] += (t - ed);
            break;
        }
        ll at = a[!tt][tmp] - a[tt][i];
        if(a[!tt][tmp] >= t){
            at = t - a[tt][i];
            ll ed = a[!tt][tmp - 1] + k - 1;
            if(ed >= t) break;
            if(ed >= a[tt][i]) at -= (ed - a[tt][i] + 1);
            ans[!tt] += at;
            break;
        }
        if(tmp==1){
            ans[!tt] += at;
            tt = !tt;
            swap(tmp, i);
            continue;
        }
        ll ed = a[!tt][tmp - 1] + k - 1;
        if(a[tt][i] <= ed){
            at -= (ed - a[tt][i] + 1);
        }
        ans[!tt] += at;
        tt = !tt;
        swap(tmp, i);
    }
    cout << ans[0] << ' ' << ans[1];
}
