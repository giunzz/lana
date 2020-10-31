#include <bits/stdc++.h>

using namespace std;

int ReadInt()
{
    char c; int sgn;
    for(c = getchar(); c != '-' && (c < '0' || c > '9'); c = getchar());
    int ans;
    if(c == '-')ans = 0, sgn = -1;
    else ans = c - '0', sgn = 1;
    for(c = getchar(); c >= '0' && c <= '9'; c = getchar())
        ans = ans * 10 + c - '0';
    ans *= sgn;
    return ans;
}

void WriteInt(int x)
{
    if(x > 9)WriteInt(x / 10);
    putchar(x % 10 + '0');
}

#define maxm 2001
#define maxn 16
int m, n, k, ok, xs, ys, zs;
typedef pair<int, int> I2;
typedef pair<I2, I2> I4;
#define ft first
#define sc second
I4 p[maxm], a[maxn];

void Enter()
{
    m = ReadInt(); n = ReadInt(); k = ReadInt();
    ok = 1;
    for(int i = 1; i <= m; ++i)
    {
        int x = ReadInt(), y = ReadInt(), z = ReadInt(), r = ReadInt();
        if(z != 0 || y != 0)ok = 2;
        p[i] = I4(I2(x, y), I2(z, r));
    }
    for(int i = 1; i <= n; ++i)
    {
        int x = ReadInt(), y = ReadInt(), z = ReadInt(), e = ReadInt();
        if(z != 0 || y != 0)ok = 2;
        a[i] = I4(I2(x, y), I2(z, e));
    }
    xs = ReadInt(); ys = ReadInt(); zs = ReadInt();
    if(zs != 0 || ys != 0)ok = 2;
}

int nho[1 << maxn], dp[1 << maxn], dd[maxm], deg[maxn];
vector<int> g[maxn];

int calc(int x, int cnt)
{
    if(cnt == 0 || x == 0)return 0;
    if(nho[x])return dp[x];
    nho[x] = 1; dp[x] = 0;
    for(int i = 1; i <= n; ++i)if((x >> (i - 1)) & 1)
    {
        int y = x ^ (1 << (i - 1)), val = 0;
        for(int j = 0; j < deg[i]; ++j)
        {
            int k = g[i][j];
            if(dd[k] == 0)++val;
            ++dd[k];
        }
        if(val <= cnt)dp[x] = max(dp[x], calc(y, cnt - val) + a[i]. sc. sc);
        for(int j = 0; j < deg[i]; ++j)
        {
            int k = g[i][j];
            --dd[k];
        }
    }
    return dp[x];
}

bool namtrong(int A, int B, int C, int r)
{
    return (abs(C - A) <= r && abs(C - B) <= r);
}

bool namngoai(int A, int B, int C, int r)
{
    return ((A < C - r && B < C - r) || (A > C + r && B > C + r));
}

void Solve1()
{
    int A = xs;
    for(int i = 1; i <= n; ++i)
    {
        int B = a[i]. ft. ft;
        for(int j = 1; j <= m; ++j)
        {
            int C = p[j]. ft. ft;
            int r = p[j]. sc. sc;
            if(!(namtrong(A, B, C, r) || namngoai(A, B, C, r)))g[i]. push_back(j), ++deg[i];
        }
    }
    int ds = calc((1 << n) - 1, k);
    if(k == 0)for(int i = 1; i <= n; ++i)if(deg[i] == 0)ds += a[i]. sc. sc;
    WriteInt(ds);
}

void Solve2()
{

}

void Solve()
{
    if(ok == 1)Solve1();
    if(ok == 2)Solve2();
}

#define TASK "teaworld"

int main()
{
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    Enter();
    Solve();
}
