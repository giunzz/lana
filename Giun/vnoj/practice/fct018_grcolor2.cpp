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

cll mxn = 1e5 + 3, mxlog = 18;
ll n, hi[mxn] = {0}, dp[mxn][mxlog], l, 
    tin[mxn], tout[mxn], t = 0, m, a[mxn], d[mxn], red[mxn], ans = 0;
vec(ll) g[mxn], ng[mxn];

void init(ll u, ll p){
    dp[u][0] = p; tin[u] = ++t;
    lp(i, 1, l) if(~dp[u][i - 1]) dp[u][i] = dp[dp[u][i - 1]][i - 1];
    for(ll v : g[u]){
        if(v == dp[u][0]) continue;
        hi[v] = hi[u] + 1;
        init(v, u);
    }
    tout[u] = ++t;
}

bool cpr(ll &a, ll &b){
    return tin[a] < tin[b];
}

ll lca(ll u, ll v){
    if(hi[u] < hi[v]) swap(u, v);
    // cerr << u << ' ' << v << ' ';
    lpd(i, l, 0){
        if(dp[u][i] == -1) continue;
        if(hi[dp[u][i]] >= hi[v]) u = dp[u][i];
    }
    // cerr << u << ' ' << v << ' ' << hi[u] << ' ' << hi[v] << '\n';
    if(u == v) return u;
    assert(hi[u] == hi[v]);
    lpd(i, l, 0){
        if(dp[u][i] == -1) continue;
        if(dp[u][i] != dp[v][i]) u = dp[u][i], v = dp[v][i];
    }
    return dp[u][0];
}

ll dfs(ll u, ll const &stt){
    ll tmp;
    bool ok = 0;
    if(red[u] == stt){
        for(ll v : ng[u]){
            tmp = dfs(v, stt);
            if(red[v] == stt && dp[v][0] == u){
                ans += 1e9;
            }
            if(tmp) ++ans;
        }
        ok = 1;
    } else{
        ll cnt = 0;
        for(ll v : ng[u]){
            tmp = dfs(v, stt);
            if(tmp) ++cnt;
        }
        if(cnt > 1) ++ans;
        else if(cnt == 1) ok = 1;
    }
    return ok;
}

void sol(ll stt){
    cin >> m;
    lp(i, 1, m){
        cin >> a[i];
        d[a[i]] = red[a[i]] = stt;
        ng[a[i]].clear();
    }
    sort(a + 1, a + 1 + m, cpr);
    for(ll i = 2; i <= m; i++){
        ll par = lca(a[i - 1], a[i]);
        if(d[par] < stt){
            d[par] = stt, a[++m] = par;
            ng[par].clear();
        }
    }
    sort(a + 1, a + 1 + m, cpr);
    stack<ll> st;
    st.push(a[1]);
    lp(i, 2, m){
        while(tout[st.top()] < tout[a[i]]) st.pop();
        ng[st.top()].push_back(a[i]);
        st.push(a[i]);
    }
    // lp(i, 1, m){
    //     cerr << a[i] << '\t';
    //     for(ll v : ng[a[i]]) cerr << v << ' ';
    //     cerr << '\n';
    // }
    ans = 0;
    dfs(a[1], stt);
    // cerr << ans << '\n';
    if(ans >= 1e9) cout << "-1\n";
    else cout << ans << "\n";
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    memset(dp, -1, sizeof(dp));
    cin >> n;
    l = log2(n);
    lp(i, 1, n - 1){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init(1, -1);
    // cerr << dp[3][2] << '\t';
    ll tests;
    cin >> tests;
    lp(cs, 1, tests) sol(cs);
}