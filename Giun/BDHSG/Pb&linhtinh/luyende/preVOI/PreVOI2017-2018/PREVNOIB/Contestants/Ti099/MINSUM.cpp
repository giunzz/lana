#include <bits/stdc++.h>
#define maxn int(1e6)
using namespace std;

int a, b, p[maxn], e[maxn];
typedef pair <int, int> II;
II pa[maxn], pb[maxn];

void sangNT()
{
    int np = 0;
    for(int i = 1; i <= maxn; ++i) e[i] = i;
    for(int i = 2; i <= maxn; ++i) if(e[i] == i)
    {
        p[++np] = i;
        for(int j = 1; i * j <= maxn; ++j) e[i * j] = np;
    }
}

int gcd(int a, int b)
{
    while(b > 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int mu(int x, int k)
{
    if(k == 0) return 1;
    int y = mu(x, k / 2);
    y *= y;
    if(k % 2) y *= x;
    return y;
}

void sub1()
{
    scanf("%d%d", &a, &b);
    int d = gcd(a, b);
    a /= d; b /= d;
    int sl1 = 0, xa = a, t1 = 1;
    while(xa > 1)
    {
        int p1 = p[e[a]], k = 0;
        while(xa % p1 == 0) ++k, xa /= p1;
        pa[++sl1] = II(p1, k);
    }
    for(int i = 1; i <= sl1; ++i)
    {
        int u = pa[i].first;
        int v = pa[i].second;
        t1 *= (v % 2 == 1) ? mu(u, v - 1) : mu(u, v);
    }
    a /= t1;
    int sl2 = 0, xb = b, t2 = 1;
    while(xb > 1)
    {
        int p2 = p[e[b]], k = 0;
        while(xb % p2 == 0) ++k, xb /= p2;
        pb[++sl2] = II(p2, k);
    }
    for(int i = 1; i <= sl2; ++i)
    {
        int u = pb[i].first;
        int v = pb[i].second;
        t2 *= (v % 2 == 1) ? mu(u, v - 1) : mu(u, v);
    }
    b /= t2;
    printf("%d %d\n", a, b);
}

void solve()
{
    int t;
    scanf("%d", &t);
    while(t) sub1(), --t;
}

int main()
{
    freopen("MINSUM.inp", "r", stdin);
    freopen("MINSUM.out", "w", stdout);
    sangNT();
    solve();
}
