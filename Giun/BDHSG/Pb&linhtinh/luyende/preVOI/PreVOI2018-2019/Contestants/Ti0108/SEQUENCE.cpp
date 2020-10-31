#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 3007

using namespace std;

int m, n, k, pv1[maxn][maxn], pv2[maxn][maxn], a[maxn], b[maxn], ai[maxn], bi[maxn], re[maxn * 2], qu[maxn];
pair <int, int> d1[maxn], d2[maxn];

void build()
{
    for (int i = 1; i <= k; i++) d1[i].fi = d2[i].fi = -1;
    for (int i = 1; i <= m; i++)
        for (int j = k; j; j--)
        {
            if (d1[j - 1].fi == -1) continue;
            if (d1[j - 1].fi <= d1[j].fi && a[d1[j].se] <= a[i]) continue;
            if (d1[j - 1].fi > d1[j].fi && d1[j - 1].fi) d1[j] = {d1[j - 1].fi, i};
                else d1[j] = {d1[j].fi + 1, i};
            if (!d1[j].fi) d1[j].fi = 1;
            pv1[i][j] = d1[j - 1].se;
        }
    for (int i = 1; i <= n; i++)
        for (int j = k; j; j--)
        {
            if (d2[j - 1].fi == -1) continue;
            if (d2[j - 1].fi <= d2[j].fi && b[d2[j].se] <= b[i]) continue;
            if (d2[j - 1].fi > d2[j].fi && d2[j - 1].fi) d2[j] = {d2[j - 1].fi, i};
                else d2[j] = {d2[j].fi + 1, i};
            if (!d2[j].fi) d2[j].fi = 1;
            pv2[i][j] = d2[j - 1].se;
        }
}

void check(int q1, int q2)
{
    int p1 = d1[q1].se, qi = q1;
    while (qi)
    {
        ai[qi] = a[p1];
        p1 = pv1[p1][qi]; --qi;
    }
    int p2 = d2[q2].se; qi = q2;
    while (qi)
    {
        bi[qi] = b[p2];
        p2 = pv2[p2][qi]; --qi;
    }
    int q = 0;
    for (int i = 1; i <= q1; i++) qu[++q] = ai[i];
    int lt = 1;
    for (int i = 1; i <= q2; i++)
    {
        int t = 1;
        for (int j = lt; j <= q; j++)
            if (bi[i] < qu[j])
            {
                t = 0; ++q; lt = j + 1;
                for (int ii = q; ii > j; ii--) qu[ii] = qu[ii - 1];
                qu[j]= bi[i];
                break;
            }
        if (t) qu[++q] = bi[i]; lt = q + 1;
    }
    if (re[0] != k)
    {
        re[0] = k;
        for (int i = 1; i <= k; i++) re[i] = qu[i];
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        if (qu[i] > re[i]) break;
        if (qu[i] < re[i])
        {
            for (i = 1; i <= k; i++) re[i] = qu[i];
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    build();
    for (int i = 0; i <= min(k, m); i++)
        if (k - i <= n) check(i, k - i);
    for (int i = 1; i <= k; i++) cout << re[i] << ' ';
    return 0;
}
