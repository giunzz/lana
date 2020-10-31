#include <bits/stdc++.h>

using namespace std;

const int N = 305;
const int lim = 3e7;

int m, n, x, a[N][N], u[N], v[N], p[N], q[N];
long long dp[N][N], dp2[N][N];
unsigned long long f[N][N], f2[N][N];

namespace solver1 {
    void solve(){
        for (int i = 1; i <= x; i++) {
            long long ans = 1e18;
            for (int j = u[i]; j <= p[i]; j++) {
                for (int k = v[i]; k <= q[i]; k++) {
                    if (j == u[i] && k == v[i]) continue;
                    if (j == p[i] && k == q[i]) continue;
                    for (int l = u[i]; l <= p[i]; l++) for (int cnt = v[i]; cnt <= q[i]; cnt++) dp[l][cnt] = -1e18;

                    dp[u[i]][v[i]] = a[u[i]][v[i]];
                    for (int l = u[i]; l <= p[i]; l++) {
                        for (int cnt = v[i]; cnt <= q[i]; cnt++) {
                            if (l == j && cnt == k) continue;
                            dp[l + 1][cnt] = max(dp[l + 1][cnt], dp[l][cnt] + a[l + 1][cnt]);
                            dp[l][cnt + 1] = max(dp[l][cnt + 1], dp[l][cnt] + a[l][cnt + 1]);
                        }
                    }

                    ans = min(ans, dp[p[i]][q[i]]);
                }
            }

            printf("%lld\n", ans);
        }
    }
}

namespace solver2 {
    void solve(){
        for (int i = 1; i <= x; i++) {
            for (int j = u[i]; j <= p[i]; j++) for (int k = v[i]; k <= q[i]; k++) dp2[j][k] = -1e18, f2[j][k] = 0;
            dp2[p[i]][q[i]] = a[p[i]][q[i]]; f2[p[i]][q[i]] = 1;
            for (int j = p[i]; j >= u[i]; j--) {
                for (int k = q[i]; k >= v[i]; k--) {
                    if (dp2[j - 1][k] > dp2[j][k] + a[j - 1][k]) {
                        dp2[j - 1][k] = dp2[j][k] + a[j - 1][k];
                        f2[j - 1][k] = f2[j][k];
                    }
                    else if (dp2[j - 1][k] == dp2[j][k] + a[j - 1][k]) f2[j - 1][k] += f2[j][k];

                    if (dp2[j][k - 1] > dp2[j][k] + a[j][k - 1]) {
                        dp2[j][k - 1] = dp2[j][k] + a[j][k - 1];
                        f2[j][k - 1] = f2[j][k];
                    }
                    else if (dp2[j][k - 1] == dp2[j][k] + a[j][k - 1]) f2[j][k - 1] += f2[j][k];
                }
            }

            for (int j = u[i]; j <= p[i]; j++) for (int k = v[i]; k <= q[i]; k++) dp[j][k] = -1e18, f[j][k] = 0;
            dp[u[i]][v[i]] = a[u[i]][v[i]]; f[u[i]][v[i]] = 1;
            for (int j = u[i]; j <= p[i]; j++) {
                for (int k = v[i]; k <= q[i]; k++) {
                    if (dp[j + 1][k] > dp[j][k] + a[j + 1][k]) {
                        dp[j + 1][k] = dp[j][k] + a[j + 1][k];
                        f[j + 1][k] = f[j][k];
                    }
                    else if (dp[j + 1][k] == dp[j][k] + a[j + 1][k]) f[j + 1][k] += f[j][k];

                    if (dp[j][k + 1] > dp[j][k] + a[j][k + 1]) {
                        dp[j][k + 1] = dp[j][k] + a[j][k + 1];
                        f[j][k + 1] = f[j][k];
                    }
                    else if (dp[j][k + 1] == dp[j][k] + a[j][k + 1]) f[j][k + 1] += f[j][k];
                }
            }

            unsigned long long ways = f[p[i]][q[i]];
            /*int ans = 0, posx = 0, posy = 0;
            for (int j = u[i]; j <= p[i]; j++) {
                for (int k = v[i]; k <= q[i]; k++) {
                    if (j == u[i] && k == v[i]) continue;
                    if (j == p[i] && k == q[i]) continue;

                    if (j + 1 <= p[i]) {
                        if (f[j][k] * f2[j + 1][k] == ways) {
                            if (a[j][k] > ans) {
                                ans = a[j][k];
                                posx = j;
                                posy = k;
                            }

                            if (a[j + 1][k] > ans) {
                                ans = a[j + 1][k];
                                posx = j + 1;
                                posy = k;
                            }
                        }
                    }

                    if (k + 1 <= q[i]) {
                        if (f[j][k] * f2[j][k + 1] == ways) {
                            if (a[j][k] > ans) {
                                ans = a[j][k];
                                posx = j;
                                posy = k;
                            }

                            if (a[j][k + 1] > ans) {
                                ans = a[j][k + 1];
                                posx = j;
                                posy = k + 1;
                            }
                        }
                    }
                }
            }*/

            vector <pair <int, int> > vec;
            for (int j = u[i]; j <= p[i]; j++) {
                for (int k = v[i]; k <= q[i]; k++) {
                    if (j == u[i] && k == v[i]) continue;
                    if (j == p[i] && k == q[i]) continue;

                    if (j + 1 <= p[i]) {
                        if (f[j][k] * f2[j + 1][k] == ways) {
                            vec.push_back({j, k});
                            vec.push_back({j + 1, k});
                        }
                    }

                    if (k + 1 <= q[i]) {
                        if (f[j][k] * f2[j][k + 1] == ways) {
                            vec.push_back({j, k});
                            vec.push_back({j, k + 1});
                        }
                    }
                }
            }

            sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
            long long res = 1e18;
            for (auto data: vec) {
                int posx = data.first, posy = data.second;

                for (int j = u[i]; j <= p[i]; j++) for (int k = v[i]; k <= q[i]; k++) dp[j][k] = -1e18;
                dp[u[i]][v[i]] = a[u[i]][v[i]];
                for (int j = u[i]; j <= p[i]; j++) {
                    for (int k = v[i]; k <= q[i]; k++) {
                        if (j == posx && k == posy) continue;
                        dp[j + 1][k] = max(dp[j + 1][k], dp[j][k] + a[j + 1][k]);
                        dp[j][k + 1] = max(dp[j][k + 1], dp[j][k] + a[j][k + 1]);
                    }
                }

                res = min(res, dp[p[i]][q[i]]);
            }

            printf("%lld\n", res);
        }
    }
}

int main(){
    #ifndef Futymy
        freopen("TABLE.inp", "r", stdin);
        freopen("TABLE.out", "w", stdout);
    #endif // Futymy
    scanf("%d %d %d", &m, &n, &x);
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= x; i++) scanf("%d %d %d %d", &u[i], &v[i], &p[i], &q[i]);
    //solver1::solve();
    //cout << "\n";
    solver2::solve();
    return 0;
}
/*
4 3 1
1 6 9
2 1 9
5 6 1
7 6 6
1 1 4 3
*/
