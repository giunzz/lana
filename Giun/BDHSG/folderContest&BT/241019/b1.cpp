#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("b1.INP", "r", stdin);
    freopen("b1.OUT", "w", stdout);
    int n, ma, maxx, num;
    cin >> n >> num;
    ma = num, maxx = num;
    for (int i = 2; i <= n; i++){
        cin >> num;
        ma = max(num + ma, num);
        if (maxx < ma)  maxx = ma;
    }
    cout << maxx;
    return 0;
}

