#include <bits/stdc++.h>

using namespace std;

const int md = 310;

int n, m, k;
long long a[md][md], f[md][md], f1[md][md], b[md], l[md], r[md];

int main() {
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    while (k--) {
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        long long res = 1e15;
        for(int ii = u; ii <= p; ii++) 
            for(int jj = v; jj <= q; jj++) {
                if ((ii == u && jj == v) || (ii == p && jj == q)) continue;
                    for(int i = u - 1; i <= p; i++)
                        for(int j = v - 1; j <= q; j++)
                            f[i][j] = 0;
                    for(int i = u; i <= p; i++)
                        for(int j = v; j <= q; j++) {
                            if (i == ii && j == jj) f[i][j] = 0;
                            else {
                                if (i - 1 != ii || j != jj)
                                    f[i][j] = max(f[i][j], f[i - 1][j] + a[i][j]);
                                if (j - 1 != jj || i != ii)
                                    f[i][j] = max(f[i][j], f[i][j - 1] + a[i][j]);
                                /*if (ii == 3  && jj == 3) {
                                    cout << i <<" " << j <<" " << f[i - 1][j] + a[i][j] <<" " << f[i][j - 1] + a[i][j] << " " << f[i][j] << endl;
                                }*/
                            }
                        }
                    /*if (ii == 2 && jj == 3) {
                        for(int i = u; i <= p; i++) {
                            for(int j = v; j <= q; j++)
                                cout << f[i][j] <<" ";
                            cout << endl;
                        }
                    }*/
                    res = min(res, f[p][q]);
            }
        //cout << f[3][3][1] << endl;
        cout << res << '\n';
    }
    return 0;
}