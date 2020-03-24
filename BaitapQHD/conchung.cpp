#include <bits/stdc++.h>

using namespace std;
int a[1005], b[1005], m, n, l[1005][1005];

void enter(){
    cin >> m >> n;
    l[0][0] = 0;
    for (int i = 1; i <= m; i++){
        cin >> a[i];
        l[0][i] = 0;
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        l[i][0] = 0;
    }
}

int optimize(){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (a[i] == b[j]) l[j][i] = l[j-1][i-1] + 1;
            else l[j][i] = max(l[j-1][i], l[j][i-1]);
        }
    }
    return l[n][m];
}

void trace(){
    int i = m, j = n;
    while (i != 0 && j != 0){
        if (a[i] != b[j]) {
            if (l[j][i] == l[j - 1][i]) --j;
            else --i;
        }
        else {
            cout << a[i] << " ";
            --i, --j;
        }
    }
}

int main(){
    freopen("conchung.INP", "r", stdin);
    freopen("conchung.OUT", "w", stdout);
    enter();
    cout << optimize() << endl;
    trace();
    return 0;
}
