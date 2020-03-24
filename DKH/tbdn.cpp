#include <bits/stdc++.h>
using namespace std;
const int maxmn = 1005, minv = -1000*1000 - 1;
int m, n, a[maxmn][maxmn], b[maxmn][maxmn] = {{0}};

void entervs(){
    cin >> m >> n;
    //for (int i = 2; i <= n; i++) a[0][i] = minv;
    //for (int i = 2; i <= m; i++) a[i][0] = minv;
    a[0][1] = 0, a[1][0] = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= m; i++){
        b[i][1] = a[i][1] + b[i - 1][1];
    }
    for (int j = 1; j <= n; j++){
        b[1][j] = a[1][j] + b[1][j - 1];
    }
    for (int i = 2; i <= m; i++){
        for (int j = 2; j <= n; j++){
            //cin >> a[i][j];
            b[i][j] = a[i][j] + max(b[i - 1][j], b[i][j - 1]); 
        }
    }
    //for (int i = 0; i <= m; i++){
    //    for (int j = 0; j <= n; j++){
    //        cerr << a[i][j] << " ";
    //    }
    //    cerr << " \n";
    //}
    cout << b[m][n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TBDN.INP", "r", stdin);
    freopen("tbdn.out", "w", stdout);
    entervs();
    return 0;
}