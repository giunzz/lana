#include <bits/stdc++.h>
#define INF 1e18
using namespace std;

const int maxn = 1e5 + 10;
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

int n;
int a[maxn];
long long f[maxn];

void load() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
}

void sub1(long long mid) {
    long long ans = 0, cur = 0;
    for (int i = 1; i <= n; ++i) a[i] -= mid;
    for (int i = 1; i <= n; ++i) {
        ans += abs(cur);
        cur += a[i];
    }
    writeln(ans);
}

long long calc(int l, int r) { return 1ll * (r - l + 1) * (r - l + 2) / 2; }

void sub23(long long mid) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i) a[i] -= mid;
    for (int i = n; i > 0; --i) {
        if (a[i] < 0) f[i] = f[i + 1] - a[i];
        else f[i] = i == n ? -a[i] : f[i + 1] - min(f[i + 1], 1ll * a[i]);
    }
    long long need = 0, now = 0;
    for (int i = 1; i <= n; ++i) {
        ans += need + now;
        if (a[i] < 0) {
            if (-a[i] > now) a[i] += now, now = 0;
            else {
                now += a[i];
                a[i] = 0;
            }
            need += abs(a[i]);
        }
        else {
            int dec = min(need, 1ll * a[i]);
            need -= dec; a[i] -= dec;
            if (f[i + 1] > 0) now += min(1ll * a[i], f[i + 1]);
        }
        if (a[i] < 0) a[i] = 0;
    }

    writeln(ans);
}

void process() {
    long long sum = 0;
    for (int i = 1; i <= n; ++i) sum += a[i];

    if (sum % n == 0) {
        sub1(sum / n);
    } else {
        sub23(sum / n);
    }
}

int main() {
    freopen("ARRANGE.inp", "r", stdin);
    freopen("ARRANGE.out", "w", stdout);

    load();
    process();

    return 0;
}
