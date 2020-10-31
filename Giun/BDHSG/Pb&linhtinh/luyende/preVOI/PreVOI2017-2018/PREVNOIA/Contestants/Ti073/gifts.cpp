#include <bits/stdc++.h>

using namespace std;

int ReadInt()
{
    char c;
    for(c = getchar(); c < '0' || c > '9'; c = getchar());
    int ans = c - '0';
    for(c = getchar(); c >= '0' && c <= '9'; c = getchar())
        ans = ans * 10 + c - '0';
    return ans;
}

void WriteInt(int64_t x)
{
    if(x > 9)WriteInt(x / 10);
    putchar(x % 10 + '0');
}

#define maxn int(1e6 + 5)
int n, k, a[maxn];

void Enter()
{
    n = ReadInt(); k = ReadInt();
    for(int i = 1; i <= n; ++i)a[i] = ReadInt();
}

#define INF 1000000000000000001LL
int64_t s[maxn], b[maxn], ds, it[10 * maxn], dt[10 * maxn];

void update(int k, int l, int r, int u, int v, int64_t val)
{
    if(r < u || v < l)return;
    if(u <= l && r <= v)
    {
        dt[k] += val;
        return;
    }
    int g = (l + r) / 2;
    dt[2 * k] += dt[k]; dt[2 * k + 1] += dt[k]; dt[k] = 0;
    update(2 * k, l, g, u, v, val);
    update(2 * k + 1, g + 1, r, u, v, val);
    it[k] = max(it[2 * k] + dt[2 * k], it[2 * k + 1] + dt[2 * k + 1]);
}

int64_t _get(int k, int l, int r, int u, int v)
{
    if(r < u || v < l)return 0;
    if(u <= l && r <= v)return it[k] + dt[k];
    int g = (l + r) / 2;
    dt[2 * k] += dt[k]; dt[2 * k + 1] += dt[k]; dt[k] = 0;
    int64_t t1 = _get(2 * k, l, g, u, v);
    int64_t t2 = _get(2 * k + 1, g + 1, r, u, v);
    it[k] = max(it[2 * k] + dt[2 * k], it[2 * k + 1] + dt[2 * k + 1]);
    return max(t1, t2);
}

void Solve()
{
    for(int i = 1; i <= n; ++i)s[i] = s[i - 1] + a[i];
    for(int i = 1; i <= n - k + 1; ++i)b[i] = s[i + k - 1] - s[i - 1];
    for(int i = 1; i <= n - k + 1; ++i)update(1, 1, n - k + 1, i, i, b[i]);
    ds = INF;
    for(int i = 1; i <= n - k + 1; ++i)
    {
        int u = i - k + 1, v = i + k - 1;
        int64_t val, t1 = 0, t2 = 0;
        if(1 < u)t1 = _get(1, 1, n - k + 1, 1, u - 1);
        if(v < n - k + 1)t2 = _get(1, 1, n - k + 1, v + 1, n - k + 1);
        val = max(t1, t2);
        ds = min(ds, val);
    }
    WriteInt(ds);
}

#define TASK "gifts"

int main()
{
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    Enter();
    Solve();
}
