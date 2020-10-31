#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
typedef int64_t ll;
using namespace std;

ll m, n, k, a[310][310], u[1001], v[10001], q[10001], p[10001], res, f[310][310];
void QHD(int d, int c, int pos)
{
    f[u[pos]][v[pos]] = a[u[pos]][v[pos]];
    For(i, u[pos] + 1, p[pos])
    {
        if(i == d && v[pos] == c)
        {
            f[i][v[pos]] =LLONG_MIN;
            continue;
        }
        if(i - 1 == d && v[pos] == c)
        {
            f[i][v[pos]] = LLONG_MIN;
            continue;
        }
        f[i][v[pos]] = f[i - 1][v[pos]] + a[i][v[pos]];
    }
    For(i, v[pos] + 1, q[pos])
    {
        if(u[pos] == d && i == c)
        {
            f[u[pos]][i] = LLONG_MIN;
            continue;
        }
        if(u[pos] == d && i - 1 == c)
        {
            f[u[pos]][i] = LLONG_MIN;
            continue;
        }
        f[u[pos]][i] = f[u[pos]][i - 1] + a[u[pos]][i];
    }
    For(i, u[pos] + 1, p[pos])
    {
        For(j, v[pos] + 1, q[pos])
        {
            if(i == d && j == c)
            {
                f[i][j] = LLONG_MIN;
                continue;
            }
            if(f[i - 1][j] != LLONG_MIN)
            {
                f[i][j] = f[i - 1][j];
            }
            if(f[i][j - 1] != LLONG_MIN)
            {
                f[i][j] = max(f[i][j], f[i][j - 1]);
            }
            f[i][j] += a[i][j];
        }
    }
    if(f[p[pos]][q[pos]] != LLONG_MIN) res = min(res, f[p[pos]][q[pos]]);
}

void Sub1()
{
    For(i, 1, k)
    {
        res = LLONG_MAX;
        For(j, u[i], p[i])
        {
            For(l, v[i] + 1, q[i] - 1)
            {
                QHD(j, l, i);
            }
        }
        if(res == LLONG_MIN || res == LLONG_MAX) cout << LLONG_MIN << endl;
        else cout << res << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);
    cin >> m >> n >> k;
    For(i, 1, m)
        For(j, 1, n) cin >> a[i][j];
    For(i, 1, k)
    {
        cin >> u[i] >> v[i] >> p[i] >> q[i];
    }
    Sub1();
}
