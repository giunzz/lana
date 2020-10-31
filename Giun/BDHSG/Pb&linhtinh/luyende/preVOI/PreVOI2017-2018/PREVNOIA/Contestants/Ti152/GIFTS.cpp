#include <bits/stdc++.h>
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
using namespace std;
int n, k;
long long a[1000005], b[1000005], d1[1000005], d2[1000005], s = 1e18;
void nhap()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]), a[i] += a[i-1];
}
main()
{

    freopen("GIFTS.inp", "r", stdin);
    freopen("GIFTS.out", "w", stdout);
    nhap();
    for(int i = 1; i <= n-k+1; ++i)
    {
        b[i] = a[i+k-1] - a[i-1];
        d1[i] = max(d1[i-1], b[i]);
    }
    for(int i = n-k+1; i; --i) d2[i] = max(d2[i+1], b[i]);
    for(int i = 1; i <= n-k+1; ++i)
    {
        int x = max(0, i-k);
        s = min(s, max(d1[x], d2[i+k]));
    }
    printf("%lld", s);
}
