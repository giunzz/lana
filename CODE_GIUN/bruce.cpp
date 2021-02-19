#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int oo = 1e9 + 7;

#define FileOpen freopen ("input.inp", "r", stdin);	freopen ("output.txt", "w", stdout);

int n, a[N], ans = oo;

int main() {
    FileOpen;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            int s = 0;
            for (int k = i; k <= j; k++) {
                s += a[k];
            }
            ans = min(ans, s);
        }
    }
    cout << ans << endl;
}
