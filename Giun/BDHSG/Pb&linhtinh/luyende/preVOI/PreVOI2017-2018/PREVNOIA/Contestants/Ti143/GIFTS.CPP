#include    <bits/stdc++.h>
#define     TITLE "GIFTS"
#define     ll long long
#define     up(k, n) for (int i = k ; i < n ; i ++)
const int maxT = (int) 1e6 + 7;

using namespace std;

struct ii
{
    ll X, Y, Z;
};

ll n, k, a[maxT], t = 0, dx, dy, ans = 0, res = LLONG_MAX; vector <ii> sum;

bool cmp(ii a, ii b)
{
    return a.X > b.X;
}

void sub3()
{
    stable_sort(sum.begin(), sum.end(), cmp);
    dx = sum[0].Y, dy = sum[0].Z;
    up(1, sum.size())
    {
        if (sum[i].X == sum[0].X)
        {
            if (sum[i].Y <= sum[0].Z) dx = sum[i].Y, dy = sum[i].Z;
        }
        else
        {
            if (sum[i].Y > dy || sum[i].Z < dx)
            {
                cout << sum[i].X;
                return;
            }
        }
    }
    cout << sum[1].X;
}

void sub1()
{
    up(0, sum.size())
    {
        t = sum[i].X, dx = sum[i].Y, dy = sum[i].Z;
        ans = 0;
        for (int j = 0 ; j < sum.size() ; j ++)
        {
            if ((sum[j].Z <= dy && sum[j].Z >= dx) || (sum[j].Y <= dy && sum[j].Y >= dx)) continue;
            ans = max(ans, sum[j].X);
        }
        res = min(res, ans);
    }
    cout << res;
}

void solve()
{
    up(0, k) t += a[i];
    sum.push_back({t, 0, k - 1});
    up(k, n)
    {
        t += a[i];
        t -= a[i - k];
        sum.push_back({t, i - k + 1, i});
    }
    if (n <= 5000) sub1();
    else sub3();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    cin >> n >> k;
    up(0, n) cin >> a[i];
    solve();
}
