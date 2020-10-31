#include <bits/stdc++.h>
#define task "MINSUM."
#define ff(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define inf 1e9
#define pb push_back
using namespace std;
typedef long long ll;

const ll maxn = 1e18 + 1;
int t;
ll minv;

inline int readint()
{
    ll sign = 1;
    char c;
    do
    {
        c = getchar();
        if (c == '-') sign = -sign;
    }
    while (c < '0' || c > '9');
    ll res;
    for (res = 0; c >= '0' && c <= '9'; c = getchar())
        res = res * 10 + (c - '0');
    return res * sign;
}

void enter()
{
    freopen(task"inp", "r", stdin);
    freopen(task"out", "w", stdout);
    ios_base::sync_with_stdio(false);
    t = readint();
}

ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void findout(ll x)
{

    ll can = sqrt(x);
    ll v1 = 0, v2 = 0;
    while (can >= 1)
    {
        if (x % can == 0)
        {
            ll y = x / can;
            ll tg = gcd(can, y);
            if (tg != 1)
            {
                printf("%lld %lld\n", can / tg, y / tg);
                return;
            }
            else
            if (minv > can + y)
            {
                minv = can + y;
                v1 = can; v2 = y;
            }
        }
        --can;
    }
    printf("%lld %lld\n", v1, v2);
}

void solve()
{
    enter();
    while (t--)
    {
        ll a, b;
        a = readint(); b = readint();
        ll ucln = gcd(a, b);
        minv = maxn;
        if (ucln != 1)
            printf("%lld %lld\n", a / ucln, b / ucln);
        else
        {
            ll tich = a * b;
            findout(tich);
        }
    }
}

int main()
{
    solve();
}

