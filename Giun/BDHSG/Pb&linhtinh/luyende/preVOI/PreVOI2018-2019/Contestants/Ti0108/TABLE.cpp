#include <bits/stdc++.h>
#define x first
#define y second
#define maxn 307

using namespace std;

int m, n, k, c[maxn][maxn];
long long d[maxn][maxn], g[maxn][maxn], mx[maxn][maxn], my[maxn][maxn];
pair <int, int> st, ed;

long long proc()
{
    for (int i = st.x - 1; i <= ed.x + 1; i++)
        for (int j = st.y - 1; j <= ed.y + 1; j++) d[i][j] = g[i][j] = mx[i][j] = my[j][i] = -1e12;
    for (int i = st.x; i <= ed.x; i++)
        for (int j = st.y; j <= ed.y; j++)
        {
            d[i][j] = max(d[i - 1][j], d[i][j - 1]) + c[i][j];
            if (i == st.x && j == st.y) d[i][j] = c[i][j];
        }
    for (int i = ed.x; i >= st.x; i--)
        for (int j = ed.y; j >= st.y; j--)
        {
            g[i][j] = max(g[i + 1][j], g[i][j + 1]) + c[i][j];
            if (i == ed.x && j == ed.y) g[i][j] = c[i][j];
            mx[i - 1][j] = max(mx[i - 1][j - 1], g[i][j] + d[i - 1][j]);
            my[j - 1][i] = max(my[j - 1][i - 1], g[i][j] + d[i][j - 1]);
        }
    long long rev = 1e12;
    for (int i = st.x; i <= ed.x; i++)
        for (int j = st.y; j <= ed.y; j++)
        {
            if (i == st.x && j == st.y) continue;
            if (i == ed.x && j == ed.y) continue;
            rev = min(rev, max(mx[i][j - 1], my[j][i - 1]));
        }
    return rev;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("TABLE.INP", "r", stdin);
    freopen("TABLE.OUT", "w", stdout);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> c[i][j];
    for (int i = 1; i <= k; i++)
    {
        cin >> st.x >> st.y >> ed.x >> ed.y;
        cout << proc() << '\n';
    }
    return 0;
}
