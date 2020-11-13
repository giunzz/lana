#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define int long long
using namespace std;
const int oo = (int) 1e18;

int dp[1 << 15][16];
int val[1 << 15];
int f[10][1 << 15];
int d[15];
int a[15][15];
int n,k,q;

int getbit(int x, int i)
{
    return (x >> i) & 1;
}

void minimize(int &a, int b)
{
    if (a > b) a = b;
}

int solve(int i, int mask)
{
    int &res = f[i][mask];
    if (res != -1) return res;
    if (i > k) return (!mask) ? 0 : oo;
    res = oo;
    for (int nxt = mask; nxt > 0; nxt = (nxt - 1) & mask)
    {
        minimize(res, solve(i + 1, mask ^ nxt) + val[nxt]);
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
    {
        cin >> a[i][j];
    }
    for (int mask = 1; mask < (1 << n); mask++)
    {
        val[mask] = oo;
        int sum = 0;
        for (int i = 1; i <= n; i++) if (getbit(mask, i - 1))
        {
            sum += d[i];
        }
        if (sum > q) continue;
        for (int cur = 0; cur < (1 << n); cur++)
        for (int i = 0; i <= n; i++)
        {
            dp[cur][i] = oo;
        }
        dp[0][0] = 0;
        for (int cur = 0; cur < (1 << n); cur++)
        for (int i = 0; i <= n; i++) if (dp[cur][i] < oo)
        {
            for (int j = 1; j <= n; j++) if (getbit(mask, j - 1) && !getbit(cur, j - 1))
            {
                int nxt = cur | (1 << (j - 1));
                minimize(dp[nxt][j], dp[cur][i] + a[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            minimize(val[mask], dp[mask][i] + a[i][0]);
        }
    }
    memset(f, -1, sizeof(f));
    cout << solve(1, (1 << n) - 1);
    return 0;
}
