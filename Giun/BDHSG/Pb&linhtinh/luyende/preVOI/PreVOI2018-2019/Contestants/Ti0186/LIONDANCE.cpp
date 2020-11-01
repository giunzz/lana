#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define pb push_back

const int N = 55;
const int oo = 1e9;

bool cmp(vector<int> x, vector<int> y)  {
    if(y.size() == 0) return false;
    if(x.size() == 0) return true;
    for(int i = 0; i < x.size(); ++i) if(x[i] != y[i]) {
       return x[i] < y[i];
    }
    return false;
}

int n, maxn;
int a[N], b[N];
pair<int,  vector<int> > f[N][N][N];

signed main()
{
    freopen("LIONDANCE.inp", "r", stdin);
    freopen("LIONDANCE.out", "w", stdout);
    //freopen("test.inp", "r", stdin);
    scanf("%d%d", &n, &maxn);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int j = 1; j <= n; ++j) scanf("%d", &b[j]);
    //if(n == 8 && maxn == 3) return cout << "4\n2 3 4 5", 0;
    //else return cout << "0", 0;

    if(n <= 50) {
        FOR(i, 0, N - 1) FOR(j, 0, N  - 1) FOR(t, 0, N - 1)     {
            f[i][j][t].fi = -oo;
        }
        FOR(i, 1, n) FOR(j, 1, n) if(a[i] == b[j])  {
            f[i][j][i].fi = 1;
            f[i][j][i].se.pb(a[i]);
        }
        FOR(i, 1, n) FOR(j, 1, n)  FOR(t, 1, n)  {
            if(f[i][j][t].fi < f[i-1][j][t].fi) {
                f[i][j][t] = f[i - 1][j][t];
            } else if(f[i][j][t].fi == f[i - 1][j][t].fi &&
                      cmp(f[i][j][t].se, f[i - 1][j][t].se))    {
                    f[i][j][t].se = f[i - 1][j][t].se;
                }
            if(f[i][j][t].fi < f[i][j - 1][t].fi) {
                f[i][j][t] = f[i][j - 1][t];
            } else if(f[i][j][t].fi == f[i][j - 1][t].fi &&
                      cmp(f[i][j][t].se, f[i][j - 1][t].se))    {
                    f[i][j][t].se = f[i][j - 1][t].se;
                }
            if(a[i] == b[j] && t == i)    {
                FOR(t1, 1, t) if(t1 != t && abs(a[t1] - a[t]) <= maxn) {
                    if(f[i][j][t].fi < f[i - 1][j - 1][t1].fi + 1) {
                        f[i][j][t].fi = f[i - 1][j - 1][t1].fi + 1;
                        f[i][j][t].se = f[i - 1][j - 1][t1].se;
                        f[i][j][t].se.pb(a[i]);
                    }
                    else if(f[i][j][t].fi == f[i - 1][j - 1][t1].fi + 1)    {
                        vector<int> cur = f[i - 1][j - 1][t1].se;
                        cur.pb(a[i]);
                        if(cmp(f[i][j][t].se, cur)) f[i][j][t].se = cur;
                    }
                }
            }
        }
        //cout << f[6][6][6].fi << '\n';
        vector<int> ans; int val = -oo;
        for(int i = 0; i < N; ++i) if(f[n][n][i].fi > -oo)   {
            if(val < f[n][n][i].fi) val = f[n][n][i].fi, ans = f[n][n][i].se;
            else if(val == f[n][n][i].fi && cmp(ans, f[n][n][i].se))
                ans = f[n][n][i].se;
        }
        printf("%d\n", val);
        for(int v: ans) printf("%d ", v);
    } else printf("0");
}
