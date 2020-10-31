#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int lg[(1 << 20) + 1];

int main(void) {
    freopen("minsum.inp", "r", stdin);
    freopen("minsum.out", "w", stdout);
    for (int i = 0; i <= 20; ++i) lg[1 << i] = i;
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        vector <int> primes;
        for (int i = 2; i <= 100000; ++i) {
            int odd = 0;
            while (a % i == 0) odd ^= 1, a /= i;
            while (b % i == 0) odd ^= 1, b /= i;
            if (odd) primes.push_back(i);
        }
        if (a > 1 && a != b) primes.push_back(a);
        if (b > 1 && b != a) primes.push_back(b);
        int n = primes.size();
        vector <long long> product(1 << n);
        product[0] = 1;
        for (int i = 1; i < (1 << n); ++i) {
            int last = lg[i&-i];
            product[i] = product[i - (1 << last)] * primes[last];
        }
        long long minsum = 1LL << 60, x = -1, y = -1;
        for (int i = 0; i < (1 << n); ++i) {
            long long sum = product[i] + product[(1 << n) - 1 - i];
            if (minsum > sum) {
                minsum = sum;
                x = product[i];
                y = product[(1 << n) - 1 - i];
            }
        }
        cout << x << ' ' << y << endl;
    }
}
