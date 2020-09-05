#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define pb push_back
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".ans").c_str(), "w", stdout);
}

cll maxn = 2e5 + 7;
ll n, tg, a[maxn];
vec(ll) g[maxn], cnt[maxn];

void init(){
    ll u, v;
    lp(i, 1, n - 1) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(ll u){
    a[u] = 0;
    for(ll v : g[u]){
        if(a[v] == -1){
            dfs(v);
            cnt[u].pb(a[v]);
        }
    }
    sort(cnt[u].rbegin(), cnt[u].rend());
    // for(ll v : cnt[u]) cerr << v << ' ';
    // cerr << '\n';
    for(ll v = 0; v < cnt[u].size(); v++){
        a[u] = max(a[u], v + 1 + cnt[u][v]);
    }
}

void sol(){
    lp(i, 1, n) a[i] = -1;
    dfs(tg);
    cout << a[tg];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("transport");
    cin >> n >> tg;
    init();
    sol();
}

