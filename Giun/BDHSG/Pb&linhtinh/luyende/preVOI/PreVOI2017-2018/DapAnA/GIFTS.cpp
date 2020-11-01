#define taskname "GIFTS"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long lli;
const int maxN = 1e6;
const int maxA = 1e6;
const lli infty = 1e18; //maxN * maxA

int n, k, a[maxN];
lli v[maxN], f[maxN], g[maxN];

inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int res = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        res = res * 10 + c - '0';
    return res;
}

void WriteInt(lli x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void Enter()
{
    n = ReadInt(); k = ReadInt();
    for (int i = 0; i < n; ++i)
        a[i] = ReadInt();
}

void Solve()
{
    lli s = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        s += a[i];
        if (i + k < n) s -= a[i + k];
        f[i] = i + k <= n ? s : 0;
    }
    g[0] = f[0];
    for (int i = 1; i < n; ++i)
        g[i] = max(g[i - 1], f[i]);
    for (int i = n - 2; i >= 0; --i)
        f[i] = max(f[i + 1], f[i]);
    lli res = infty;
    for (int i = 0; i < n; ++i)
    {
        lli a = i - k >= 0 ? g[i - k] : 0;
        lli b = i + k < n ? f[i + k] : 0;
        lli c = max(a, b);
        if (c < res) res = c;
    }
    WriteInt(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Solve();
}
