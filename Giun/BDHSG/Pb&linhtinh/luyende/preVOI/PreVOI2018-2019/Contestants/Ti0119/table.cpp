#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int mod = 1e9 + 7;
//Ti0119
const int N = 305;

int n, m, k, a[N][N];

long long dp[N][N], prefrow[N][N], prefcol[N][N], lmao[N][N];

const long long inf = 1e15;

int main() {
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    }
    for(int l = 1; l <= k; l++) {
        long long mn = inf;
        int u, v, p, q;
        scanf("%d%d%d%d", &u, &v, &p, &q);
        for(int i = p; i >= u; i--) {
            for(int j = q; j >= v; j--) {
                lmao[i][j] = -inf;
                dp[i][j] = -inf;
                prefrow[i][j] = -inf;
                prefcol[i][j] = -inf;
            }
        }
        lmao[p][q] = a[p][q];
        dp[u][v] = a[u][v];
        for(int i = u; i <= p; i++) {
            for(int j = v; j <= q; j++) {
                if(j < q)
                    dp[i][j + 1] = max(dp[i][j] + a[i][j + 1], dp[i][j + 1]);
                if(i < p)
                    dp[i + 1][j] = max(dp[i][j] + a[i + 1][j], dp[i + 1][j]);
            }
        }
        for(int i = p; i >= u; i--) {
            for(int j = q; j >= v; j--) {
                if(j - 1 >= v)
                    lmao[i][j - 1] = max(lmao[i][j] + a[i][j - 1], lmao[i][j - 1]);
                if(i - 1 >= u)
                    lmao[i - 1][j] = max(lmao[i][j] + a[i - 1][j], lmao[i - 1][j]);
            }
        }
        for(int i = u; i <= p; i++) {
            for(int j = v; j <= q; j++) {
                prefrow[i][j] = dp[i][j] + lmao[i][j] - a[i][j];
                prefcol[i][j] = dp[i][j] + lmao[i][j] - a[i][j];
            }
        }
        for(int j = q; j >= v; j--) {
            for(int i = p - 1; i >= u; i--)
                prefcol[i][j] = max(prefcol[i + 1][j], prefcol[i][j]);
        }
        for(int i = u; i <= p; i++) {
            for(int j = q - 1; j >= v; j--)
                prefrow[i][j] = max(prefrow[i][j + 1], prefrow[i][j]);
        }
        for(int i = u; i <= p; i++) {
            for(int j = v; j <= q; j++) {
                if(i == u && j == v) continue;
                if(i == p && j == q) continue;
                long long mx = -inf;
                if(i - 1 >= u && j + 1 <= q)
                    mx = max(mx, prefrow[i - 1][j + 1]);
                if(i + 1 <= p && j - 1 >= v)
                    mx = max(mx, prefcol[i + 1][j - 1]);
                mn = min(mn, mx);
            }
        }
        printf("%lld\n", mn);
    }
}
