#include <bits/stdc++.h>
using namespace std;
int n, a[1007], f[1007][1007] = {{0}}, t[1007], d = 1;

void enter(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void sol(){
    for (int i = 1; i <= n; i++) f[i][i] = 1;
    for (int k = 1; k < n; k++){
        for (int i = 1; i <= n - k; i++){
            int j = i + k;
            if (k == 1) {
                f[i][j] = 1 + (a[i] == a[j]);
                continue;
            }
            f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            if (a[i] == a[j]) f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
        }
    }
}

void trace(){
    int i = 1, j = n;
    while (i <= j){
        if (i == j){
            cout << a[i] << " ";
            ++i, --j;
        }
        else if (a[i] == a[j]){
            t[d] = a[i];
            cout << a[i] << " ";
            ++d, ++i, --j;
        }
        else if (f[i][j] == f[i + 1][j]) ++i;
        else --j;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DAYDX.INP", "r", stdin);
    freopen("DAYDX.OUT", "w", stdout);
    enter();
    sol();
    cout << f[1][n] << "\n";
    trace();
    for (int i = d - 1; i >= 1; i--) cout << t[i] << " ";
    return 0;
}