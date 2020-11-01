#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001000
#define pp pair<int, int>
#define IO cin.tie(NULL);cout.tie(NULL);
#define bit(S, i) (((S) >> i) & 1)
template<typename T> inline void read(T &x) {
    char c;
    bool neg = false;
    while (!isdigit(c = getchar()) && c != '-');
    x = 0;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    do {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
    if (neg) x = -x;
}
template<typename T> inline void write(T x) {
    if (x < 0) {
        putchar('-');
        write(-x);return;
    }
    if (x < 10) {
        putchar(char(x + 48));
    }
    else {
        write(x/10);
        putchar(char(48 + x%10));
    }
}
template<typename T> inline void writeln(T x) {
    write(x);
    putchar('\n');
}
using namespace std;

int n, k;
long long a[N], s[N], LEFT[N], RIGHT[N];
int main() {
    IO;
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    read(n); read(k);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) s[i] = s[i - 1] + a[i];
    FORD(i, n - k + 1, 1) RIGHT[i] = max(RIGHT[i + 1], s[i + k - 1] - s[i - 1]);
    FOR(i, k, n) LEFT[i] = max(LEFT[i - 1], s[i] - s[i - k]);
    long long ans = 1e18;
    FOR(i, 1, n - k + 1) {
        if (i > k && i + k + k - 1 <= n) {
            ans = min(ans, max(LEFT[i - 1], RIGHT[i + k]));
        }
        else {
            if (i <= k) ans = min(ans, RIGHT[i + k]);
            else ans = min(ans, LEFT[i - 1]);
        }
    }
    writeln(ans);
}
