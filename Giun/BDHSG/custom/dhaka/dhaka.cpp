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
const string tenfile = "dhaka";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7, maxmask = 64;
ll n, m, k, l;
vec(ll) a[maxn];
vec(pp(ll, ll)) g[maxn];

void init(){
    lp(i, 1, n){
        ll s;
        cin >> s;
        lp(j, 1, s){
            ll num;
            cin >> num;
            a[i].push_back(--num);
        }
    }
    lp(i, 1, m){
        ll u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({c, v});
        g[v].push_back({c, u});
    }
}

ll dp[maxn][maxmask + 7];

ll countbito(ll num){
    ll cnt = 0;
    while(num) cnt += num&1, num >>= 1;
    return cnt;
}

void dj(){
    lp(i, 1, n) lp(j, 0, maxmask) dp[i][j] = LLONG_MAX;
    ll numr = 0;
    for(ll i : a[1]){
        numr = numr | (1LL << i);
    } 
    priority_queue<pp(pp(ll, ll), ll), vec(pp(pp(ll, ll), ll)), greater<pp(pp(ll, ll), ll)>> q;
    q.push({{0,  numr}, 1});
    dp[1][numr] = 0;
    while(q.size()){
        ll cu = q.top().first.first, mask = q.top().first.second, u = q.top().second;
        q.pop();
        if(cu != dp[u][mask]) continue;
        for(pp(ll, ll) i : g[u]){
            ll v = i.second, cuv = i.first, nmask = mask;
            for(ll j : a[v]){
                nmask = nmask | (1LL << j);
            }
            if(dp[u][mask] + cuv < dp[v][nmask]){
                dp[v][nmask] = dp[u][mask] + cuv;
                q.push({{dp[v][nmask], nmask}, v});
            }
        }
    }
    ll ans = LLONG_MAX;
    lp(i, 0, 31){
        if(countbito(i) == l){
            ans = min(ans, dp[n][i]);
        }
    }
    if(ans == LLONG_MAX) ans = -1;
    cout << ans;
}

int main(){
    opt;
    file;
    cin >> n >> m >> k >> l;
    init();
    dj();
}
