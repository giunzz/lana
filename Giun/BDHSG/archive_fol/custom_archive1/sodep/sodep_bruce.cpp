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
const string tenfile = "sodep";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

ll n;

bool check(ll i){
    while(i > 9){
        ll tmp = i % 10;
        i /= 10;
        if(tmp % 2 == i % 2) return 1;
    }
    return 0;
}

int main(){
    opt;
    file;
    cin >> n;
    ll n1 = n, n2 = n;
    while(check(n1)){
        --n1;
    }
    while(check(n2)){
        ++n2;
    }
    if(n - n1 == n2 - n) cout << n1 << ' ' << n2;
    else if(n - n1 > n2 - n) cout << n2;
    else cout << n1;
    // cout << n1 << '\n' << n2;
}
