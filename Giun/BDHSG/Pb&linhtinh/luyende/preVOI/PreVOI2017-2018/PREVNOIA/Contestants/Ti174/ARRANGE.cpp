#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 100005;
const ll inf = LLONG_MAX;

int n, a[maxn];
ll s, ans;

void inp()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s += a[i];
    }
}

void sub1()
{
    s /= n;
    for (;;)
    {
        int mnx = 1, mxx = 1;
        for (int i = 2; i <= n; ++i)
            {
                if (a[i] < a[mnx]) mnx = i;
                if (a[i] > a[mxx]) mxx = i;
            }
        if (a[mxx] - a[mnx] <= 0) { cout << ans; return;}
        ans += min(s - a[mnx], a[mxx] - s)*abs(mxx - mnx);
        a[mxx] = a[mxx] - s + a[mnx];
        a[mnx] = s;
    }
}

void work()
{
    if (s % n == 0) sub1();
    else cout << 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("ARRANGE.inp", "r", stdin);
    freopen("ARRANGE.out", "w", stdout);

    inp();
    work();

    return 0;
}
