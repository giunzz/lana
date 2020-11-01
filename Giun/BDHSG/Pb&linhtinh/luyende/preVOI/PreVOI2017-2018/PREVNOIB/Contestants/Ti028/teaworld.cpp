#include <bits/stdc++.h>
#define task "teaworld"
#define maxa 2020
#define ft first
#define sd second

using namespace std;
typedef pair <int,int> II;
typedef pair <II,II> IIII;

int xs, ys, zs;
int m, n, k, sl;
IIII a[maxa];
int b[maxa];

void sub1()
{
    sort(a + 1, a + sl + 1);
    for(int i = 1; i <= sl; ++i) b[i] = a[i].ft.ft;
    int s = lower_bound(b + 1, b + sl + 1, xs) - b;
    int dem = 0;
    int kq1 = 0, kq2 = 0;
    for(int i = s - 1; i > 0; --i)
    {
        if(a[i].sd.sd == -1) ++dem;
        else kq1 += a[i].sd.ft;
        if(dem > k) break;
    }
    dem = 0;
    for(int i = s + 1; i <= n; ++i)
    {
        if(a[i].sd.sd == -1) ++dem;
        else kq2 += a[i].sd.ft;
        if(dem > k) break;
    }
    int ds = max(kq1, kq2);
    printf("%d", ds);
}

void sub2()
{
    sub1();
}

void sub3()
{
    sub2();
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    scanf("%d%d%d", &m, &n, &k);
    int y0 = 0, z0 = 0;
    sl = 0;
    for(int i = 1; i <= m; ++i)
    {
        int x, y, z, r;
        scanf("%d%d%d%d", &x, &y, &z, &r);
        if(y == 0) ++y0;
        if(z == 0) ++z0;
        a[++sl] = IIII(II(x, y), II(r, -1));
    }
    for(int i = 1; i <= n; ++i)
    {
        int x, y, z, e;
        scanf("%d%d%d%d", &x, &y, &z, &e);
        if(y == 0) ++y0;
        if(z == 0) ++z0;
        a[++sl] = IIII(II(x, y), II(e, 1));
    }
    scanf("%d%d%d", &xs, &ys, &zs);
    if(ys == 0) ++y0;
    if(zs == 0) ++z0;
    a[++sl] = IIII(II(xs, ys), II(0,0));
    if(y0 == m + n + 1 && z0 == m + n + 1) sub1();
    else if(z0 == m + n + 1) sub2();
    else sub3();
}
