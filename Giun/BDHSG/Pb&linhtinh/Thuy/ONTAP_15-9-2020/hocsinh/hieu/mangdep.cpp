#include <bits/stdc++.h>
using namespace std;
int n, a;
queue<int> v4, v8, v15, v16, v23, v42;
int main() {
    freopen("mangdep.inp", "r", stdin);
    freopen("mangdep.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == 4) v4.push(i);
        if (a == 8) v8.push(i);
        if (a == 15) v15.push(i);
        if (a == 16) v16.push(i);
        if (a == 23) v23.push(i);
        if (a == 42) v42.push(i);
    }
    int res = 0;
    while (true) {
            if (v4.empty() || v8.empty() || v15.empty() || v16.empty() || v23.empty() || v42.empty()) break;
            int x = v4.front();
            v4.pop();
            bool ok = false;
            while (v8.size()) {
                if (v8.front() > x) {
                    ok = true;
                    break;
                } else {
                    v8.pop();
                }
            }
            if (!ok) break;
            x = v8.front();
            v8.pop();
            ok = false;
            while (v15.size()) {
                if (v15.front() > x) {
                    ok = true;
                    break;
                } else {
                    v15.pop();
                }
            }
            if (!ok) break;
            x = v15.front();
            v15.pop();
            ok = false;
            while (v16.size()) {
                if (v16.front() > x) {
                    ok = true;
                    break;
                } else {
                    v16.pop();
                }
            }
            if (!ok) break;
            x = v16.front();
            v16.pop();
            ok = false;
            while (v23.size()) {
                if (v23.front() > x) {
                    ok = true;
                    break;
                } else {
                    v23.pop();
                }
            }
            if (!ok) break;
            x = v23.front();
            v23.pop();
            ok = false;
            while (v42.size()) {
                if (v42.front() > x) {
                    ok = true;
                    break;
                } else {
                    v42.pop();
                }
            }
            if (!ok) break;
            x = v42.front();
            v42.pop();
            res += 6;
    }
    cout << n - res;
    return 0;
}
