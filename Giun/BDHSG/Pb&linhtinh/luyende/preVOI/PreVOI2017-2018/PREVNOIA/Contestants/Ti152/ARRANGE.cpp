#include <bits/stdc++.h>
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
using namespace std;
int n;
long long a[100005], xp, xq, y, s = 0;
void nhap()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]), s += a[i];
}
main()
{
    freopen("ARRANGE.inp", "r", stdin);
    freopen("ARRANGE.out", "w", stdout);
    nhap();
    xp = xq = s / n, y = n - (s % n) + 1;
    s = 0;
    int p = 1, q = 1;
    while(p <= n && q <= n)
    {
        while(a[p] >= xp && p <= n)
        {
            p++;
            if(p == y) xp++;
        }
        while(a[q] <= xq && q <= n)
        {
            q++;
            if(q == y) xq++;
        }
        if(p <= n && q <= n)
        {
            long long z1 = xp - a[p], z2 = a[q] - xq;
            z1 = min(z1, z2);
            s += z1 * abs(p-q);
            a[p] += z1;
            a[q] -= z1;
        }
    }
    printf("%lld", s);
}
