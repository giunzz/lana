#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 3007;

struct T
{
    int x, y, z;
};

T Trace[107][107][207];
int Last[107][107][207], a[maxn], b[maxn], n, m, k;
int val[107][107][207], eat[107][107][207];
vector<int> ans;
void Qr(int n, int m, int t)
{
    if(t == 0) return;
    if(eat[n][m][t] == 1)
    {
        ans.push_back(a[n]);
        Qr(n - 1, m, t - 1);
    }
    else if(eat[n][m][t] == 2)
    {
        ans.push_back(b[m]);
        Qr(n, m - 1, t - 1);
    }
    else
    {
        Qr(n - 1, m - 1, t);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("sequence.inp", "r", stdin);
    freopen("sequence.out", "w", stdout);
    fill_n(&val[0][0][0], 107 * 107 * 207, LLONG_MAX);
    cin >> n >> m >> k;
    for(int i = n; i >= 1; i--) cin >> a[i];
    for(int i = m; i >= 1; i--) cin >> b[i];
    a[n + 1] = 1e9 + 69;
    val[0][0][0] = LLONG_MAX;
    for(int i = 1; i <= n; i++) Trace[i][0][i] = {i - 1, 0, i - 1}, eat[i][0][i] = 1, val[i][0][i] = a[i];
    for(int i = 1; i <= m; i++) Trace[0][i][i] = {0, i - 1, i - 1}, eat[0][i][i] = 2, val[i][0][i] = b[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int t = 1; t <= min(i + j, k); t++)
            {
                int val = LLONG_MAX;
                if(i == 0 && j == 0) continue;
                if(a[i] < b[j]) Trace[i][j][t] = {i - 1, j, t - 1}, val = a[i], eat[i][j][t] = 1;
                if(a[i] >= b[j]) Trace[i][j][t] = {i, j - 1, t - 1}, val = b[j], eat[i][j][t] = 2;
                if(val > ::val[Trace[i - 1][j - 1][t].x][Trace[i - 1][j - 1][t].y][Trace[i - 1][j - 1][t].z])
                {
                    Trace[i][j][t] = Trace[i - 1][j - 1][t];
                    eat[i][j][t] = 0;
                    val = ::val[Trace[i - 1][j - 1][t].x][Trace[i - 1][j - 1][t].y][Trace[i - 1][j - 1][t].z];
                }
                ::val[i][j][t] = val;
            }
        }
    }
    Qr(n, m, k);
    for(auto i: ans) cout << i << ' ';
}
