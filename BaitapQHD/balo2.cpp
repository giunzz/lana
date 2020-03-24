#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3;
const int maxm = 5e4;
long int w[maxn], v[maxn], n, m, s[maxn][maxm];

void enter(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 0; i <= m; i++) s[0][i] = 0;
}

long int optimize(){
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            s[i][j] = s[i - 1][j];
            if (w[i] <= j && s[i][j] < s[i - 1][j - w[i]] + v[i])
                s[i][j] = s[i - 1][j - w[i]] + v[i];
        }
    }
    return s[n][m];
}

void trace(){
    //int i =
    //while
}

int main(){
    freopen("balo2.INP", "r", stdin);
    freopen("balo2.OUT", "w", stdout);
    enter();
    cout << optimize() << endl;
    return 0;
}
