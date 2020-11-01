#include <bits/stdc++.h>
using namespace std;

int m, n, k, u, v, p, q;
int a[318][318];
int dp[318][318];
int Trace[318][318];
int IT[318][2498];


void _reset()
{
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++) dp[i][j] = 0;
}

void _build(int l, int r, int node, int x)
{   
    if(l == r)  {IT[x][node] = a[x][l]; return;}
    int mid = (l+r)/2;
    _build(l, mid, node*2, x);
    _build(mid+1, r, node*2+1, x);
    IT[x][node] = max(IT[x][node*2+1], IT[x][node*2]);
}

int _get(int l, int r, int node, int x, int U, int V)
{
    int mid = (l+r)/2;
    if(x == u || x == p)
    {
        if(l == r && l == U)    return INT_MIN;
        if(l == r && l == v)    return INT_MIN;
    }
    // if((l == v && x == u) || (l == q && x == p)) return INT_MIN;
    if(U <= l && r <= V)  return IT[x][node];
    if(r < U || V < l)  return INT_MIN;
    return max(_get(l, mid, node*2, x, U, V), _get(mid+1, r, node*2+1, x, U, V));
}

int _bruteForce()
{
    _reset();
    int maxu, maxv, maxi = INT_MIN;
    for(int i = u; i <= p; i++)
        for(int j = v; j <= q; j++) 
            if((i == u && j == v) || (i == p && j == q)) continue;
            else
                if(a[i][j] >= maxi)
                {
                    maxi = a[i][j];
                    maxu = i, maxv = j;
                }
    int Rest = INT_MIN;
    for(int i = u; i <= p; i++)
    {
        for(int j = v; j <= q; j++) 
        {
            if(i == maxu && j == maxv)  { dp[i][j] = max(dp[i-1][j], dp[i][j-1]); continue; }
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
            Rest = max(Rest, dp[i][j]);
        }
    }
    return Rest;
}

main(int argc, char const *argv[])
{
    freopen("TABLE.inp", "r", stdin);
    freopen("TABLE.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++) cin >> a[i][j];
        _build(1, n, 1, i);
    }
    // u = 1, v = 2, p = 2, q = 4;
    // _build(1, n, 1, 2);
    // cerr << _get(1, n, 1, 2, 2, 4);
    while(k--)
    {
        cin >> u >> v >> p >> q;
        // for(int i = u; i <= p; i++)
            // cerr << _get(1, n, 1, i, v, q) << ' ';
        // cerr << '\n';
        cout << _bruteForce() << '\n';
    }
    return 0;
}
