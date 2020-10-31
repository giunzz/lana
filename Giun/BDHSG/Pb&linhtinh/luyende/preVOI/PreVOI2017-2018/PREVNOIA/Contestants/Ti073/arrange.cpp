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

#define maxn int(1e5 + 5)
int n, a[maxn];

void Enter()
{
    n = ReadInt();
    for(int i = 1; i <= n; ++i)a[i] = ReadInt();
}

int64_t S, ds, b[maxn];

void Solve1()
{
    for(int i = 1; i <= n; ++i)b[i] = a[i];
    for(int i = 1; i < n; ++i)
    {
        b[i + 1] += (b[i] - S / n);
        ds += abs(b[i] - S / n);
    }
}

int64_t x[maxn], S1;

void Try()
{
    int64_t val = 0;
    for(int i = 1; i <= n; ++i)b[i] = a[i];
    for(int i = 1; i < n; ++i)
    {
        b[i + 1] += (b[i] - x[i]);
        val += abs(b[i] - x[i]);
    }
    ds = min(ds, val);
}

void BackTrack(int k)
{
    if(k > n && S1 == S){Try(); return;}
    for(int i = S / n; i <= S / n + 1; ++i)
    {
        x[k] = i;
        S1 += i;
        if(S1 + (S / n) * (n - k) <= S && S1 + (S / n + 1) * (n - k) >= S)BackTrack(k + 1);
        S1 -= i;
    }
}

#define INF 1000000000000000001LL

void Solve2()
{
    ds = INF;
    BackTrack(1);
}

void Solve()
{
    for(int i = 1; i <= n; ++i)S += a[i];
    if(S % n == 0)Solve1();
    else Solve2();
    WriteInt(ds);
}

#define TASK "arrange"

int main()
{
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    Enter();
    Solve();
}
