#include <bits/stdc++.h>
using namespace std;
const int maxa = 1e5 + 7;
int t, n;
long long sum, a[maxa], ucln, l, b, c;

void enter(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
}

void sol(){
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        sum += 2*(2 * i - 1- n)*a[i];
    }
    l = sum;
    b = n;
    while (l*b!= 0){
        if (l > b) l %= b;
        else b %= l;
    }
    cout << sum/(l + b) << " " << n/(l + b) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Test01-20200114T075042Z-001\\Test01\\SPC2.INP", "r", stdin);
    freopen("spc2.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++){
        sum = 0;
        enter();
        sol();
    }
    cerr << clock() << " ms";
}
