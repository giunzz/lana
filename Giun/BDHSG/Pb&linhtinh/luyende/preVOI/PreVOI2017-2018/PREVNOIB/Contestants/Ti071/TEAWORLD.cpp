#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 2016;
int n, m, k, X[maxn+1], Y[maxn+1], Z[maxn+1], R[maxn+1], XX, YY, ZZ, E[maxn+1];
ll ans;
bool Free[maxn+1];

void Sub1()
{
    int val = (1 << n) - 1;
    for (int x=0; x<=val; x++)
    {
        int d = 0;
        ll res = 0;
        memset(Free, 1, sizeof(Free));
        for (int i=1; i<=n; i++)
            if ((x >> (i-1)) & 1)
            {
                res += E[i];
                for (int j=1; j<=m; j++)
                {
                    int l = X[j+n] - R[j+n], r = X[j+n] + R[j+n];
                    int L = min(X[i], X[m+n+1]), R = max(X[i], X[m+n+1]);
                    if (!((l <= L && R <= r) || r < L || l > r)) Free[j+n] = 0;
                }
            }
        for (int i=n+1; i<=m+n; i++) d += !Free[i];
        if (d <= k) ans = max(ans, res);
    }
    cout << ans;
    exit(0);
}

int main()
{
    freopen("TEAWORLD.INP", "r", stdin);
    freopen("TEAWORLD.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    for (int i=1; i<=m; i++) cin >> X[i+n] >> Y[i+n] >> Z[i+n] >> R[i+n];
    for (int i=1; i<=n; i++) cin >> X[i] >> Y[i] >> Z[i] >> E[i];
    cin >> X[m+n+1] >> Y[m+n+1] >> Z[m+n+1];
    bool oky = 1, okz = 1;
    for (int i=1; i<=n+m+1; i++)
    {
        if (Y[i] != 0) oky = 0;
        if (Z[i] != 0) okz = 0;
    }
    if (oky && okz) Sub1();
    return 0;
}
