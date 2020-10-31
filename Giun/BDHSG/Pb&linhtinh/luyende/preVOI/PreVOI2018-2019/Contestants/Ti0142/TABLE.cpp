#include <bits/stdc++.h>
#define Task "TABLE"
#define pii pair<int,int>
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define ll long long

using namespace std;
const int maxn = 307;
int n, m, k, a[maxn][maxn];
ll dp[maxn][maxn], c[maxn][maxn];

void tr()
{
    while (k--)
    {
        int u,v,p,q; ll res = 1e10; cin >> u >> v >> p >> q;
        for (int x = u; x <= p; ++x)
            for (int y = v; y <= q; ++y)
            {
                reset(dp);
                for (int i = u; i <= p; ++i)
                    for (int j = v; j <= q; ++j)
                        {
                            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1ll*a[i][j];
                            if (i==x && j==y) dp[i][j] = 0;
                        }
                if (x != p || y != q) res = min(res,dp[p][q]);
            }
        cout << res << "\n";
    }
}

void St()
{
    while (k--)
    {
        int u,v,p,q, mx = -1e9; ll res = 1e10; cin >> u >> v >> p >> q;
        for (int i = u; i <= p; ++i)
            for (int j = v; j <= q; ++j)
                if ((i != u || j != v) && (i != p || j != q))
                mx = max(mx,a[i][j]);
        for (int x = u; x <= p; ++x)
            for (int y = v; y <= q; ++y)
                if (a[x][y] == mx)
                {
                    reset(dp);
                    for (int i = u; i <= p; ++i)
                        for (int j = v; j <= q; ++j)
                        {
                            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1ll*a[i][j];
                            if (i == x && j == y) dp[i][j] = 0;
                        }
                    if (x != p || y != q) res = min(res,dp[p][q]);
                }
        cout << res << "\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(Task".inp","r",stdin);
	freopen(Task".out","w",stdout);
	cin >> m >> n >> k;
	for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    if (n <= 40 && m <= 40) tr();
    else St();
	return 0;
}
