#include <bits/stdc++.h>
#define ll int
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

cll mx = 1e7 + 4, mxn = 1e5 + 4;
ll n, a[mxn], near[mx] = {0}, pos[mx] = {0}, par[mxn], sz[mxn], ans = 0;
bool visit[mx] = {0};
vec(pp(ll, ll)) edge[mx];

ll _get(ll u){
    return par[u] = (par[u] == u ? u : _get(par[u]));
}

bool _join(ll u, ll v){
    u = _get(u), v = _get(v);
    if(u == v) return 0;
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
    return 1;
}

int main(){
    // giuncute();
    freopen("sirni.inp", "r", stdin);
    freopen("sirni.out", "w", stdout);
    memset(near, -1, sizeof near);
    scanf("%d", &n);
    lp(i, 1, n){
        scanf("%d", &a[i]);
        if(pos[a[i]]) continue;
        pos[a[i]] = i, near[a[i]] = a[i];
    }
    lpd(i, 1e7, 1) if(near[i] == -1) near[i] = near[i + 1];
    lp(i, 1, n){
        if(visit[a[i]]) continue;
        visit[a[i]] = 1;
        if(near[a[i] + 1] != -1 && (2 * a[i] > 1e7 || near[a[i] * 2] != near[a[i] + 1])) 
            edge[near[a[i] + 1] - a[i]].push_back({i, pos[near[a[i] + 1]]}); 
        for(ll j = a[i] * 2; j <= 1e7; j += a[i])
            if(j + a[i] > 1e7 || near[j + a[i]] != near[j]) if(near[j] != -1) edge[near[j] - j].push_back({i, pos[near[j]]});
    }
    // find min tree
    lp(i, 1, n) par[i] = i, sz[i] = 1;
    ll cnt_edge = 0;
    lp(i, 0, 1e7){
        if(edge[i].empty()) continue;
        for(auto e : edge[i]) if(_join(e.first, e.second)) ++cnt_edge, ans += i;
        if(cnt_edge == n - 1) break;
    }
    printf("%d", ans);
}