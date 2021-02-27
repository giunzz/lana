#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 7;
int t, a[maxn], n, x, ans[5] = {0};

void enter(){
    cin >> n;
    x = n / 4;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= 3; i++){
        if (a[i * x] != a[i * x + 1]) ans[i] = a[i * x + 1];
        else {
            cout << -1 << "\n";
            return;
        }
    }
    cout << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("RANDOM.INP", "r", stdin);
    freopen("RANDOM.OUT", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++){
        enter();
        ans[1] = 0, ans[2] = 0, ans[3] = 0;
    }
}