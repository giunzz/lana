#include <bits/stdc++.h>
#define f0(i, n) for(int i(0); i < (n); i++)
#define f1(i, n) for(int i(1); i <= n; i++)

using namespace std;
typedef long long ll;
const int N = 302;

ll a[N][N], b[N][N], dp1[N][N], dp2[N][N], f1[N][N], f2[N][N], d1[N][N], d2[N][N];

void init(int m, int n){
    f1(i, m) f1(j, n) dp1[i][j] = dp2[i][j] = f1[i][j] = f2[i][j] = LLONG_MIN;
    dp1[1][1] = b[1][1];
    dp2[m][n] = b[m][n];
    f1(i, m){
        f1(j, n){
            if(i - 1 > 0){
                dp1[i][j] = max(dp1[i][j], dp1[i - 1][j] + b[i][j]);
            }
            if(j - 1 > 0){
                dp1[i][j] = max(dp1[i][j], dp1[i][j - 1] + b[i][j]);
            }
        }
    }
    for(int i = m; i >= 1; i--){
        for(int j = n; j >= 1; j--){
            if(i + 1 <= m){
                dp2[i][j] = max(dp2[i][j], dp2[i + 1][j] + b[i][j]);
            }
            if(j + 1 <= n){
                dp2[i][j] = max(dp2[i][j], dp2[i][j + 1] + b[i][j]);
            }
        }
    }
    f1(i, m){
        f1(j, n){
            if(j >= 2){
                f2[i][j] = dp1[i][j - 1] + dp2[i][j];
            }
        }
    }
    f1(i, m){
        f1(j, n){
            if(j + 1 <= n){
                f1[i][j] = dp1[i][j] + dp2[i][j + 1];
            }
        }
    }
    f1(j, n){
        f1(i, m){
            if(i==1) d1[j][i] = f1[i][j];
            else{
                d1[j][i] = max(d1[j][i - 1], f1[i][j]);
            }
        }
    }
    f1(j, n){
        for(int i = m; i >= 1; i--){
            if(i==m) d2[j][i] = f2[i][j];
            else{
                d2[j][i] = max(d2[j][i + 1], f2[i][j]);
            }
        }
    }
}

ll calc1(int i, int j){
    return d1[j][i];
}

ll calc2(int i, int j){
    return d2[j][i];
}

ll solve(int x1, int y1, int x2, int y2){
    int m = x2 - x1 + 1;
    int n = y2 - y1 + 1;
    for(int x = x1; x <= x2; x++){
        for(int y = y1; y <= y2; y++){
            b[x - x1 + 1][y - y1 + 1] = a[x][y];
        }
    }
    init(m, n);
    ll res = LLONG_MAX;
    f1(i, m){
        f1(j, n){
            ll ans = LLONG_MIN;
            if(i==1 && j==1){
                continue;
            }
            if(i==m && j==n){
                continue;
            }
            if(i >= 2){
                if(j + 1 <= n){
                    ans = max(ans, calc1(i - 1, j));
                }
            }
            if(i + 1 <= m){
                if(j >= 2){
                    ans = max(ans, calc2(i + 1, j));
                }
            }
            res = min(res, ans);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    freopen("TABLE.inp", "r", stdin);
    freopen("TABLE.out", "w", stdout);

    int m, n, q;
    cin >> m >> n >> q;
    f1(i, m) f1(j, n) cin >> a[i][j];

    while(q--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ll res = LLONG_MAX;
        res = min(res, solve(x1, y1, x2, y2));
        cout << res << "\n";
    }
}

