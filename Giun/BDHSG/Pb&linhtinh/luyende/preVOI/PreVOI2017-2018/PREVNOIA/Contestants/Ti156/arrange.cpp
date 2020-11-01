#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[100010];

main() {
    freopen("arrange.inp", "r", stdin);
    freopen("arrange.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > s / n) {
            res += a[i] - s / n;
            a[i + 1] += a[i] - s / n;
        }
        else if (a[i] < s / n) {
            int j = i + 1;
            while (a[i] < s / n) {
                int t = min(s / n - a[i], a[j]);
                res += t * (j - i);
                a[i] += t;
                a[j] -= t;
                ++j;
            }
        }
    }
    cout << res;
}
