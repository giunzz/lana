#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "comnet"

cll mxn = 1e3 + 3;
ll n, k, a, b, dis[mxn][mxn] = {{0}}, p[mxn] = {0}, dp[mxn][mxn] = {{0}}, high[mxn];
vec(ll) g[mxn];
bool done[5];

void dfs3(ll u){
    ll uu = p[u];
    while(uu != -1) dis[uu][u] = dis[u][uu] = dis[uu][p[u]] + 1, uu = p[uu];
    if(u != 1) dp[u][0] = p[u];
    lp(j, 1, n) {
        if((1 << j) > high[u]) break;
        dp[u][j] = dp[dp[u][j - 1]][j - 1];
    }
    for(ll v : g[u]){
        if(v == p[u]) continue;
        high[v] = high[u] + 1;
        p[v] = u;
        dfs3(v);
    }
}

ll lca(ll u, ll v){
    ll cha, cha1;
    if(high[u] < high[v]) swap(u, v);
    cha = u;
    while(high[cha] > high[v]){
        lp(i, 0, n){
            if((1 << i) > high[u] || high[dp[u][i]] < high[v]) break;
            cha = dp[u][i];
        }
        u = cha;
    }
    if(u == v) return u;
    while(p[u] != p[v]){
        lp(i, 0, n){
            if((1 << i) > high[u] || dp[u][i] == dp[v][i]) break;
            cha = dp[u][i], cha1 = dp[v][i];
        }
        u = cha, v = cha1;
    }
    return p[u];
}

inline bool cmp(ll &a, ll &b){
    return high[a] > high[b];
}

bool ok;

bool tot_dis(vec(ll) du){
    sort(du.begin(), du.end(), cmp);
    ll lu = lca(du[0], du[1]), res = dis[lu][du[0]] + dis[lu][du[1]], tmplca;
    lp(i, 2, du.size() - 1){
        tmplca = lca(lu, du[i]);
        if(lu != tmplca){
            res += dis[lu][tmplca] + dis[du[i]][tmplca];
            lu = tmplca;
        } else{
            ok = 1;
            lp(j, 0, i - 1){
                if(dis[du[i]][du[j]]){ok = 0; break;}
                ll tmp = lca(du[i], du[j]);
                if(high[tmp] > high[tmplca]) tmplca = tmp;
            }
            if(ok) res += dis[tmplca][du[i]];
        }
    }
    //for(ll u : du) cerr << u << ' ';
    //cerr << res << '\n';
    return a <= res && res <= b;
}

void sol_sub3(){
    ll u, ans = 0;
    p[1] = -1;
    dfs3(1);
    if(k == 2) lp(i, 1, n) lp(j, i + 1, n) ans += tot_dis({i, j});
    else if(k == 3) lp(i, 1, n) lp(j, i + 1, n) lp(k, j + 1, n) ans += tot_dis({i, j, k});
    else lp(i, 1, n) lp(j, i + 1, n) lp(k, j + 1, n) lp(l, k + 1, n) ans += tot_dis({i, j, k, l});
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    cin >> n >> k >> a >> b;
    lp(i, 1, n - 1){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n <= 100) sol_sub3();
}
