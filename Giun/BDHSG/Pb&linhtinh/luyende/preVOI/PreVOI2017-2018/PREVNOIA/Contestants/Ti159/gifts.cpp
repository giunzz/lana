#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, k;
int a[N];
long long res = 1e18, sum[2][N];
long long f[2][N];

int main() {
    freopen("gifts.inp", "r", stdin);
    freopen("gifts.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) sum[0][i] = sum[0][i - 1] + a[i];
    for (int i = n; i >= 1; --i) sum[1][i] = sum[1][i + 1] + a[i];
    for (int i = 1; i <= n; ++i) {
        f[0][i] = max(f[0][i], f[0][i - 1]);
        if (i - k + 1 >= 1) f[0][i] = max(f[0][i], sum[0][i] - sum[0][i - k]);
    }
    for (int i = n; i >= 1; --i) {
        f[1][i] = max(f[1][i], f[1][i + 1]);
        if (i + k - 1 <= n) f[1][i] = max(f[1][i], sum[1][i] - sum[1][i + k]);
    }
    for (int i = 1; i + k - 1 <= n; ++i) {
        res = min(res, max(f[0][i - 1], f[1][i + k]));
    }
    cout << res;
}
