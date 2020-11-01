#include<bits/stdc++.h>

using namespace std;

const long long oo = 1e17 + 7;
const int maxN = 1e5 + 7;
long long m, n, k, a[maxN], sum[maxN], res, t[maxN], st[4*maxN];

long long build(int in, int l, int r)
{
    if (l == r) return st[in] = t[l];
    int mid = (l + r)/2;
    int p1 = build(in*2, l, mid);
    int p2 = build(in*2 + 1, mid + 1, r);
    return st[in] = max(p1, p2);
}

long long getmax(int in, int l, int r, int i, int j)
{
    if (r < i || l > j) return -1e17;
    if (l >= i && r <= j)   return st[in];
    int mid = (l + r)/2;
    long long p1 = getmax(in*2, l, mid, i, j);
    long long p2 = getmax(in*2 + 1, mid + 1, r, i, j);
    return max(p1, p2);
}

int main()
{
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if (n <= 5000)
    {
        for (int i = 1; i <= n; i++)    cin >> a[i];
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i];
        res = oo;
        for (int i = 1; i <= n - k + 1; i++)
        {
            // i -> i + k - 1 bi loai bo
            long long tes = 0;
            for (int j = 1; j <= n - k + 1; j++)
            {
                int l = j, r = j + k - 1;
                if (r >= i && r <= i + k - 1) continue;
                if (l >= i && l <= i + k - 1) continue;
                tes = max(tes, sum[r] - sum[l - 1]);
            }
            res = min(res, tes);
        }
        cout << res;
        exit(0);
    }
    for (int i = 1; i <= n; i++)    cin >> a[i];
    for (int i = 1; i <= n; i++)    sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n - k + 1; i++)
    {
        int l = i, r = i + k - 1;
        t[i] = sum[r] - sum[l - 1];
    }
    m = n - k + 1;
    res = oo;
    build(1, 1, m);
    for (int i = 1; i <= m; i++)
    {
        // i -> i + k - 1;
        int l = i - k, r = i + k;
        long long p1, p2;
        if (l >= 1) p1 = getmax(1, 1, m, 1, l);
        if (r <= m) p2 = getmax(1, 1, m, r, m);
        long long tes = max(p1, p2);
        res = min(res, tes);
    }
    cout << res;
    return 0;
}

