#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const int mod  = 1e9 + 7;
const ll oo   = 1e18 + 1;

ll n, T, a[maxn], sum(0), f[maxn], dp[2001][2001];

void Sub1()
{
    ll k = sum / n, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += abs (a[i] - k);
        a[i + 1] += (a[i] - k);
    }
    cout << ans;
}

void Sub2()
{
    ll x; int cnt; sum -= n;
    for (int i = 1; i <= n; ++i)
        if ((sum + i) % n == 0)
        {
            cnt = i; x = (sum + i) / n;
            break;
        }

    //cout << x << " " << cnt << endl;

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= min (cnt, i); ++j)
        {
            dp[i][j] = +oo;

            if (i - 1 >= j)
            {
                ll u = f[i] - j * x - (i - 1 - j) * (x + 1);
                dp[i][j] = dp[i - 1][j] + abs (u - (x + 1));
            }
            if (j != 0)
            {
                ll u = f[i] - (j - 1) * x - (i - 1 - (j - 1)) * (x + 1);
                dp[i][j] = min (dp[i][j], dp[i - 1][j - 1] + abs (u - x));
            }
            //cout << i << " " << j << " " << dp[i][j] << " " << u << " " << f[i] << endl;
        }
    cout << dp[n][cnt];
}

void Init()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i]; sum += a[i];
        f[i] = f[i - 1] + a[i];
    }
    if (sum % n == 0) Sub1();
    else Sub2();
    //Sub1(); cout << endl; Sub2();
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("arrange.inp", "r", stdin);
    freopen ("arrange.out", "w", stdout);

    Init();
}
// Date 2 Month 12 Year 2017

