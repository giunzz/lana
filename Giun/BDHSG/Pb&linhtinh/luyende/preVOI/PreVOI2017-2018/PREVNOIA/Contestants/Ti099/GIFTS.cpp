#include <bits/stdc++.h>
#define maxn int(1e6 + 2)
#define oo int64_t(1e18)

using namespace std;

int n, k, a[maxn], nho[maxn], d[maxn];
long long s[maxn];

long long xuly(int i)
{
    for(int j = 1; j <= n; ++j) nho[j] = 0;
    for(int j = i; j <= i + k - 1; ++j) nho[j] = 1;
    d[0] = 0;
    for(int j = 1; j <= n; ++j) d[j] = d[j - 1] + nho[j];
}

bool ok(int i)
{
    int t = d[i + k - 1] - d[i - 1];
    if(t > 0) return false;
    return true;
}

void sub1()
{
    long long ds = oo;
    for(int i = 1; i <= n - k + 1; ++i)
    {
        long long kq = 0;
        xuly(i);
        for(int j = 1; j <= n - k + 1; ++j) if(ok(j)) kq = max(kq, s[j + k - 1] - s[j - 1]);
        ds = min(ds, kq);
    }
    printf("%I64d", ds);
}

void sub2()
{
    sub1();
}

void solve()
{
    scanf("%d%d", &n, &k);
    s[0] = 0;
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
    if(n <= 5000) sub1();
    else sub2();
}

int main()
{
    freopen("GIFTS.inp", "r", stdin);
    freopen("GIFTS.out", "w", stdout);
    solve();
}
