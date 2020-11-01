#include <bits/stdc++.h>
#define int long long

using namespace std;

int m, n, k, res;
int era[2010];
struct data {
    int X, Y, Z, T;
} a[2010], b[20];

bool check(int x, int y, int z) {
    int l = a[z].X - a[z].T;
    int r = a[z].X + a[z].T;
    if (l <= b[x].X && b[x].X <= r && l <= b[y].X && b[y].X <= r) return 1;
    if (b[x].X < l && b[y].X < l) return 1;
    if (b[x].X > r && b[y].X > r) return 1;
    return 0;
}

main() {
    freopen("teaworld.inp", "r", stdin);
    freopen("teaworld.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) cin >> a[i].X >> a[i].Y >> a[i].Z >> a[i].T;
    for (int i = 1; i <= n; ++i) cin >> b[i].X >> b[i].Y >> b[i].Z >> b[i].T;
    cin >> b[0].X >> b[0].Y >> b[0].Z;
    for (int i = 0; i < (1 << n); ++i) {
        memset(era, 0, sizeof(era));
        int cur = 0, cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (i & (1 << (j - 1))) {
                cur += b[j].T;
                for (int l = 1; l <= m; ++l) {
                    if (era[l]) continue;
                    if (!check(0, j, l)) {
                        era[l] = 1;
                        ++cnt;
                    }
                }
            }
        }
        if (cnt <= k) res = max(res, cur);
    }
    cout << res;
}
