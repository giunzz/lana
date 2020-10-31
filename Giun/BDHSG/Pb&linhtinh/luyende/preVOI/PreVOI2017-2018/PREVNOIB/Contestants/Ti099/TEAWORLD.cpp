#include <bits/stdc++.h>
#define maxn 2030

using namespace std;

int xn, yn, zn, m, n, k, a[maxn], t, ds1[maxn], ds2[maxn];
typedef pair <int, int> II;
typedef pair <II, int> III;
III c[maxn], b[maxn];
II d[maxn], e[maxn], dd[maxn];

void xuly1()
{
    int h = lower_bound(a + 1, a + t + 1, xn) - a;
    int i = h - 1;
    long long ds = 0;
    while(dd[i].first == 0 && i > 0) ds += dd[i].second, --i;
    i = h + 1;
    while(dd[i].first == 0 && i <= m + n + 2) ds += dd[i].second, ++i;
    printf("%I64d", ds);
}

void xuly2()
{
    int h = lower_bound(a + 1, a + t + 1, xn) - a;
    int i = h - 1;
    long long ds = 0;
    while(dd[i].first == 0 && i > 0) ds += dd[i].second, --i;
    int j = h + 1;
    while(dd[j].first == 0 && j <= m + n + 2) ds += dd[j].second, ++j;
    --i, ++j;
    int sl1 = 0, sl2 = 0;
    while(i > 0 && j <= n)
    {
        while(dd[i].first == 0) ds1[++sl1] += dd[i].second, --i;
        while(dd[j].first == 0) ds2[++sl2] += dd[i].second, ++j;
        --i; ++j;
    }
    int u = 1, v = 1;
    while(k && (u <= sl1 || v <= sl2))
    {
        if(ds1[u] > ds2[v]) ds += ds1[u], --u;
        else ds += ds2[v], --v;
        --k;
    }
    printf("%d", ds);
}

void sub1()
{
    t = 0;
    int s = 0;
    for(int i = 1; i <= m; ++i)
    {
        d[i] = II(c[i].first.first + c[i].second, c[i].first.first - c[i].second);
        a[++t] = d[i].first;
        a[++t] = d[i].second;
    }
    for(int i = 1; i <= n; ++i) e[i] = II(b[i].first.first, b[i].second), a[++t] = e[i].first;
    a[++t] = xn;
    sort(a + 1, a + t + 1);
    t = unique(a + 1, a + t + 1) - a;
    for(int i = 1; i <= m; ++i)
    {
        int u = lower_bound(a + 1, a + t + 1, d[i].first) - a;
        int v = lower_bound(a + 1, a + t + 1, d[i].second) - a;
        dd[u] = II(1, 0);
        dd[v] = II(1, 0);
    }
    for(int i = 1; i <= n; ++i)
    {
        int u = lower_bound(a + 1, a + t + 1, e[i].first) - a;
        if(dd[u].first == 0) dd[u] = II(0, e[i].second);
    }
    if(k == 0) xuly1();
    else xuly2();
}

void sub2()
{
    sub1();
}

void solve()
{
    scanf("%d%d%d", &m, &n, &k);
    int dem1 = 0, dem2 = 0, sl1 = 0, sl2 = 0;
    for(int i = 1; i <= m; ++i)
    {
        int x, y, z, r;
        scanf("%d%d%d%d", &x, &y, &z, &r);
        if(y == 0) ++dem1;
        if(z == 0) ++dem2;
        c[i] = III(II(x, y), r);
    }
    for(int i = 1; i <= n; ++i)
    {
        int x, y, z, w;
        scanf("%d%d%d%d", &x, &y, &z, &w);
        if(y == 0) ++sl1;
        if(z == 0) ++sl2;
        b[i] = III(II(x, y), w);
    }
    scanf("%d%d%d", &xn, &yn, &zn);
    if(dem1 == m && dem2 == m && sl1 == n && sl2 == n) sub1();
    else if(dem2 == m && sl2 == n) sub2();
}

int main()
{
    freopen("TEAWORLD.inp", "r", stdin);
    freopen("TEAWORLD.out", "w", stdout);
    solve();
}
