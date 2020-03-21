#include <bits/stdc++.h>
using namespace std;
int n, ucln, t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DELGCD.INP", "r", stdin);
    freopen("DELGCD.OUT", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> ucln;
    for (int i = 1; i < n; i++){
        cin >> t;
        ucln = __gcd(ucln, t);
    }
    if (ucln == 1) cout << 0;
    else cout << -1;
}