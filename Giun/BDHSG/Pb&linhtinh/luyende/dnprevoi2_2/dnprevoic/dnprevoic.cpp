#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

cll MOD = 1 << 30;
vec(ll) f;
ll a, b, c, n, s = 0, ans = 0;

void init(){
    lp(i, 1, n){
        f[i] = 0;
        for(ll j = 1; j * j <= i; ++j){
            if(j * j == i) ++f[i];
            else f[i] += 2;
        }
        (s += f[i]) %= MOD;
    }
}

int main(){
    file("dnprevoic");
    cin >> a >> b >> c;
    n = max(a, max(b, c));
    f.resize(max(a, max(b, c)) + 7);
    init();
    lp(i, 1, n) cerr << f[i] << ' '<< i << '\n';
    lp(i, 1, n){
        ll tmp = (f[i] * (f[i] * s) % MOD) % MOD;
        lp(j, i + 1, n){
            (tmp += (2 * (f[i] * (f[j] * s) % MOD) % MOD) % MOD) %= MOD;
        }
        (ans += tmp) %= MOD;
    }
    cout << ans;
}