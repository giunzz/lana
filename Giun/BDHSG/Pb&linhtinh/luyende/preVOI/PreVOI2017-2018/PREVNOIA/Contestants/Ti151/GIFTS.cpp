#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 1e6 + 10;
template <class T> bool read(T &x) {
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-' && c != EOF);
    if (c == EOF) return 0;
    if (c == '-') nega = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
    return 1;
}
template <class T> void wri(T x) { if (x / 10) wri(x / 10); putchar(x % 10 + '0'); }
template <class T> void write(T x) { if (x < 0) putchar('-'), x = -x; wri(x); }
template <class T> void writeln(T x) { write(x); putchar('\n'); }

int n, k;
long long sum[maxn], f[maxn], g[maxn];

int main() {
    freopen("GIFTS.inp", "r", stdin);
    freopen("GIFTS.out", "w", stdout);

    read(n); read(k);
    for (int i = 1; i <= n; ++i) {
        read(sum[i]);
        sum[i] += sum[i - 1];
    }

    f[k] = sum[k];
    for (int i = k + 1; i <= n; ++i) f[i] = max(f[i - 1], sum[i] - sum[i - k]);
    g[n - k + 1] = sum[n] - sum[n - k];
    for (int i = n - k; i > 0; --i) g[i] = max(g[i + 1], sum[i + k - 1] - sum[i - 1]);
    long long ans = 1e18;
    for (int i = 1; i <= n - k; ++i) {
        long long cur = 1e18;
        if (i > k && i + k - 1 <= n - k) ans = min(ans, max(f[i - 1], g[i + k]));
        else if (i > k) ans = min(ans, f[i - 1]);
        else if (i + k - 1 <= n - k) ans = min(ans, g[i + k]);
    }
    writeln(ans);

    return 0;
}
