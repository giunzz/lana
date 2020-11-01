#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
#define f first
#define s second

map<ll, ii> f;
int a, b, n;
ll k, m, mu[30];

void Inkq(ll x, ll y) {
    vector<int> res;
    while (x) {
        res.push_back(x % 10);
        x /= 10;
    }
    while (!res.empty()) cout << res.back(), res.pop_back();
    while (y) {
        res.push_back(y % 10);
        y /= 10;
    }
    while (!res.empty()) cout << res.back(), res.pop_back();
}
int main() {
    #define file "MODULO"
    freopen(file".INP", "r", stdin);  freopen(file".OUT", "w", stdout);
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> b >> n >> k;
    m = (1 << n);
    mu[0] = 1LL;
    for(int i = 1; i <= 21; ++i) mu[i] = (mu[i - 1] * 10) % m;
    int c = n / 2;
    for(int x = 0; x < (1 << c); ++x) {
        ll tmp = 0;
        for(int j = 0; j < c; ++j) {
            if ((x >> j) & 1) {
                tmp = tmp * 10 + 1LL * a;
            }
            else tmp = tmp * 10 + 1LL * b;
        }
        ll du = ((tmp % m) * mu[n - c]) % m;
        f[du].f++;
        f[du].s = tmp;
    }
    for(int x = 0; x < (1 << (n - c)); ++x) {
        ll tmp = 0;
        for(int j = 0; j < (n - c); ++j) {
            if ((x >> j) & 1) {
                tmp = tmp * 10 + 1LL * a;
            }
            else tmp = tmp * 10 + 1LL * b;
        }
        ll du = (k + m - tmp % m) % m;
        if (f[du].f != 0) {
            Inkq(f[du].s, tmp);
            return 0;
        }
    }
    cout << -1;
    return 0;
}
