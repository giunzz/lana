#include <bits/stdc++.h>

#define text "MODULO"

using namespace std;

const int maxn = 1e6+7;

int n, k, s, a[maxn], q;

int TRY (int x)
{
    s = 0; q = 1;
    for (int i = 1; i <= n; ++i)
    {
        q *= 2;
        if (s == 0) s += a[x];
        else
        {
            s *= 10;
            if (x == 1) s += a[x+1];
            else s += a[x-1];
        }
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    freopen(text".INP", "r", stdin);
    freopen(text".OUT", "w", stdout);

    for (int i = 1; i <= 2; ++i) cin >> a[i];
    cin >> n >> k;

    int ans = 0;

    for (int i = 1; i <= 2 ; ++i) if (TRY(i) % q == k) ans = TRY(i);

    if (ans > 0) cout << ans;
    else cout << -1;

    return 0;
}
