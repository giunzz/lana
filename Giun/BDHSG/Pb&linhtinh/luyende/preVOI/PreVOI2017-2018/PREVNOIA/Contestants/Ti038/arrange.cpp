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
    do {
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
const int N = 1e5 +10;
int n, tot;
int a[N];
void Enter()
{
    n = read();
    FOR(i, 1, n) a[i] = read(), tot += a[i];
}
namespace subtask1 {
    void run()
    {
        tot /= n;
        int ans = 0;
        deque < int > v1, v2;
        FOR(i, 1, n) if (a[i] > tot) v1.push_back(i);
            else if (a[i] < tot) v2.push_back(i);
        while (v1.size() || v2.size())
        {
            int u = a[v1.front()], v = a[v2.front()];
            int hold = min(u - tot, tot - v);
            a[v1.front()] -= hold; a[v2.front()] += hold;
            ans += hold * abs(v1.front() - v2.front());
            if (u - tot > tot - v) v2.pop_front();
            else if (tot - v > u - tot) v1.pop_front();
            else v1.pop_front(), v2.pop_front();
        }
        write(ans);
    }
}
namespace full {
    int sum[N];
    void run()
    {
        int ans = 0;
        int lo = tot / n, hi = lo + 1;
        FOR(i, 1, n) sum[i] = sum[i-1] + a[i];
        FOR(i, 1, n)
        {
            if (sum[i] - sum[i-1] > hi) ans += (sum[i] - (sum[i-1] + hi)), sum[i] = sum[i-1] + hi;
            if (sum[i] - sum[i-1] < lo) ans += (sum[i-1] + lo - sum[i]), sum[i] = sum[i-1] + lo;
        }
        write(ans);
    }
}
void Solve()
{
    if (tot % n == 0) subtask1 :: run();
    else
        full :: run();
}
main()
{
    freopen("arrange.inp", "r", stdin);
    freopen("arrange.out", "w", stdout);

    Enter();
    Solve();

    return 0;
}
