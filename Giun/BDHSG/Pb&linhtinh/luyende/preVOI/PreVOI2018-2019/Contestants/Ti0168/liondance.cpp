/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ll long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define pi acos(-1)
#define N 4003
#define task "liondance"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int n, D, a[N], b[N], cnt = 0;

pair <int, pii> dp[N][N];

int luu[N];

vector <int> ans;

void Calc(int u, int v)
{
    FOR(i, 1, n)
        FOR(j, 1, n) dp[i][j] = MP(0, MP(0, 0));
    FOR(i, u , n)
        FOR(j, v, n)
        {
            if (a[i] == b[j] && (i == u || j == v || abs(a[i] - a[dp[i-1][j-1].S.F]) <= D))
            {
                if (dp[i][j].F < dp[i-1][j-1].F + 1)
                {
                    dp[i][j].F = dp[i-1][j-1].F + 1;
                    dp[i][j].S = MP(i, j);
                }
                    else if (dp[i][j].F == dp[i-1][j-1].F + 1)
                    {
                        if (a[dp[i][j].S.F] < a[i])
                        {
                            dp[i][j].F = dp[i-1][j-1].F + 1;
                            dp[i][j].S = MP(i, j);
                        }
                    }
            }
                else
                {
                    if (dp[i][j].F < dp[i-1][j].F) dp[i][j] = dp[i-1][j];
                    if (dp[i][j].F < dp[i][j-1].F) dp[i][j] = dp[i][j-1];
                    if (dp[i][j].F == dp[i][j-1].F && a[dp[i][j].S.F] < a[dp[i][j-1].S.F]) dp[i][j] = dp[i][j-1];
                    if (dp[i][j].F == dp[i-1][j].F && a[dp[i][j].S.F] < a[dp[i-1][j].S.F]) dp[i][j] = dp[i][j-1];
                }
        }
    if (dp[n][n].F < sz(ans)) return;
    int i = dp[n][n].S.F, j = dp[n][n].S.S;
    cnt = 0;
    while (i && j)
    {
        luu[++cnt]= a[i];
        int x = dp[i-1][j-1].S.F;
        int y = dp[i-1][j-1].S.S;
        i = x, j = y;
    }
    j = 0;
    FORD(i, cnt, 1)
    {
        if (ans.empty() || sz(ans) < cnt || luu[i] > ans[j])
        {
            ans.clear();
            FORD(k, cnt, 1) ans.PB(luu[k]);
            return;
        }
        if (luu[i] < ans[j]) return;
        j++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> D;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    FOR(i, 1, n)
        FOR(j, 1, n)
            Calc(i, j);
    cout << sz(ans) << '\n';
    for (auto x : ans) cout << x << ' ';
    return 0;
}
