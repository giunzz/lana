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

cll mxn = 1e3 + 2;
ll n, dp[mxn][20], mhigh[mxn], high[mxn];
vec(ll) g[mxn];

void dfs(ll u, ll p){
    dp[u][0] = p, mhigh[u] = 0;
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
    ll _case, q;
    cin >> _case;
    lp(test, 1, _case){
        cin >> n;
        lp(i, 1, n) g[i].clear();
        lp(i, 1, n) lp(j, 0, 19) dp[i][j] = -1;
        lp(u, 1, n){
            ll tot, v;
            cin >> tot;
            lp(i, 1, tot){
                cin >> v;
                g[v].push_back(u);
                g[u].push_back(v);
            }
        }
        high[1] = 0;
        dfs(1, -1);
        cin >> q;
        cout << "Case " << test << ":\n";
        lp(i, 1, q){
            ll u, v;
            cin >> u >> v;
            cout << _lca(u, v) << '\n';
        }
    }
}