#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int x, y; cin >> x >> y;
    int curx = x, cury = y;
    vector<int> vec;
    for (int i = 2; i <= max(sqrt(x), sqrt(y)); ++i) {
        while (curx % i == 0) vec.push_back(i), curx /= i;
        while (cury % i == 0) vec.push_back(i), cury /= i;
    }
    if (curx > cury) swap(curx, cury);
    if (curx > 1) vec.push_back(curx);
    if (cury > 1) vec.push_back(cury);
    vector<int> vec2;
    for (int i = 0; i < vec.size(); ++i) {
        int cur = i, cnt = 0;
        while (i < vec.size() && vec[i] == vec[cur]) i++, cnt++;
        i--; if (cnt & 1) vec2.push_back(vec[i]);
    }
    int sz = vec2.size();
    int resx = 0, resy = 0, res = INF * 2;
    for (int i = 0; i < (1 << sz); ++i) {
        int valx = 1, valy = 1;
        for (int j = 0; j < sz; ++j) {
            if (i >> j & 1) valx = min(1LL * INF, 1LL * valx * vec2[j]);
            else valy = min(1LL * INF, 1LL * valy * vec2[j]);
        }
        if (res > valx + valy) {
            res = valx + valy, resx = valx, resy = valy;
        }
    }
    if (resx > resy) swap(resx, resy);
    cout << resx << ' ' << resy << '\n';
}

int main() {
    freopen("minsum.inp", "r", stdin);
    freopen("minsum.out", "w", stdout);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
}
