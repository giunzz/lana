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
const string tenfile = "dptree";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll maxn = 1e6 + 7;
ll n, dp[maxn] = {0};
vec(ll) g[maxn];

void dfs(ll u){
    for(ll v : g[u]){
        dfs(v);
        dp[u] += dp[v] + 1;
    }
}

int main(){
    opt;
    file;
    cin >> n;
    lp(i, 2, n){
        ll tmp;
        cin >> tmp;
        g[tmp].push_back(i);
    }
    lp(u, 1, n){
        for(ll v : g[u]){
            cerr << u << ' ' << v << '\n';
        }
    }
    dfs(1);
    lp(i, 1, n) cout << dp[i] << ' ';
}
