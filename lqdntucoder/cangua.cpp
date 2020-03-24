#include <bits/stdc++.h>
using namespace std;
pair <int, int> a[100007];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    char c;
    int n, u = 0; cin >> n;
    vector<int> bx(n + 1, INT_MAX), by(n + 1, INT_MAX);
    int result = 0;
    for (int x = 0; x < n; x++){
        cin >> c;
        if (x == 0 && c == 'Q'){
            cout << 0;
            continue;
        }
        if (c == 'A') {
            cin >> a[u].first >> a[u++].second;
            int k = lower_bound(bx.begin(), bx.end(), a[u - 1].first) - bx.begin();
            if (by[k] > a[u - 1].second){
                bx[k] = a[u - 1].first, by[k] = a[u - 1].second;
                result = max(result, k);
            }
        }
        else cout << result << "\n";
    }
    return 0;
}