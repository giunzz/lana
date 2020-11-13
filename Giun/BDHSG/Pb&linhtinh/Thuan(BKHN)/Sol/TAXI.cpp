#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int oo = 1e9;

vector <int> d[25][25];

int a[25][25];
int dp[1 << 21][21];
int ptr[1 << 21][21];
int n;

int getbit(int x, int i)
{
    return (x >> i) & 1;
}

int bit(int x)
{
    return (1 << x);
}

bool minimize(int &a, int b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

void dijkstra(int s)
{
    vector <int> dp(2 * n + 1, oo);
    vector <int> ptr(2 * n + 1, 0);
    dp[s] = 0;
    priority_queue <pair <int, int>> heap;
    heap.push(mp(0, s));
    while (heap.size())
    {
        pair <int, int> res = heap.top();
        heap.pop();
        int u = res.se;
        if (-res.fi != dp[u]) continue;
        for (int v = 0; v <= 2 * n; v++)
        {
            if (minimize(dp[v], dp[u] + a[u][v]))
            {
                ptr[v] = u;
                heap.push(mp(-dp[v], v));
            }
        }
    }
    for (int i = 0; i <= 2 * n; i++)
    {
        int cur = i;
        while (cur != s)
        {
            d[s][i].push_back(cur);
            cur = ptr[cur];
        }
        reverse(d[s][i].begin(), d[s][i].end());
    }
}

void trace(int last)
{
    vector <int> s(1, 0);
    int mask = bit(2 * n + 1) - 1;
    while (last)
    {
        int res = last;
        s.push_back(res);
        last = ptr[mask][res];
        mask ^= bit(res);
    }
    s.push_back(0);
    reverse(s.begin(), s.end());
    vector <int> ans(1, 0);
    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 < s.size())
        {
            for (int x : d[s[i]][s[i + 1]])
            {
                ans.push_back(x);
            }
        }
    }
    cout << ans.size() << "\n";
    for (int x : ans) cout << x << " ";
}

void solve()
{
    for (int mask = 0; mask < bit(2 * n + 1); mask++)
    for (int i = 0; i <= 2 * n; i++)
    {
        dp[mask][i] = oo;
    }
    dp[1][0] = 0;
    for (int mask = 1; mask < bit(2 * n + 1); mask++)
    for (int i = 0; i <= 2 * n; i++) if (dp[mask][i] < oo)
    {
        for (int j = 0; j <= 2 * n; j++) if (!getbit(mask, j) && (j <= n || getbit(mask, j - n)))
        {
            int new_mask = mask | bit(j);
            if (minimize(dp[new_mask][j], dp[mask][i] + a[i][j]))
            {
                ptr[new_mask][j] = i;
            }
        }
    }
    int ans = oo;
    int last = 0;
    for (int i = 0; i <= 2 * n; i++)
    {
        int mask = bit(2 * n + 1) - 1;
        if (minimize(ans, dp[mask][i] + a[i][0]))
        {
            last = i;
        }
    }
    cout << ans << "\n";
    trace(last);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j <= 2 * n; j++)
    {
        cin >> a[i][j];
    }
    for (int i = 0; i <= 2 * n; i++)
    {
        dijkstra(i);
    }
    for (int j = 0; j <= 2 * n; j++)
    for (int i = 0; i <= 2 * n; i++)
    for (int k = 0; k <= 2 * n; k++)
    {
        minimize(a[i][k], a[i][j] + a[j][k]);
    }
    solve();
    return 0;
}
