#include<bits/stdc++.h>
#define For(i, a, b)  for(int i = a; i <= b; ++i)
#define Ford(i, a, b) for(int i = a; i >= b; --i)
#define FileName      "table"
#define ll            long long
#define ld            long double
#define ull           unsigned long long
#define pb            push_back
#define X             first
#define Y             second
#define Karma

using namespace std;

template <typename T> inline void Cin(T &x)
{
    char c;
    T sign = 1;
    x = 0;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') sign = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    x *= sign;
}

typedef pair<int, int> pii;
typedef pair<ll, int> plli;
const int N = 307;

int n, m, k, trace[N][N], u, v, p, q, Max, forbidx, forbidy;
ll f[N][N], a[N][N];
vector<pii> vec;

void Enter()
{
     Cin(n), Cin(m), Cin(k);
     For(i, 1, n)
     {
         For(j, 1, m)
         Cin(a[i][j]);
     }
}

ll DP(int x, int y)
{
    if(f[x][y] != -1 || x < u || x > p || y < v || y > q) return f[x][y];
    if(x == u && y == v) return f[x][y] = a[u][v];
    if(x > 1 && !(x - 1 == forbidx && y == forbidy))
    {
        if(DP(x - 1, y) > f[x][y])
        {
            f[x][y] = DP(x - 1, y);
            trace[x][y] = 1;
        }
    }
    if(y > 1 && !(x == forbidx && y - 1 == forbidy))
    {
        if(DP(x, y - 1) > f[x][y])
        {
            f[x][y] = DP(x, y - 1);
            trace[x][y] = 2;
        }
    }
    f[x][y] += a[x][y];
    return f[x][y];
}

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

void Trace(int x, int y)
{
     if(x == u && y == v) return;
     if(x != p || y != q)
     {
         if(x != u || y != v)
         {
            vec.pb({x, y});
            if(a[x][y] > Max)
            {
                Max = a[x][y];
                forbidx = x;
                forbidy = y;
            }
         }
     }
     if(trace[x][y] == 1) Trace(x - 1, y);
     else Trace(x, y - 1);
}

void Solve()
{
     srand(time(NULL));
     while(k --)
     {
         Cin(u), Cin(v), Cin(p), Cin(q);
         vec.clear();
         memset(&f, -1, sizeof f);
         forbidx = forbidy = Max = -1;
         DP(p, q), Trace(p, q);
         memset(&f, -1, sizeof f);
         ll res = DP(p, q);
         For(i, 1, 20) {
             memset(&f, -1, sizeof f);
             pii t = vec[Rand(0, vec.size() - 1)];
             forbidx = t.X, forbidy = t.Y;
             res = min(res, DP(p, q));
         }
         cout << res << '\n';
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifdef Karma
    freopen(FileName".inp", "r", stdin);
    freopen(FileName".out", "w", stdout);
#endif // Karma

    Enter();
    Solve();

    return 0;
}
