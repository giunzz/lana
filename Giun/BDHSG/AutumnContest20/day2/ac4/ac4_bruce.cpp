#include <bits/stdc++.h>
using namespace std;
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".").c_str(), "w", stdout);
#define ll long long
const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e2 + 7;
int query, n, k, key[N];
bool cmp(int a, int b) {
    return (a > b);
}
main() {
    fileInput("ac5");
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> key[i];
        }
        sort(key + 1, key + 1 + n, cmp);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (key[i] == 1) continue;
            while (k % key[i] == 0) {
                cnt++;
                k /= key[i];
            }
        }
        if (k == 1) cout << cnt << endl;
        else cout << "Impossible\n";
    }
}