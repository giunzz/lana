#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 2e5 + 7;
ll n, d[maxn] = {0};
vec(ll) g[maxn];

void dfs(ll u, ll p, ll dis, ll &maxdis, ll &fver){
    if(g[u].size() == 1 && p != -1){
        if(dis == maxdis) fver = u;
        return;
    }
    for(ll &v : g[u]){
        if(v != p){
            dfs(v, u, dis + 1, maxdis = max(maxdis, dis + 1), fver);
        }
    }
}

void dis(ll u, ll p, ll &t){
    if(u == t){
        d[u] = -1;
        return;
    }
    for(ll &v : g[u]){
        if(v != p){
            dis(v, u, t);
            if(d[v]) d[u] = v;
        }
    }
}

void getsol(ll u, ll p, ll &fver, ll dis, ll &maxdis){
    if(g[u].size() == 1 && p != -1){
        if(maxdis == dis) fver = u;
        return;
    }
    for(ll &v : g[u]){
        if(v != p && !d[v]){
            getsol(v, u, fver, dis + 1, maxdis = max(maxdis, dis + 1));
        }
    }
}

int main(){
    giuncute();
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
    ll far1, far2, ans = 0, tmp = 0;
    dfs(1, -1, 0, tmp, far1);
    dfs(far1, -1, 0, ans, far2);
    dis(far1, -1, far2);
    ll u = d[far1], far3 = u;
    tmp = 0;
    while(d[u] != -1){
        getsol(u, -1, far3, 0, tmp);
        u = d[u];
    }
    cout << ans + tmp << '\n' << far1 << ' ' << far2 << ' ' << far3;
}