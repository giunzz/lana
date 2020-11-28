#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".ans").c_str(), "w", stdout);
}

cll MOD = 1 << 30;
ll a, b, c, s, ans = 0;

int main(){
    // file("dnprevoic");
    cin >> a >> b >> c;
    lp(x, 1, a){
        lp(y, 1, b){
            lp(z, 1, c){
                s = x * y * z;
                ll tmp = 0;
                for(ll i = 1; i * i <= s; ++i){
                    if(s % i) continue;
                    if(i * i == s) (++tmp) %= MOD;
                    else (tmp += 2) %= MOD;
                }
                // ll sl = 6;
                // if(y == z && x != y) sl = 3;
                // else if(x == y && y != z) sl = 3;
                // else if(x == z && x != z) sl = 3;
                // else if(x == y && y == z) sl = 1;
                // cerr << x << ' ' << y << ' ' << z << "   " << s << "   " << sl << "   " << tmp << '\n';
                (ans += tmp) %= MOD;
            }
        }
    }
    cout << ans;
}