#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

struct node {
    long long sum, x, y;
    node() {}
    node(long long sum, long long x, long long y) : sum(sum), x(x), y(y) {}
};

int gcd(int A, int B) {
    if (A < B) return gcd(B, A);
    if (!B) return A;
    return gcd(B, A % B);
}

node get(int A, int B) {
    long long r = A + B, X, Y;
    for (int i = 1; i * i <= A; ++i) if (A % i == 0) {
        long long x = i;
        if (r > A / x + B * x) {
            r = A / x + B * x;
            X = A / x; Y = B * x;
        }
        x = A / i;
        if (r > A / x + B * x) {
            r = A / x + B * x;
            X = A / x; Y = B * x;
        }
    }
    return node(r, X, Y);
}

void compare(node &p, node q) {
    if (p.sum > q.sum) p = q;
}

int main() {
    freopen("MINSUM.inp", "r", stdin);
    freopen("MINSUM.out", "w", stdout);

    int t; scanf("%d", &t);
    while (t--) {
        int A, B; scanf("%d%d", &A, &B);
        int g = gcd(A, B);
        A /= g; B /= g;
        node ans = node(A + B, A, B);
        compare(ans, get(A, B));
        compare(ans, get(B, A));
        printf("%lld %lld\n", ans.x, ans.y);
    }

    return 0;
}
