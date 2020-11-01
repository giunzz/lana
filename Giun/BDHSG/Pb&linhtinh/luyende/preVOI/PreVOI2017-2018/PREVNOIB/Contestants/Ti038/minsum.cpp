#include <bits/stdc++.h>

using namespace std;

#define task                        "minsum"
#define int                         long long
#define ft							first
#define nd							second
#define left                        _left
#define right                       _right
#define FOR(i, a, b)                for(int i = a; i <= b; ++i)
#define FORD(i, a, b)               for(int i = a; i >= b; --i)
#define REP(i, a, b)                for(int i = a; i < b; ++i)
#define REPD(i, a, b)               for(int i = (int)a-1; i >= b; --i)
#define ___unique(a)                sort(a.begin(), a.end()); a.resize(unique(a.begin(), a.end())-a.begin());
#define fast                        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CLR(a, x)                   memset(a, x, sizeof a);

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
void write(long long x)
{
    if (x < 0) { putchar('-'); write(abs(x)); }
    if (x > 9) write(x / 10);
    putchar(char(x % 10 + '0'));
}
//--------------------------------------------------------------
vector < int > v;
int res, ans, x1, x2;
int cal(int a)
{
    int res = 1;
    int lim = sqrt(a) + 1;
    FOR(i, 2, lim) if (a % i == 0)
    {
        int cnt = 0;
        while (a % i == 0) a /= i, cnt ^= 1;
        if (cnt) res *= i, v.push_back(i);
    }
    if (a > 1) res *= a, v.push_back(a);
    return res;
}
void backtrack(int i, int now)
{
    if (now >= ans) return;
    if (i == v.size())
    {
        if (ans > now + res / now)
        {
            x1 = now; x2 = res / now;
            ans = now;
        }
        return;
    }
    backtrack(i+1, now * v[i]);
    backtrack(i+1, now);
}
void Solve()
{
    int nn; nn = read();
    while (nn --)
    {
        int a, b; a = read(), b = read();
        v.clear();
        int tmp = __gcd(a, b);
        a /= tmp, b /= tmp;
        x1 = cal(a), x2 = cal(b);
        ans = x1 + x2;
        res = 1;
        REP(i, 0, v.size()) res *= v[i];
        backtrack(0, 1);
        write(x1); putchar(' '); write(x2);
        putchar('\n');
    }
}
main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    fast;

    Solve();

    return 0;
}
