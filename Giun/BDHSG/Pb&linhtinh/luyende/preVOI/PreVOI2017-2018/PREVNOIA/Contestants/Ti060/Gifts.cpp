#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+6;

int n, k;
int a[maxn];
long long s[maxn], rmq[25][maxn];
long long res = LLONG_MAX;

void build(int m)
{
    int k = log2(m);
    for (int i=1; i<=m; i++)
        rmq[0][i] = s[i];
    for (int j=1; j<=k; j++)
        for (int i=1; i<=m; i++)
        {
            if (i + (1 << j) - 1 > m) break;
            rmq[j][i] = max(rmq[j-1][i], rmq[j-1][i + (1 << (j - 1))]);
        }
}

long long  get(int l, int r)
{
    int k = log2(r - l + 1);
    return max(rmq[k][l], rmq[k][r - (1 << k) + 1]);
}

int main()
{
    freopen ("Gifts.inp", "r", stdin);
    freopen ("Gifts.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=k; i++)
        s[1] += a[i];
    int m = n - k + 1;
    for (int i=2; i<=m; i++)
        s[i] = s[i-1] - a[i-1] + a[i+k-1];
    build(m);
    for (int i=1; i<=m; i++)
    {
        long long ans = 0;
        if (i <= n - 2*k + 1)
            ans = max(ans, get(i+k, m));
        if (i > k)
            ans = max(ans, get(1, i-k));
        res = min(res, ans);
        //cout << i << ' ' << res << '\n';
    }
    //cout << get(5, m) << ' ';
    cout << res;
}
