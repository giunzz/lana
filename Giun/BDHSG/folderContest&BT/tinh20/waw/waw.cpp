#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "waw"
using namespace std;

cll mxn = 1e5 + 6;
ll n, a[mxn], tin[mxn], tout[mxn], ti = 0, sz[mxn] = {0}, bigc[mxn], atti[mxn], cnt[mxn] = {0}, ans[mxn], szans[mxn];
vec(ll) g[mxn], nen;

void init(ll u){
    tin[u] = ++ti;
    atti[ti] = u;
    sz[u] = 1;
    bigc[u] = -1;
    for(ll v : g[u]){
        init(v);
        sz[u] += sz[v];
        if(bigc[u] == -1 || sz[v] > sz[bigc[u]]) bigc[u] = v;
    }
    tout[u] = ti;
}

void compress(){
    unordered_set<ll> s;
    lp(i, 1, n) s.insert(a[i]);
    nen.assign(s.begin(), s.end());
    sort(nen.begin(), nen.end());
    lp(i, 1, n) a[i] = lower_bound(nen.begin(), nen.end(), a[i]) - nen.begin();
}

void dfs(ll u, bool keep){
    for(ll v : g[u]) if(bigc[u] != v)
        dfs(v, 0);
    if(bigc[u] != -1) dfs(bigc[u], 1), ans[u] = ans[bigc[u]], szans[u] = szans[bigc[u]];
    else ans[u] = 0, szans[u] = 0;
    if(++cnt[a[u]] > szans[u]) szans[u] = cnt[a[u]], ans[u] = nen[a[u]];
    else if(cnt[a[u]] == szans[u]) ans[u] += nen[a[u]];
    ll vv;
    for(ll v : g[u]) if(v != bigc[u]){
        lp(i, tin[v], tout[v]){
            vv = atti[i];
            if(++cnt[a[vv]] > szans[u]) szans[u] = cnt[a[vv]], ans[u] = nen[a[vv]];
            else if(cnt[a[vv]] == szans[u]) ans[u] += nen[a[vv]];
        }
    }
    if(!keep){
        lp(i, tin[u], tout[u]) --cnt[a[atti[i]]];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    compress();
    lp(i, 1, n - 1){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    init(1);
    dfs(1, 1);
    lp(i, 1, n) cout << ans[i] << ' ';
}
