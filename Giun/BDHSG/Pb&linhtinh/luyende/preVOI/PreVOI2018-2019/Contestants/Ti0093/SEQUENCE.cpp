#define taskname "SEQUENCE"
#include <bits/stdc++.h>

using namespace std;

const int maxn = 6666;

stack <int> s;
vector <int> smallest;
int n, k, d, t, m;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    cin >> m >> d >> t;
    n = m + d;
    k = n - t;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (s.empty()) s.push(a);
        else {
            while (!s.empty() && a < s.top() && k > 0) {
                s.pop();
                --k;
            }
            s.push(a);
        }
    }
    while (k > 0 && !s.empty()) {
        s.pop();
        --k;
    }
    while (!s.empty()) {
        smallest.emplace_back(s.top());
        s.pop();
    }
    for (int i = smallest.size() - 1; i >= 0; --i) cout << smallest[i] << ' ';
}
