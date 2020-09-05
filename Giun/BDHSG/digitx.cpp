#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
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
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll q, t[(ll)1e6 + 10] = {0}, f[10][10][3];

void dp(string N){
    memset(f, 0, sizeof(f));
    ll len = N.size();
    N = "0" + N;
    f[0][0][1] = 1;
    for(ll pos = 0; pos < len; pos++){
        
    }
}

ll getRes(string &N){

}

void sol(ll l, ll r){
    string L = to_string(l), R = to_string(r);
    
}

ii main(){
    opt;
    file;
    ll l, r;
}
