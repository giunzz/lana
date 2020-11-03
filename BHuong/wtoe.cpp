#include <bits/stdc++.h>
using namespace std;
const long long maxmn = 1005, inf = LLONG_MIN;
long long m, n, a[maxmn][maxmn], vt = 1, b[maxmn][maxmn], t[maxmn];

//cach giai can set full cac canh 0 =-oo

void sol(){
    for (int j = 1; j <= n; j++){
        for (int i = 1; i <= m; i++){
            // if (i == 1 && j == 1) continue;
            b[i][j] = max(b[i - 1][j - 1], max(b[i][j - 1], b[i + 1][j - 1]));
            if(b[i][j] == inf) b[i][j] = a[i][j];
            else b[i][j] += a[i][j];
        }
    }
    long long ma = b[1][n];
    for (int i = 2; i <= m; i++){
        if (ma < b[i][n]){
            ma = b[i][n], vt = i;
        }
    }
    cout << ma << endl;
}

void enter(){
    cin >> m >> n;
    for (int i = 0; i <= m; i++) b[i][0] = inf;
    for (int i = 0; i <= n; i++) b[0][i] = inf; 
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

void trace(){
    int j = n, i = vt;
    while (j > 0){
        t[j] = i;
        if (b[i][j] - b[i - 1][j - 1] == a[i][j]) --i;
        else if (b[i][j] - b[i + 1][j - 1] == a[i][j]) ++i;
        --j;
    } 
    long long check = 0;
    for (i = 1; i <= n; i++) {cout << t[i] << " "; check += a[t[i]][i];}
    cerr << check;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("wtoe.INP", "r", stdin);
    freopen("wtoe.OUT", "w", stdout);
    enter();
    sol();
    // trace();
    return 0;
}