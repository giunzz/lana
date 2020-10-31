#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000010;
int n, k, a[N], f[N], Max[4 * N];
int max_range(int u, int ll, int rr, int L, int R){
    if (L > rr || ll > R) return -1e15;
    if (L <= ll && rr <= R) return Max[u];
    int M = (ll + rr) >> 1;
    return max(max_range(u * 2, ll, M, L, R), max_range(u * 2 + 1, M + 1, rr, L, R));
}
void inc_range(int u, int ll, int rr, int L, int R, int X){
    if (ll > R || L > rr) return;
    if (L <= ll && rr <= R) {
        Max[u] += X;
        return;
    }
    int M = (ll + rr) >> 1;
    inc_range(u * 2, ll, M, L, R, X);
    inc_range(u * 2 + 1, M + 1, rr, L, R, X);
    Max[u] = max(Max[u * 2], Max[u * 2 + 1]);
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("gifts.inp", "r", stdin);
    freopen("gifts.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    if (n <= 5000) {
        int ans = 1e18;
        for (int i = 1; i <= n - k + 1; i++) {
            int tmp = 0;
            for (int j = 1; j <= i - k; j++) tmp = max(tmp, f[j + k - 1] - f[j - 1]);
            for (int j = i + k; j <= n - k + 1; j++) tmp = max(tmp, f[j + k - 1] - f[j - 1]);
            ans = min(ans, tmp);
        }
        cout << ans;
    }
    else {
        for (int i = 1; i <= n - k + 1; i++) inc_range(1, 1, n, i, i, f[i + k - 1] - f[i - 1]);
        int ans = 1e18;
        for (int i = 1; i <= n - k + 1; i++) {
            int tmp = 0;
            if (i - k >= 1) tmp = max(tmp, max_range(1, 1, n, 1, i - k));
            if (i + k <= n - k + 1) tmp = max(tmp, max_range(1, 1, n, i + k, n - k + 1));
            ans = min(ans, tmp);
        }
        cout << ans;
    }
    return 0;
}
