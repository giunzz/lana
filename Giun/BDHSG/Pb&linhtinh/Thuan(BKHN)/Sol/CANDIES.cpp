#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define int long long
using namespace std;

int f[105];
int g[105];
pair <int, int> dp[105][105];
int n,k;

bool mem[105][105];

pair <int, int> calc(int i, int j)
{
    pair <int, int> &res = dp[i][j];
    if (i <= 0) return mp(!j, 0);
    if (mem[i][j]) return res;
    res = calc(i - 1, j);
    pair <int, int> nxt = calc(i - 2, max(0LL, j - 1));
    nxt.se += nxt.fi;
    res.fi += nxt.fi;
    res.se += nxt.se;
    mem[i][j] = true;
    return res;
}

int solve()
{
    int res = 0;
    for (int i = 72; i >= 1; i--) if (f[i] <= n)
    {
        n -= f[i];
        g[i] = 1;
        res++;
    } else g[i] = 0;
    if (res < k) res = 0;
    int sum = 0;
    for (int i = 72; i >= 1; i--) if (g[i])
    {
        pair <int, int> tmp = calc(i - 1, max(0LL, k - sum));
        res += tmp.se + sum * tmp.fi;
        sum++;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 72; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    for (int i = 0; i <= 72; i++)
    {
        calc(72, i);
    }
    int q;
    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        if (k >= 72) cout << 0 << "\n";
        else cout << solve() << "\n";
    }
    return 0;
}
