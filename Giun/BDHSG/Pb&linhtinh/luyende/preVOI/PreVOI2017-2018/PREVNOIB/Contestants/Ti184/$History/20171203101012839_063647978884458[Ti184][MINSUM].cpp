#include<bits/stdc++.h>
const int N = 1e6 + 5;
const long long inf = 1e18;
using namespace std;

ifstream fi ("MINSUM.inp");
ofstream fo ("MINSUM.out");

int n, a, b, t;
long long f[N], ans;

void solve(){
    fi >> a >> b; long long c = a * b; n = 0;
    for (int i = 2; 1LL * i * i <= c; i++){
        int cnt = 0;
        while (c % i == 0){
            c /= i; cnt++;
        }
        if (cnt % 2 == 1) f[(1 << n)] = i, n++;
    }
    if (c > 0) f[(1 << n)] = c, n++;
    f[0] = 1;
    for (int i = 1; i < (1 << n); i++){
        if (i&(i-1) == 0) continue;
        f[i] = f[i-(i&(-i))] * f[(i&(-i))];
    }
    ans = inf;
    for (int i = 0; i < (1 << n); i++) {
        if (ans > f[i] + f[(1 << n) - 1 - i]) {
            ans = f[i] + f[(1 << n) - 1 - i];
            a = f[i], b = ans - a;
        }
    }
    if (a > b) swap(a, b);
    fo << a << " " << b << "\n";
}

int main(){
    fi >> t;
    while (t--) solve();
}
