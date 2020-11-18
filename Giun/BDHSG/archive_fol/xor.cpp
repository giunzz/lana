#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "xor";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll t, l, r;

inline ll fx(ll x){
    if(x % 4 == 0) return x;
    else if(x % 4 == 1) return 1;
    else if(x % 4 == 2) return x + 1;
    else return 0;    
}

ii main(){
    opt;
    file;
    cin >> t;
    ll tmp;
    while(t--){
        cin >> l >> r;
        cout << (fx(r) ^ fx(l - 1)) << endl;
    }
}
