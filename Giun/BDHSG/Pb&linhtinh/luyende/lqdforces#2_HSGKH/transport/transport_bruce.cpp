#include <bits/stdc++.h>
#define pb push_back
#define vii vector<int>
#define task "transport"
#define pll pair<ll, ll>
#define pii pair< ll, pair< ll, ll > >
#define fi first
#define se second

using ll = long long;
using ld = long double;
using ull = unsigned long long;
const ll mod = 1e17 + 7;
using namespace std;
const int N = 1e5 + 5;
ll tong, m, n, k, t, T, ntest, ans,  res[N], a[N], b[N];
struct dang
{
    ll id;
    vector<int> vc;
};
string s;
vector<ll> adj[N], adt[N];
//ll b[N], a[N];
bool check;
void dfs(ll u)
{
    a[u] = 0;
    for(int v : adj[u])
    {
        if(a[v] == -1)
        {
            dfs(v);
            adt[u].pb(a[v]);
        }
    }
    sort(adt[u].rbegin(), adt[u].rbegin());
    //cout << u <<" ";
    for(int v = 0; v < adt[u].size(); v++)
    {
        a[u] = max(a[u], v+1+adt[u][v]);
    }
}

inline void sol()
{
    cin >> n >> m;
    fill_n(a, n+2, -1);
    for(int i = 1; i < n; i ++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);

    }
    dfs(m);
    cout << a[m] <<" ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".ans", "w", stdout);
    }
    sol();
}
