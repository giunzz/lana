#include <bits/stdc++.h>

using namespace std;

const int N = 65;

int a, b, n;
unsigned long long mod;
long long k;
map <long long, int> dist[N];
map <long long, pair <int, int> > trace[N];

struct State {
    long long d;
    int len;

    State (long long d = 0, int len = 0): d(d), len(len) {}
};

queue <State> q;

void dotrace (int len, long long d) {
    vector <int> vec;
    while (len > 0) {
        vec.push_back(trace[len][d].second);
        d = trace[len][d].first;
        len--;
    }

    reverse(vec.begin(), vec.end());
    for (auto i: vec) printf("%d", i);
    exit(0);
}

namespace solver1 {
    void solve(){
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) ans = (ans * 10 + a) % mod;
                else ans = (ans * 10 + b) % mod;
            }

            if (ans == k) {
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) printf("%d", a);
                    else printf("%d", b);
                }

                return;
            }
        }
    }
}

int main(){
    #ifndef Futymy
        freopen("MODULO.inp", "r", stdin);
        freopen("MODULO.out", "w", stdout);
    #endif // Futymy

    scanf("%d %d", &a, &b);
    scanf("%d %lld", &n, &k);
    mod = 1ULL << n;

    if (n <= 20) {
        solver1::solve();
        return 0;
    }

    /*dist[0][0] = 0; q.push(State(0, 0));
    int cnt = 0;
    while (!q.empty()) {
        cnt++;
        long long d = q.front().d;
        int len = q.front().len;
        //cout << d << " " << s << " " << len << "\n";
        q.pop();
        if (len > n) continue;

        if (d == k && len == n) dotrace(len, d);
        if (cnt >= 10000000) return !printf("%d", -1);
        if (len == n) continue;
        if (!dist[len + 1].count((d * 10 + a) % mod) || dist[len + 1][(d * 10 + a) % mod] > dist[len][d] + 1) {
            dist[len + 1][(d * 10 + a) % mod] = dist[len][d] + 1;
            q.push(State((d * 10 + a) % mod, len + 1));
            trace[len + 1][(d * 10 + a) % mod] = {d, a};
        }

        if (!dist[len + 1].count((d * 10 + b) % mod) || dist[len + 1][(d * 10 + b) % mod] > dist[len][d] + 1) {
            dist[len + 1][(d * 10 + b) % mod] = dist[len][d] + 1;
            q.push(State((d * 10 + b) % mod, len + 1));
            trace[len + 1][(d * 10 + b) % mod] = {d, b};
        }
    }*/

    printf("%d", -1);
    return 0;
}
