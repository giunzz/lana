#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const int mod  = 1e9 + 7;
const ll oo   = 1e18 + 1;

ll n, T, a[maxn], s[maxn], f[maxn], k, le[maxn], ri[maxn], res(+oo);

void Init()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
}

void Solve()
{
    for (int i = n; i >= 1; --i)
    {
        if (i + k - 1 > n) le[i] = 0;
        le[i] = max (le[i + 1], s[i + k - 1] - s[i - 1]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i - k + 1 < 1) ri[i] = 0;
        ri[i] = max (ri[i - 1], s[i] - s[i - k]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i + k - 1 > n) continue;
        int u = i - 1;
        int t = i + k;
        res = min (res, max (ri[u], le[t]));
        //cout << i << " " << max (ri[u], le[t]) << endl;
    }
    cout << res;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("gifts.inp", "r", stdin);
    freopen ("gifts.out", "w", stdout);

    Init();
    Solve();
}
// Date 2 Month 12 Year 2017

