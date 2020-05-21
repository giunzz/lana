#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 5;
int m, n, s[maxn][maxn];

void trace(){
    while (m > 0 && n > 0){
        if ((s[n][m] - 1) == s[n-1][m-1]){
          cout << m <<" "<< n << endl;
          --m, --n;
        }
        else if (s[n][m] == s[n][m - 1]) --m;
        else --n;
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) cout << s[i][j] << " ";
        cout << "\n";
    }
}

void enter(){
    cin >> m >> n;
    int stphn, i, j;
    memset(s, 0, sizeof(s));
    while (cin >> stphn){
        cin >> i;
        for (int p = 1; p <= stphn; p++){
            cin >> j;
            s[j][i] = 1;
        }
    }
}

int optimize(){
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        s[i][j] = max(s[i - 1][j - 1] + s[i][j], max(s[i-1][j], s[i][j-1]));
    }
    return s[n][m];
}

int main(){
    freopen("baccau.INP", "r", stdin);
    freopen("baccau.OUT", "w", stdout);
    enter();
    cout << optimize() << endl;
    trace();
    return 0;
}
