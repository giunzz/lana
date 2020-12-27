#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, cnt[maxn] = {0}, p[maxn], cntchuoi = 1, stt[maxn] = {0}, r[maxn] = {0}, pos[maxn] = {0}, cntp = 0, trace[maxn] = {0};
vec(ll) g[maxn];
bool d[maxn] = {0};

void dfs(ll u){
    cnt[u] = 1;
    for(ll v : g[u]){
        if(d[v]) continue;
        d[v] = 1, p[v] = u;
        dfs(v);
        cnt[u] += cnt[v];
    }
}

void hld(ll u){
    stt[u] = cntchuoi;
    if(!r[cntchuoi]) r[cntchuoi] = u;
    pos[u] = ++cntp;
    trace[cntp] = u;
    ll specver = -1;
    for(ll v : g[u]) if((v != p[u]) &&(specver == -1 || cnt[v] > cnt[specver])) specver = v;
    if(specver != -1) hld(specver);
    for(ll v : g[u]) if(v != specver && v != p[u]) ++cntchuoi, hld(v);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n - 1){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    d[1] = 1;
    dfs(1);
    hld(1);
    lp(i, 1, n) cerr << trace[i] << ' ';
    cerr << '\n';
    lp(i, 1, n) cerr << stt[trace[i]] << ' ';
    cerr << '\n';
    lp(i, 1, cntchuoi) cerr << r[i] << '\n';
}