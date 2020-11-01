#include <bits/stdc++.h>

using namespace std;

const int N = 305;
const int mod = 1e9 + 9;
const int lim = 1e7;
const int maxn = 10000 * 350 + 1;

vector <vector <vector <vector <int> > > > dp;
vector <int> f, f1;
int n, mmax, m50, m1, m2;

int binPow (int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = (1LL * ans * x) % mod;
        x = (1LL * x * x) % mod;
        y >>= 1;
    }

    return ans;
}

void add (int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

namespace solver1 {
    void solve(){
        dp.assign(n + 1, vector <vector <vector <int> > >(mmax + 1, vector <vector <int> >(mmax + 1, vector <int>(mmax + 1, 0))));
        dp[0][m50][m1][m2] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= mmax; j++) {
                for (int k = 0; k <= mmax; k++) {
                    for (int l = 0; l <= mmax; l++) {
                        if (dp[i][j][k][l]) {
                            if (j < mmax) add(dp[i + 1][j + 1][k][l], dp[i][j][k][l]);
                            if (j && k < mmax) add(dp[i + 1][j - 1][k + 1][l], dp[i][j][k][l]);
                            if (j && k && l < mmax) add(dp[i + 1][j - 1][k - 1][l + 1], dp[i][j][k][l]);
                            else if (j >= 3 && l < mmax) add(dp[i + 1][j - 3][k][l + 1], dp[i][j][k][l]);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= mmax; i++) for (int j = 0; j <= mmax; j++) for (int k = 0; k <= mmax; k++) add(ans, dp[n][i][j][k]);
        printf("%d", ans);
    }
}

namespace solver2 {
    int ans = 0;
    void bt (int pos, int m50, int m1, int m2) {
        if (pos == n + 1) {
            ans++;
            return;
        }

        if (m50 + 1 <= mmax) bt(pos + 1, m50 + 1, m1, m2);
        if (m50 >= 1 && m1 + 1 <= mmax) bt(pos + 1, m50 - 1, m1 + 1, m2);
        if (m50 >= 1 && m1 >= 1 && m2 + 1 <= mmax) bt(pos + 1, m50 - 1, m1 - 1, m2 + 1);
        else if (m50 >= 3 && m2 + 1 <= mmax) bt(pos + 1, m50 - 3, m1, m2 + 1);
    }

    void solve(){
        bt(1, m50, m1, m2);
        printf("%d", ans);
    }
}

int main(){
    #ifndef Futymy
        freopen("ICECREAM.inp", "r", stdin);
        freopen("ICECREAM.out", "w", stdout);
    #endif // Futymy
    scanf("%d %d", &n, &mmax);
    scanf("%d %d %d", &m50, &m1, &m2);
    if (1LL * n * mmax * mmax * mmax <= lim) solver1::solve();
    else if (n <= 16) solver2::solve();
    else printf("%d", binPow(3, n));
    return 0;
}
