#include <bits/stdc++.h>
using namespace std;
int n, k, b[300009];
pair<int, int> a[300009];
int main() {
    freopen("vanchuyen.inp", "r", stdin);
    freopen("vanchuyen.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= k; i++) cin >> b[i];
    sort (b + 1, b + k + 1);
    priority_queue<int> pq;
    long long res = 0;
    int pos = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = pos; j <= n; j++) {
            if (a[j].first <= b[i]) {
                pq.push(a[j].second);
                pos = j + 1;
            } else {
                break;
            }
        }
        if (pq.size()) {
            res += pq.top();
            pq.pop();
        }
    }
    cout << res;
    return 0;
}
