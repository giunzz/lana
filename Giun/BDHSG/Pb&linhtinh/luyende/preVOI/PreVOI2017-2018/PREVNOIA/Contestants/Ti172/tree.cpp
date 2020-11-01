#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const int mod  = 1e9 + 7;
const int oo   = 1e8 + 1;

int n, T, par[maxn], a[maxn], u, t, dp[5001][5001], res(+oo);
vector <int> v[maxn];

void Dfs (int x, int pre)
{
    par[x] = pre;
    for (int i = 0; i < (int)v[x].size(); ++i)
    {
        int j = v[x][i];
        if (j != pre) Dfs (j, x);
    }
}

void Visit (int x)
{
    if ((int)v[x].size() == 0)
    {
        dp[x][1] = abs (a[x] - 1);
        dp[x][0] = abs (a[x] - 0);
        if (x == 1) res = min (res, min (dp[x][1], dp[x][0]));
    }
    for (int i = 0; i < (int)v[x].size(); ++i) Visit (v[x][i]);

    for (int i = 0; i <= n; ++i)
    {
        if ((int)v[x].size() == 1) dp[x][i] = dp[v[x][0]][i] + abs (a[x] - i);
        if ((int)v[x].size() == 2)
        {
            for (int j = 0; j <= n; ++j)
                dp[x][i] = min (dp[x][i], dp[v[x][0]][j] + dp[v[x][1]][i - j] + abs (a[x] - i));
        }
        if (x == 1) res = min (res, dp[x][i]);
    }
}

void Init()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> t;
        v[u].push_back(t);
        v[t].push_back(u);
    }
    Dfs(1, 1);

    for (int i = 1; i <= n; ++i)
    {
        for (int l = 0; l < (int)v[i].size(); ++l)
        {
            int j = v[i][l];
            if (j == par[i])
            {
                v[i][l] = v[i].back();
                v[i].pop_back();
            }
        }
        /*cout << i << "   ";
        for (int j : v[i]) cout << j << " ";
        cout << endl;*/
    }

    for (int i = 1; i <= 5000; ++i)
        for (int j = 0; j <= 5000; ++j) dp[i][j] = +oo;
    Visit(1);
    cout << res;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("tree.inp", "r", stdin);
    freopen ("tree.out", "w", stdout);

    Init();
}
// Date 2 Month 12 Year 2017

