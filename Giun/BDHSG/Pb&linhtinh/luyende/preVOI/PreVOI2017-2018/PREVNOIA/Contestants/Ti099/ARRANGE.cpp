#include <bits/stdc++.h>
#define maxn int(1e5 + 5)

using namespace std;

int n, a[maxn], b[maxn];
long long s = 0;

void sub1()
{
    int k = s / n;
    for(int i = 1; i <= n; ++i) b[i] = a[i] - k;
    int amax = maxn, id, ds = 0;
    while(amax > 0)
    {
        amax = 0;
        int s1 = 0, s2 = 0;
        for(int i = 1; i <= n; ++i) if(b[i] >= amax) amax = b[i], id = i;
        for(int i = 1; i < id; ++i) s1 += b[i];
        for(int i = id + 1; i <= n; ++i) s2 += b[i];
        b[id] = 0;
        b[id - 1] += abs(s1);
        b[id + 1] += abs(s2);
        ds += amax;
    }
    printf("%d", ds);
}

void sub2()
{
    sub1();
}

void solve()
{
    scanf("%d", &n);
    s = 0;
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), s += a[i];
    if(s % n == 0) sub1();
    else sub2();
}

int main()
{
    freopen("ARRANGE.inp", "r", stdin);
    freopen("ARRANGE.out", "w", stdout);
    solve();
}
