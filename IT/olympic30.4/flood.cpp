#include <bits/stdc++.h>
using namespace std;
const int maxmn = 1e3 + 7, maxt = 1e6 + 7;
int n, m, k, r[maxmn][maxmn], gm[maxt], gn[maxt], t = 0, ti = 1, ans = 0, dp[maxmn][maxmn] = {{0}};

void dp(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            f[i][j] = min()
        }
    }
}

void enter(){
    char check;
    cin >> n >> m >> k;
    for (int i =  1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> check;
            //if (check == 'H' || check == 'G') r[i][j] = -1;
            if (check == 'S') r[i][j] = 1, gm[++t] = j, gn[t] = i;
            else r[i][j] = 0;
        }
    }
}

void sol(){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("flood.inp", "r", stdin);
    freopen("flood.out", "w", stdout);
    enter();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << r[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= t; i++){
        cout << gm[i] << " " << gn[i] << endl;
    }
    if (k >= m + n - 3) cout << -1;
    else sol();
}