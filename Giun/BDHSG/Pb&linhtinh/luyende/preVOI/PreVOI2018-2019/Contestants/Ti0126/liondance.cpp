#include <bits/stdc++.h>

#define text "LIONDANCE"

using namespace std;

const int maxn  = 1e6+7;

int n, k, a[maxn], b[maxn], m, c[maxn];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    freopen(text".inp", "r", stdin);
    freopen(text".out", "w", stdout);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    for (int i = 1; i <= n; ++i)
    {
        c[1] = a[1];
        if (a[i] - a[i+1] <= k && a[i] == b[i]) m++;
        if (a[i] - a[i+1] <= k) c[m] = a[i];
    }

    cout << m << "\n";

    for (int i = 1; i <= m; ++i) cout << c[i] << " ";

    return 0;
}
