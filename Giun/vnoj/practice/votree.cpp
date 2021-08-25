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

cll mxn = 7e4 + 3;
ll n, q, par[mxn], mhigh[mxn], dp[mxn][20] = {{0}}, high[mxn] = {0}, dp_seg[mxn][20];
vec(ll) g[mxn];

void dfs(ll u, ll p){
    dp[u][0] = p;
    lp(i, 1, 19) if(~dp[u][i - 1] && ~(dp[u][i] = dp[dp[u][i - 1]][i - 1])) mhigh[u] = i;
    if(dp[u][mhigh[u]] == -1) mhigh[u] = -1;
    for(ll v : g[u]){
        if(v == p) continue;
        high[v] = high[u] + 1;
        dfs(v, u);
    }
}

ll _lca(ll u, ll v){
    if(high[u] < high[v]) swap(u, v);
    while(high[u] > high[v]){
        lpd(i, mhigh[u], 0) if(high[dp[u][i]] >= high[v]){u = dp[u][i]; break;}
    }
    if(u == v) return u;
    lpd(i, mhigh[u], 0) if(dp[u][i] != dp[v][i]){
        u = dp[u][i], v = dp[v][i];
    }
    return dp[u][0];
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> q;
    lp(i, 1, n - 1){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dp, -1, sizeof dp);
    high[1] = 1;
    dfs(1, -1);
    memset(dp_seg, -1, sizeof dp_seg);
    lp(i, 1, n) dp_seg[i][0] = i;
    lp(j, 1, 19) lp(i, 1, n){
        if(~dp_seg[i][j - 1] && ~dp_seg[i + (1 << j - 1)][j - 1]) 
            dp_seg[i][j] = _lca(dp_seg[i][j - 1], dp_seg[i + (1 << j - 1)][j - 1]);
    }
    while(q --> 0){
        ll u, v, loglen;
        cin >> u >> v;
        loglen = log2(v - u + 1);
        cout << _lca(dp_seg[u][loglen], dp_seg[v - (1 << loglen) + 1][loglen]) << '\n';
    }
}