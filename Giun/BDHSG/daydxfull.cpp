#include <bits/stdc++.h>
using namespace std;
int n, a[1007], f[1007][1007] = {{0}}, t[1007], d = 1;//, p, q; //f la do dai xau con tu i -> j

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

/*void tv(int i, int j){
    //static int i = 1, j = n;
    //p = 1, q = n;
    if (i == j) {
        cout << a[i] << " ";
        return;
    }
    if (a[i] == a[j]) {
        cout << a[i] << " ";
        tv(i + 1, j - 1);
        cout << a[j] << " "; 
        return;
    }
    if (f[i][j] == f[i + 1][j]) {
        tv(i + 1, j);
    }
    else tv(i, j - 1);
}*/

void trace(){
    int i = 1, j = n;//, d = 1;
    while (i <= j){
        if (i == j){
            //t[d] = a[i];
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
    freopen("f.INP", "r", stdin);
    freopen("f.OUT", "w", stdout);
    enter();
    sol();
    cout << f[1][n] << "\n";
    //cerr << 1 << endl;
    //tv(1, n);
    //cerr << 1 << endl;
    //for (int i = p; i <= q; i++) cout << a[i] << " ";
    trace();
    //cerr << d;
    //cout << endl;
    for (int i = d - 1; i >= 1; i--) cout << t[i] << " ";
    return 0;
}