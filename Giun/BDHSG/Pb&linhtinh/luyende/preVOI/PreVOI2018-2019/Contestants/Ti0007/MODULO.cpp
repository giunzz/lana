#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
#define f first
#define s second
#define mk make_pair

const int N = 1e2 + 7;
int n, t, res, T, k;
ull A, B, mod, ten[N], m;
map<ull, int> sav;

void built() {
    mod = (1<<n);
    ten[0] = 1;
    for(int i = 1; i <= n; ++ i) ten[i] = (ten[i-1]*10) % mod;//, cout << ten[i] << " " ; cout << "\n";
}
ull Mod(ull x) {
    ull _x = x/mod;
    return x - _x*mod;
}
void write(int bit, int sl) {
    for(int i = sl - 1; i >= 0; -- i)
        if((bit>>i)&1) cout << B;
        else cout << A;
}
void sub12() {
    built(); m %= mod;
//    cout << m << "  " << mod << "  mod\n";
    if(n == 1) {
        if(A%mod == m) cout << A << "\n";
        else if(B%mod == m) cout << B << "\n";
        else cout << "-1\n";
        exit(0);
    }
    int half = n/2; n -= half;
//    cout << half << "  " << n << "\n";
    int bit = (1<<half); //cout << bit << "\n";
    ull num, _num;
    for(int now = 0; now < bit; ++ now) {
        num = 0;
        for(int i = 0 ; i < half; ++ i)
            if((now >> i)&1) num = Mod(num + B*ten[i]);
            else num = Mod(num + A*ten[i]);
        if(!sav[num]) sav[num] = now;
//        cout << now << " " << num << "\n";
    }
//    cout << "\n";
    bit = (1<<n);
    for(int now = 0; now < bit; ++ now) {
        num = 0;
        for(int i = 0 ; i < n; ++ i)
            if((now >> i)&1) num = Mod(num + B*ten[i + half]);
            else num = Mod(num + A*ten[i + half]);
        _num = Mod(m - num + mod);
//        cout << now << "  " << num << "  " << _num << "\n";
        if(sav[_num]) {
//            cout << num << "  " << _num << "\n";
//            cout << "::  " << now << "  " << sav[_num] << "\n";
            write(now, n); write(sav[_num], half); cout << "\n";
            exit(0);
        }
    }
    cout << "-1\n";
}

int main() {
//#define file "r"
#define file "MODULO"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);

    cin >> A >> B >> n >> m;
    if(A > B) swap(A, B);
    if(n <= 40) sub12();
    cout << "-1\n";

    return 0;
}
