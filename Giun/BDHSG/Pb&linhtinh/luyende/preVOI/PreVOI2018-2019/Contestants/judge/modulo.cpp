#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
int a, b, n, d;
ull k, p;
int ans[65];

ull mul(ull x, ull y, ull m) {
    ull r = 0;
    while (y) {
        if (y & 1) r = (r + x) % m;
        x = (x + x) % m;
        y >>= 1;
    }
    return r;
}

int main(void) {
    	freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> n >> k;
    p = 1ULL << n;
    if (a < b) swap(a, b);
    d = a - b;
    ull current = 0;
    for (int i = 0; i < n; ++i) current = (mul(current, 10, p) + b) % p; //bbb...b
    k = (k + p - current) % p;
    while (k % 2 == 0 && d % 2 == 0) k /= 2, d /= 2;
    if (d % 2 == 0) return cout << -1 << endl, 0;

    ull coefficient = d;
    for (int i = 0; i < n; ++i) {
        if (k >> i & 1) {
            ans[i] = a;
            k = (k + p - coefficient) % p;
        }
        else ans[i] = b;
        coefficient = mul(coefficient, 10, p);
    }
    for (int i = n - 1; i >= 0; --i) cout << ans[i];
    cout << endl;
    return 0;
}
