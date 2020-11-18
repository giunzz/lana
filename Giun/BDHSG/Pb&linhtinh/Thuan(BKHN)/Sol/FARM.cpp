#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5;

int a[N];
int dp[N][1005][2];
int n,k,q,p,d,m;

void maximize(int &a, int b)
{
    if (a < b)  a = b;
}

int solve(int i, int j, bool used)
{
    if (i > n) return 0;
    int &res = dp[i][j][used];
    if (res != -1) return res;
    res = solve(i + 1, j, used);
    if (d && !used) maximize(res, solve(i + k, j, 1) + d * a[i]);
    if (j) maximize(res, solve(i + k, j - 1, used) + p * a[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n >> k >> q >> p;
    d = q % p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    m = q / p;
    d = q % p;
    cout << solve(1, m, 0);
    return 0;
}
