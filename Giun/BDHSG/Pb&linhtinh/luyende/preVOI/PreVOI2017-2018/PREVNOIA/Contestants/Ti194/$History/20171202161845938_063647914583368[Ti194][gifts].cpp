#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 7;

int n, k, dem = 0;

long long a[maxn], b[maxn], maxt[maxn], maxp[maxn], kq = LLONG_MAX, kqphu;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("gifts.inp", "r", stdin);
    freopen("gifts.out", "w", stdout);
    cin >> n >> k;
    a[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
        if(i >= k) {b[++dem] = a[i] - a[i - k];}
    }
    int t = n - k + 1;
    maxt[0] = 0;
    maxp[t + 1] = 0;
    for(int i = 1; i <= t; i++)
    {
        maxt[i] = max(maxt[i - 1], b[i]);
    }
    for(int i = t; i >= 1; i--)
    {
        maxp[i] = max(maxp[i + 1], b[i]);
    }
    for(int i = 1; i <= t; i++)
    {
        kqphu = max(maxt[max(i - k, 0)], maxp[min(i + k, n + 1)]);
        kq = min(kq, kqphu);
    }
    cout << kq;
}
