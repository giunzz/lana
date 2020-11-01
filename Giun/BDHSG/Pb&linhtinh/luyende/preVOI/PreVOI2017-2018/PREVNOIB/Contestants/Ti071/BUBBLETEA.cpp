#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define fi first
#define se second

using namespace std;

const int maxn = 50000, LOG = log2(maxn)+1;
int n, k, P[maxn+1][LOG+1], H[maxn+1], V[maxn+1];
vector <int> A[maxn+1], Free[maxn+1], C[maxn+1];
ll CC[maxn+1][LOG+1], ans;
typedef pair <int , ll> ii;
bool ok;

void DFS(int u)
{
    for (int i=0; i<A[u].size(); i++)
    {
        int v = A[u][i];
        if (v != P[u][0])
        {
            P[v][0] = u;
            CC[v][0] = C[u][i];
            H[v] = H[u] + 1;
            DFS(v);
        }
    }
}

void dfs(int u, int s)
{
    if (s == u) return;
    for (int i=0; i<A[u].size(); i++)
    {
        int v = A[u][i];
        if (v == P[u][0])
        {
            if (Free[u][i] == 0) ok = 0;
            Free[u][i] = 0;
            dfs(v, s);
        }
    }
}

void Build()
{
    for (int u=1; u<=n; u++)
        for (int i=1; i<=log2(n); i++)
        {
            P[u][i] = P[P[u][i-1]][i-1];
            if (P[u][i])
                CC[u][i] = CC[u][i-1] + CC[P[u][i-1]][i-1];
        }
}

ii LCA(int u, int v)
{
    ll val = 0;
    if (H[u] < H[v]) swap(u, v);
    int j = log2(n);
    for (int i=j; i>=0; i--)
        if (H[u] - (1 << i) >= H[v]) val += CC[u][i], u = P[u][i];
    if (u == v) return ii(u, val);
    for (int i=j; i>=0; i--)
        if (P[u][i] != P[v][i]) val += CC[u][i] + CC[v][i], u = P[u][i], v = P[v][i];
    return ii(P[u][0], val + CC[u][0]+ CC[v][0]);
}

int main()
{
    freopen("BUBBLETEA.INP", "r", stdin);
    freopen("BUBBLETEA.OUT", "w", stdout);
    cin >> n >> k;
    for (int i=1; i<=k; i++) cin >> V[i];
    for (int u, v, c, i=1; i<n; i++)
    {
        cin >> u >> v >> c;
        A[u].pb(v); A[v].pb(u);
        C[u].pb(c); C[v].pb(c);
        Free[u].pb(1); Free[v].pb(1);
    }
    H[1] = 1;
    DFS(1);
    Build();
    int X[11];
    for (int i=1; i<=k; i++) X[i] = i;
    ans = 1e18;
    do
    {
        for (int u=1; u<=n; u++)
            for (int i=0; i<A[u].size(); i++) Free[u][i] = 1;
        ll res = 0;
        ok = 1;
        for (int i=1; i<=k; i+=2)
        {
            int u = V[X[i]], v = V[X[i+1]];
            int p = LCA(u, v).fi;
            res = max(res, LCA(u, v).se);
            dfs(u, p);
            dfs(v, p);
        }
        if (ok) ans = min(ans, res);
    }   while (next_permutation(X+1, X+k+1));
    cout << ans;
    return 0;
}
