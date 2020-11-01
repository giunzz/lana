#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 1000006;
const ll inf = LLONG_MAX;

int n, k;
ll a[maxn], temp, ans = inf;

void inp()
{
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
}

void sub12()
{
    for (int i = k; i <= n; ++i)
    {
        bool ok = true;
        temp = a[i] - a[i-k];
        for (int j = k; j <= i - k; ++j)
            if (a[j] - a[j-k] > temp) { ok = false; break;}
        if (!ok) continue;
        for (int j = i + k; j <= n; ++j)
            if (a[j] - a[j-k] > temp) { ok = false; break;}
        if (!ok) continue;
        ans = min(ans, temp);
    }
}

void sub3()
{
    ans = a[k];

    for (int i = k + 1; i <= n; ++i)
        ans = max(ans, a[k]);
}

void work()
{
    if (n <= 10000) sub12();
    else sub3();
}

void out()
{
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("GIFTS.inp", "r", stdin);
    freopen("GIFTS.out", "w", stdout);

    inp();
    work();
    out();

    return 0;
}
