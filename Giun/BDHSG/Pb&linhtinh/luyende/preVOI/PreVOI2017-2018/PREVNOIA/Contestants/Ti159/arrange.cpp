#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const long long INF = 1e18;

int n, need;
long long val;
long long a[N];
long long f[2][N];

int main() {
    freopen("arrange.inp", "r", stdin);
    freopen("arrange.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
    need = a[n] % n, val = a[n] / n;
    for (int i = 1; i <= need; ++i) f[0][i] = INF;
    for (int i = 1; i <= n; ++i) {
        bool t = i & 1;
        for (int j = 0; j <= need; ++j) {
            long long cost = abs(a[i] - val * i - j);
            f[t][j] = f[t ^ 1][j] + cost;
            if (j) f[t][j] = min(f[t][j], f[t ^ 1][j - 1] + cost);
        }
    }
    cout << f[n & 1][need];
}

/*
8
2 2 2 2 1 9 1 2
*/
