//Make_Sam^^
#include <bits/stdc++.h>
#define nmax 301
#define SIZE(f) int(f.size())
#define vti vector<int>
#define pii pair<int, int>
#define vtp vector<pii>
#define vtv vector<vti>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define oo 1000000009
#define MOD 1000000007
#define real double
#define Task "TABLE"
#define reset(f) memset(f, 0, sizeof f)
#define resetF(f) memset(f, 1, sizeof f)
#define resetM(f) memset(f, 60, sizeof f)

using namespace std;
int m, n, k, a[nmax][nmax];
long long d[nmax][nmax], res;

void solve(int u, int v, int p, int q)
{
    for (int i = u; i <= p; i++)
        for (int j = v; j <= q; j++){
            if (i == u && j == v) continue;
            if (i == p && j == q) continue;
            reset(d);
            for (int t = u; t <= p; t++)
                for (int b = v; b <= q; b++){
                    if (t == i && b == j) d[t][b] = max(d[t - 1][b], d[t][b - 1]);
                    else d[t][b] = max(d[t - 1][b] + a[t][b], d[t][b - 1] + a[t][b]);
                }
            res = min(res, d[p][q]);
        }
}

int main()
{
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    while(k--)
    {
        res = 1e18;
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        reset(d);
        solve(u, v, p, q);
        cout << res << "\n";
    }

}
