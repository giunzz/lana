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
const string tenfile = "socks";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
ll n, q, a[maxn], r, tt[maxn];
vec(ll) g[maxn];
bool d[maxn] = {0};

void sub1(){
    vec(ll) res(g[r].size());
    d[r] = 1;
    lp(i, 0, g[r].size() - 1){
        ll u = g[r][i];
        d[u] = 1;
        if(a[u]) ++res[i];
        while(g[u].size() > 1){
            for(ll v : g[u]){
                if(d[v]) continue;
                d[v] = 1;
                tt[v] = i;
                if(a[v]) ++res[i];
                u = v;
                break;
            }
        }
    }
    ll ans = 0, cnt = 0, tp;
    lp(i, 0, g[r].size()){
        if(res[i] > 0) ++cnt, tp = i;
    }
    if(cnt > 1) ans = cnt - 1;
    if(cnt == 1 && (res[tp] > 1 || a[r])) ans = 1;
    cout << ans << '\n'; 
    lp(i, 1, q){
        ll num;
        cin >> num;
        a[num] = !num;
        if(a[num]) ++res[tt[i]];
        else --res[tt[i]];
        ans = 0, cnt = 0, tp;
        lp(i, 0, g[r].size()){
            if(res[i] > 0) ++cnt, tp = i;
        }
        if(cnt > 1) ans = cnt - 1;
        if(cnt == 1 && (res[tp] > 1 || a[r])) ans = 1;
        cout << ans << '\n';
    }
}

int main(){
    opt;
    file;
    cin >> n >> q;
    lp(i, 1, n) cin >> a[i];
    // bool sub2 = 1, sub3 = 0;
    // ll cnt = 0;
    lp(i, 1, n - 1){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll cnt = 0;
    lp(i, 1, n){
        if(g[i].size() >= 3){
            ++cnt, r = i;
        }
    }
    if(cnt == 0){
        lp(i, 1, n)
            if(g[i].size() == 2){
                r = i;
                break;
            }
    }
    if(cnt <= 1) sub1();
}
