#include <bits/stdc++.h>

using namespace std;
int d[11] = {0}, n, l = 0, k = 0;

void sol(int v){
    for (int i = 0; i <= 9; i++){
        if (v == 1 && i == 0) continue;
        if(d[i]){
            k = k * 10 + i;
            --d[i];
            if (v == l) cout << k << endl;
            else sol(v + 1);
            ++d[i];
            k = k / 10;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bai41ql.inp", "r", stdin);
    freopen("bai41ql.out", "w", stdout);
    cin >> n;
    while (n){
        ++d[n % 10], ++l, n /= 10;
    }
    sol(1);
}