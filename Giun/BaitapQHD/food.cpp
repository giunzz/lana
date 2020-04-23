#include <bits/stdc++.h>

using namespace std;
int n, m, a[1005][1005], s[1005][1005];

void enter(){
    cin >> m >> n;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++){
            if (i == 0 || j == 0) s[i][j] = 0;
            else
                cin >> a[i][j];
    }
}

void optimize(){
    for (int i = 1; i < m; i++)
        for (int j = 1; j <= n; j++)
            s[i][j] = a[i][j] + max(s[i - 1][j], s[i][j - 1]);
    for (int j = 1; j <= n; j++)
        s[m][j] = a[m][j] + s[m - 1][j];
}

void truyvet(int maxc){
    int i = m, j = maxc;
    cout << a[i][j] << " ";
    while (i != 1 && j != 1){
        if (s[i][j] - a[i][j] == s[i - 1][j]) {
            cout << a[i - 1][j] << " ";
            i = i - 1;
        }
        else {
            cout << a[i][j - 1] << " ";
            j = j - 1;
        }
    }
    cout << a[1][1];
}

int main(){
    freopen("food.INP", "r", stdin);
    freopen("food.OUT", "w", stdout);
    enter();
    optimize();
    int maxn = 0, maxc;
    for (int i = 1; i <= n; i++){
        if (maxn < s[m][i]){
            maxn = s[m][i];
            maxc = i;
        }
    }
    cout << maxn << endl;
    truyvet(maxc);
    return 0;
}
