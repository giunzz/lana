#include <bits/stdc++.h>

using namespace std;

int n, k, qu[30], re[30], a[30], b[30];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("LIONDANCE.INP", "r", stdin);
    freopen("LIONDANCE.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 0; i < (1ll << n); i++)
    {
        int q = 0, p = 1, t = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1) qu[++q] = a[j + 1];
        qu[0] = qu[1];
        for (int j = 1; j <= q; j++)
            if (abs(qu[j] - qu[j - 1]) > k) t = 1;
        if (t) continue;
        int il = q;
        for (int j = 1; j <= n; j++)
        {
            if (b[j] == a[p]) { ++q; ++p; }
            if (p > il) break;
        }
        if (q / 2 == il)
        {
            if (il < re[0]) continue;
            if (il > re[0]) { re[0] = il; for (int j = 1; j <= il; j++) re[j] = qu[j]; }
                else
                {
                    for (int j = 1; j <= il; j++)
                    {
                        if (qu[j] < re[j]) continue;
                        if (qu[j] > re[j]) { for (j = 1; j <= il; j++) re[j] = qu[j]; break; }
                    }
                }
        }
    }
    cout << re[0] << '\n';
    for (int i = 1; i <= re[0]; i++) cout << re[i] << ' ';
    return 0;
}
