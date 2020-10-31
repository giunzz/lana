#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<= b; ++i)
#define FORD(i, a, b) for (int i = a; i>=b; --i)
#define REP(i, a) for (int i = 0; i<a; ++i)
#define N 1001000
#define pp pair<int, int>
#define bit(S, i) (((S) >> i) & 1)
#define IO cin.tie(NULL);cout.tie(NULL);
#define taskname "MINSUM"
using namespace std;

map<int, int> cnt;
map<int, int> :: iterator it;
void cal(int a) {
    int A = a;
    FOR(i, 2, sqrt(A)) if (A % i == 0) {
        while (A % i == 0) {
            A/=i;
            cnt[i]++;
        }
    }
    if (A > 1) cnt[A]++;
}
int a, b;
vector<int> e;
void solve() {
    scanf("%d %d", &a, &b);
    e.clear();
    cnt.clear();
    cal(a);cal(b);
    long long all = 1;
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        if (it -> second % 2) {
            e.push_back(it -> first);
            all = all * it -> first;
        }
    }
    long long ans = 1e18 + 5, resx, resy;
    REP(S, 1 << (int)e.size()) {
        long long x = 1, y = all;
        REP(i, (int)e.size()) if(bit(S, i)) {
            x = x * e[i];
            y = y / e[i];
        }
        if(ans > x + y) {
            resx = x;
            resy = y;
            ans = x + y;
        }
    }
    printf("%lld %lld\n", resx, resy);
}
int main() {
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    IO;
    int test;
    scanf("%d", &test);
    while (test--) solve();
}
