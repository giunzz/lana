#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int maxn = 5000;
int n, D[maxn+1], P[maxn+1], Child[maxn+1], Dp[maxn+1][maxn+1], ans, Val[maxn+1], C[maxn+1][2];
vector <int> A[maxn+1];

void DFS(int u)
{
    for (int i=0; i<A[u].size(); i++)
    {
        int v = A[u][i];
        if (v != P[u])
        {
            P[v] = u;
            Child[u]++;
            DFS(v);
            D[u] += D[v];
            if (C[u][0] == 0) C[u][0] = v;
            else C[u][1] = v;
        }
    }
    if (Child[u] == 0) D[u] = 1;
}

void DP(int u)
{
    if (Child[u] == 0)
    {
        Dp[u][0] = abs(Val[u] - 0);
        Dp[u][1] = abs(Val[u] - 1);
        return;
    }
    if (Child[u] == 1)
    {
        DP(C[u][0]);
        for (int val=0; val<=D[u]; val++) Dp[u][val] = Dp[C[u][0]][val] + abs(Val[u] - val);
        return;
    }
    DP(C[u][0]);
    DP(C[u][1]);
    for (int val=0; val<=D[u]; val++) Dp[u][val] = 1e9;
    for (int x=0; x<=D[C[u][0]]; x++)
        for (int y=0; y<=D[C[u][1]]; y++)
            Dp[u][x+y] = min(Dp[u][x+y], Dp[C[u][0]][x] + Dp[C[u][1]][y] + abs(Val[u] - x - y));
}

int main()
{
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> Val[i];
    for (int u, v, i=1; i<n; i++)
    {
        cin >> u >> v;
        A[u].pb(v); A[v].pb(u);
    }
    DFS(1);
    DP(1);
    ans = 1e9;
    for (int val=0; val<=D[1]; val++) ans = min(ans, Dp[1][val]);
    cout << ans;
    return 0;
}
