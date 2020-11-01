#include <bits/stdc++.h>

using namespace std;

map<long long, int> vis;
long long a, b, n, mod, k;

void in( long long x, int Mx ) {
    for(int i = 0; i < Mx; ++ i) {
        if( (x >> i) & 1 ) cout << b;
        else cout << a;
    }
}

void sub_1() {
    if( n == 1 ) {
        if( a == 2 || b == 2 ) {
            cout << 2;
        }
        else cout << -1;
        return;
    }
    mod = (1LL << n);
    long long tmp;
    int Le = (n + 1) / 2;
    int Ri = n - Le;
    for(int i = 0; i < (1 << Le ); ++ i) {
        tmp = 0;
        for(int j = 0; j < Le; ++ j) {
            if( (i >> j) & 1 ) tmp = (tmp * 10 + b) % mod;
            else tmp = ( tmp * 10 + a ) % mod;
        }
        vis[tmp] = i + 1;
    }
    for(int i = 0; i < (1 << Ri); ++ i) {
        tmp = 0;
        for(int j = 0; j < Ri; ++ j) {
            if( (i >> j) & 1 ) tmp = (tmp * 10 + b) % mod;
            else tmp = (tmp * 10 + a) % mod;
        }
        for(int j = 0; j < Le; ++ j) tmp = (tmp * 10) % mod;
        if( vis[ ( k + mod - tmp ) % mod ] != 0 ) {
            in( i, Ri ); in( vis[ (k + mod - tmp) % mod ] - 1, Le ); return;
        }
    }
    cout << -1;

}

void sub_2() {
    cout << -1;
}

int main() {
    freopen("Modulo.inp","r",stdin);
    freopen("Modulo.out","w",stdout);
    cin >> a >> b >> n >> k;
    if( k % 2 != a % 2 && k % 2 != b % 2 ) {
        cout << -1; return 0;
    }
    if( n <= 45 ) sub_1();
    else
        sub_2();
    return 0;
}
