#include <bits/stdc++.h>

using namespace std;

const int N = 4005;

int n, d, a[N], b[N], dp[N][N];
pair <int, int> trace[N][N];

namespace solver1 {
    void solve() {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (a[i] == b[j]) dp[i][j] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i] != b[j]) continue;
                for (int k = 1; k < i; k++) {
                    for (int l = 1; l < j; l++) {
                        if (a[k] != b[l]) continue;
                        if (abs(a[i] - a[k]) > d) continue;
                        if (dp[k][l] + 1 > dp[i][j]) {
                            dp[i][j] = dp[k][l] + 1;
                            trace[i][j] = {k, l};
                        }
                        else if (dp[k][l] + 1 == dp[i][j] && a[k] > trace[i][j].first) trace[i][j] = {k, l};
                    }
                }
            }
        }

        int ans = 0, pos1 = 0, pos2 = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i] == b[j]) {
                    if (dp[i][j] > ans) {
                        ans = dp[i][j];
                        pos1 = i;
                        pos2 = j;
                    }
                }
            }
        }

        printf("%d\n", ans);
        vector <int> vec;
        while (pos1 && pos2) {
            vec.push_back(a[pos1]);
            int npos1 = trace[pos1][pos2].first, npos2 = trace[pos1][pos2].second;
            pos1 = npos1;
            pos2 = npos2;
        }

        for (auto i: vec) printf("%d ", i);
    }
}

namespace solver2 {
    void solve(){
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) trace[i][j] = {-1, -1};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i] == b[j]) {
                    if (dp[i][j] < dp[i - 1][j - 1] + 1) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        trace[i][j] = {i - 1, j - 1};
                    }
                }
                else {
                    if (dp[i - 1][j] > dp[i][j]) {
                        dp[i][j] = dp[i - 1][j];
                        trace[i][j] = {i - 1, j};
                    }
                    if (dp[i][j - 1] > dp[i][j]) {
                        dp[i][j] = dp[i][j - 1];
                        trace[i][j] = {i, j - 1};
                    }
                }
            }
        }

        vector <int> vec;
        int pos1 = n, pos2 = n;
        while (pos1 && pos2) {
            int npos1 = trace[pos1][pos2].first, npos2 = trace[pos1][pos2].second;
            if (npos1 == -1 && npos2 == -1) break;
            if (npos1 != pos1 && npos2 != pos2) vec.push_back(a[pos1]);
            pos1 = npos1; pos2 = npos2;
            //cout << pos1 << " " << pos2 << "\n";
        }

        /*for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }*/

        //cout << "\n";
        //for (auto i: vec) cout << i << " ";
        //cout << "\n";
        int ans = 1, last = 0, res = 0, fi = 0;
        for (int i = 1; i < vec.size(); i++) {
            if (abs(vec[i] - vec[i - 1]) <= d) ans++;
            else {
                if (res < ans) {
                    res = ans;
                    last = i - 1;
                    fi = last - ans + 1;
                }
                ans = 1;
            }
        }

        if (ans > res) {
            res = ans;
            last = (int)vec.size() - 1;
            fi = last - ans + 1;
        }

        printf("%d\n", res);
        for (int i = fi; i <= last; i++) printf("%d ", vec[i]);
    }
}

int main(){
    #ifndef Futymy
        freopen("LIONDANCE.inp", "r", stdin);
        freopen("LIONDANCE.out", "w", stdout);
    #endif // Futymy
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    reverse(a + 1, a + n + 1); reverse(b + 1, b + n + 1);
    if (n <= 100) solver1::solve();
    else solver2::solve();
    return 0;
}

/*
8 3
2 1 2 3 9 4 5 7
2 3 2 1 7 4 5 9
*/
