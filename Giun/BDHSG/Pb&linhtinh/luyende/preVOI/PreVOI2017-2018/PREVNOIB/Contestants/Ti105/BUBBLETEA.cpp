#include <bits/stdc++.h>
#define f0(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define nmax 50002

using namespace std;
typedef long long ll;

ll n, k, a[nmax], dem[nmax], x[nmax], d[nmax], ma = -1e17, trace[nmax];
vector <pair <ll, ll> > adj[nmax];
ll res = 1e17;
map <pair <ll, ll>, ll> g;

void dfs(ll u, ll p, ll w){
    if(u==p){
        while(trace[u]!=-1){
            ll k1 = trace[u], k2 = u;
            d[g[make_pair(k1, k2)]]+=1;
            u = trace[u];
        }
        ma = max(ma, w);
        return ;
    }

    for(ll i=0; i<adj[u].size(); i++){
        ll v = adj[u][i].first;
        if(trace[v]==0 && ma<0){
            trace[v] = u;
            dfs(v, p, w + adj[u][i].second);
        }
    }
}

void check(){
    ma = -1e17;
    pair <ll, ll> b[12];
    ll cnt = 0;
    f1(i, k){
        for(ll j=i+1; j<=k; j++){
            if(x[i]==x[j]){
                b[++cnt] = make_pair(a[i], a[j]);
            }
        }
    }
    f1(i, k/2){
        fill(trace+1, trace+n+1, 0);
        trace[b[i].first] = -1;
        dfs(b[i].first, b[i].second, 0);
    }

    bool ok = 1;
    f1(i, n - 1){
        if(d[i]>1) ok = 0;
    }
    if(ok){
        res = min(res, ma);
    }
}

void backtrack(ll i){
    for(ll j=1; j<=(k/2); j++){
        if(dem[j]==2) continue;
        x[i] = j;
        dem[j]+=1;
        if(i==k) check();
        else backtrack(i+1);
        --dem[j];
    }
}

main(){
    freopen("BUBBLETEA.inp", "r", stdin);
    freopen("BUBBLETEA.out", "w", stdout);

    cin >> n >> k;
    f1(i, k) cin >> a[i];
    f1(i, n - 1){
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
        g[make_pair(u, v)] = g[make_pair(v, u)] = i;
    }
    backtrack(1);
    if(res<1e17)
        cout << res;
    else cout << -1;
}
