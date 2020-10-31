// MR.J
#include<bits/stdc++.h>
#define maxn 50005
#define maxC 1000000000
#define MOD 1000000007
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
#define rep(i, a, b) for(int i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(int i=(a) ; i>=(b) ; --i)
#define Task "bubbletea"
using namespace std;
int n, k, p[maxn], par[maxn][20], h[maxn];
ll dis[maxn], ans = 1ll*maxC*maxC;
bool dd[maxn];
vector <pii > g[maxn];
pii luu[maxn];

void setup() {
    cin >> n >> k;
    rep(i, 1, k) cin >> p[i];
    rep(i, 1, n-1) {
        int u, v, ts;
        cin >> u >> v >> ts;
        g[u].PB(mp(v, ts));
        g[v].PB(mp(u, ts));
    }
}

void DFS(int u) {
    for(pii PP : g[u]) {
        int v = PP.F;
        if(v == par[u][0]) continue;
        par[v][0] = u;
        h[v] = h[u] + 1;
        dis[v] = dis[u] + PP.S;
        DFS(v);
    }
}

void RMQ() {
    for(int i=1 ; i<=16 ; i++)
        for(int j=1 ; j<=n ; j++)
            par[j][i] = par[par[j][i-1]][i-1];
}

int LCA(int u, int v) {
    if(h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];
    for(int i=16 ; i>=0 ; i--)
        if((delta >> i) & 1) u = par[u][i];
    if(u == v) return u;
    for(int i=16 ; i>=0 ; i--)
        if(par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}

void calc() {
    ll maxval = 0;
    rep(i, 1, k/2) {
        int u = luu[i].F;
        int v = luu[i].S;
        int cha = LCA(u, v);
        ll DIS = dis[u] + dis[v] - 2*dis[cha];
        maxval = max(maxval, DIS);
    }
    ans = min(ans, maxval);
}

void duyet(int u) {
    rep(i, 1, k) {
        if(dd[p[i]]) continue;
        dd[p[i]] = 1;
        rep(j, 1, k) {
            if(dd[p[j]]) continue;
            luu[u] = mp(p[i], p[j]);
            dd[p[j]] = 1;
            if(u == k/2) calc();
            else duyet(u+1);
            dd[p[j]] = 0;
        }
        dd[p[i]] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    DFS(1);
    duyet(1);
    cout << ans;
    return 0;
}
