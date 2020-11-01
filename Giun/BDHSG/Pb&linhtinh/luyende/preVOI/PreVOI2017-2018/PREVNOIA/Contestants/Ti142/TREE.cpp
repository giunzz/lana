#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 5005
#define MM 5000
#define maxc 1000000007

using namespace std;

int n, val[N], dp[N][N], sz[N], luu[N][N];
vector<int> a[N];

void LUU(int u)
{
    for (int i = 0; i <= MM; i++)
        if (dp[u][i] < maxc)
            luu[u][++sz[u]] = i;
}
void DFS(int u)
{
    for (int i = 0; i <= MM; i++) dp[u][i] = maxc;
    if (a[u].size() == 0)
    {
        dp[u][0] = val[u] - 0;
        dp[u][1] = abs(val[u] - 1);
        LUU(u);
        return;
    }
    for (auto v : a[u]) DFS(v);
    if (a[u].size() == 1)
    {
        int v = a[u][0];
        for (int i = 1; i <= sz[v]; i++)
        {
            int x = luu[v][i];
            dp[u][x] = dp[v][x] + abs(val[u] - x);
        }
    }
    else
    {
        int v1 = a[u][0];
        int v2 = a[u][1];
        for (int i = 1; i <= sz[v1]; i++)
            for (int j = 1; j <= sz[v2]; j++)
            {
                int x = luu[v1][i];
                int y = luu[v2][j];
                if (x+y > MM) break;
                dp[u][x+y] = min(dp[u][x+y], dp[v1][x] + dp[v2][y] + abs(val[u] - x - y));
            }
    }
    LUU(u);
}
int main()
{
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
    for (int i = 1; i < n; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        a[u].PB(v);
    }
    DFS(1);
    printf("%d", *min_element(dp[1], dp[1] + MM + 1));
}
