#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, res, aa, bb;
int memo[55][55];

void solve(int a, int b) {
    if (a > b) swap(a, b);
    if (memo[a][b]) return;
    memo[a][b] = 1;
    if (a + b < res) {
        res = a + b;
        aa = a;
        bb = b;
    }
    for (int i = 2; i <= 50; ++i) {
        if (a % i == 0) solve(a / i, b * i);
        if (b % i == 0) solve(a * i, b / i);
        if (a % i == 0 && b % i == 0) solve(a / i, b / i);
    }
}

main() {
    freopen("minsum.inp", "r", stdin);
    freopen("minsum.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a > 50 || b > 50) {
            int g = __gcd(a, b);
            cout << a / g << " " << b / g << "\n";
            continue;
        }
        memset(memo, 0, sizeof(memo));
        res = 1e15;
        solve(a, b);
        cout << aa << " " << bb << "\n";
    }
}
