#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define fi first
#define se second
#define Tpair pair <ll, ll>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const int mod  = 1e9 + 7;
const ll oo   = 1e18 + 1;

ll n, T, a, b, res(+oo), kq1, kq2;
set <Tpair> mp;
queue <Tpair> q;

ll GCD (ll x, ll y)
{
    while (y != 0)
    {
        ll r = x % y;
        x = y; y = r;
    }
    return x;
}

void Check (ll u, ll t)
{
    if (!mp.count(make_pair(u, t)))
    {
        mp.insert (make_pair(u, t));
        mp.insert (make_pair(t, u));
        q.push ({u, t});
    }
}

void Init()
{
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        mp.clear();
        cin >> a >> b;
        Check (a, b);

        while (!q.empty())
        {
            Tpair Top = q.front(); q.pop();
            //cerr << Top.fi << " " << Top.se << endl;
            if (res > Top.fi + Top.se)
            {
                kq1 = Top.fi; kq2 = Top.se;
                res = Top.fi + Top.se;
            }

            for (int i = 1; i * i <= Top.fi; ++i)
                if (Top.fi % i == 0)
                {
                    ll u = Top.fi / i;
                    ll t = Top.se * i;
                    Check (u, t);

                    u = Top.fi / (Top.fi / i);
                    t = Top.se * (Top.fi / i);
                    Check (u, t);
                }

            swap (Top.fi, Top.se);
            for (int i = 1; i * i <= Top.fi; ++i)
                if (Top.fi % i == 0)
                {
                    ll u = Top.fi / i;
                    ll t = Top.se * i;
                    Check (u, t);

                    u = Top.fi / (Top.fi / i);
                    t = Top.se * (Top.fi / i);
                    Check (u, t);
                }

            ll r = GCD (Top.fi, Top.se);
            for (int i = 1; i * i <= r; ++i)
                if (r % i == 0)
                {
                    ll u = Top.fi / i;
                    ll t = Top.se / i;
                    Check (u, t);

                    u = Top.fi / (r / i);
                    t = Top.se / (r / i);
                    Check (u, t);
                }
        }
        cout << kq1 << " " << kq2 << endl;
    }

}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("minsum.inp", "r", stdin);
    freopen ("minsum.out", "w", stdout);

    Init();
}
// Date 2 Month 12 Year 2017

