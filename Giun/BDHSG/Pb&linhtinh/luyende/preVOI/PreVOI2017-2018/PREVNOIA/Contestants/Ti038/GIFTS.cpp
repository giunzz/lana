#include <bits/stdc++.h>

using namespace std;

#define int                         long long
#define FOR(i, a, b)                for(int i = a; i <= b; ++i)
#define FORD(i, a, b)               for(int i = a; i >= b; --i)
#define REP(i, a, b)                for(int i = a; i  < b; ++i)

//--------------------------------------------------------------
inline int read()
{
    int sign = 1;
    char c;
    do
    {
        c = getchar();
        if (c == '-') sign = -sign;
    } while (c < '0' || c > '9');
    int res;
    for (res = 0; c >= '0' && c <= '9'; c = getchar()) res = res * 10 + (c - '0');
    return res * sign;
}
void write(int x)
{
    if (x < 0) { putchar('-'); write(abs(x)); }
    if (x > 9) write(x / 10);
    putchar(char(x % 10 + '0'));
}
//----------------------------------------------------------------
const int N = 2e6 +10;
int n, k;
int a[N], f[N], g[N], sum[N];
void Enter()
{
    n = read(), k = read();
    FOR(i, 1, n) a[i] = read(), sum[i] = sum[i-1] + a[i];
    FOR(i, k, n) f[i] = max(f[i-1], sum[i] - sum[i-k]);
    FORD(i, n-k+1, 1) g[i] = max(g[i+1], sum[i+k-1] - sum[i-1]);
}
void Solve()
{
    int ans = 1e18 +7;
    FOR(i, 1, n) ans = min(ans, max(f[i-1], g[i+k]));
    write(ans);
}
main()
{
    freopen("gifts.inp", "r", stdin);
    freopen("gifts.out", "w", stdout);

    Enter();
    Solve();

    return 0;
}
