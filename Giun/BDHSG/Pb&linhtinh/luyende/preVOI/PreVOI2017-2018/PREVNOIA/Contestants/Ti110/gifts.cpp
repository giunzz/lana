#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18 + 7;
const int MAXN = 1e6 + 7;
int n, k, a[MAXN], f[MAXN], res = inf, g[MAXN], maxL[MAXN], maxR[MAXN];

bool check(int i, int j)
{
    int l1 = i, l2 = j;
    if (l1 > l2) swap(l1, l2);
    if (l1 + k - 1 >= l2) return 0;
    if (l2 + k - 1 > n) return 0;
    return 1;
}

main()
{
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    if (n <= 1000)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            int cur = 0;
            for(int j = 1 ; j <= n ; j++)
                if (check(i, j))
                    cur = max(cur, f[j + k - 1] - f[j - 1]);
            if (cur != 0) res = min(res, cur);
        }
        cout << res;
        return 0;
    }
    for(int i = 1 ; i <= n - k + 1 ; i++)
    {
        g[i] = f[i + k - 1] - f[i - 1];
        maxL[i] = max(maxL[i - 1], g[i]);
    }
    for(int i = n - k + 1 ; i >= 1 ; i--)
    {
        maxR[i] = max(maxR[i + 1], g[i]);
    }
    for(int i = 1 ; i <= n - k + 1 ; i++)
    {
        int kq = 0;
        if (i - k > 0) kq = max(kq, maxL[i - k]);
        if (i + k - 1 < n - k + 1) kq = max(kq, maxR[i + k]);
        if (kq != 0) res = min(res, kq);
    }
    cout << res;
    return 0;
}
