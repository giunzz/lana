#include <bits/stdc++.h>

using namespace std;
int a[17], b[17], n, m, ans = 0;

void enter(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
}

void sol(){
    int check;
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    if (a[n] > b[1]){
        return;
    }
    else {
        for (int p = a[n]; p <= b[1]; p++){
            check = 0;
            for (int i = 1; i <= n; i++){
                if (p % a[i] != 0) break;
                else if (i == n) ++check;
            }
            for (int i = 1; i <= m; i++){
                if (b[i] % p != 0) break;
                else if (i == m) ++check;
            }
            if (check == 2) ++ans;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("gettotalx.inp", "r", stdin);
    //freopen("gettotalx.out", "w", stdout);
    enter();
    sol();
    cout << ans;
}