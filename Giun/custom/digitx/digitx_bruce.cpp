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
const string tenfile = "digitx";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

ll gett(ll t){
    while(t > 9){
        if(t % 10) t = t / 10 * (t % 10);
        else t /= 10;
    }
    return t;
}

int main(){
    opt;
    file;
    ll q, l, r, k;
    cin >> q;
    while(q--){
        ll ans = 0;
        cin >> l >> r >> k;
        lp(i, l, r){
            ll p = gett(i);
            if(p == k) ++ans;
        }
        cout << ans << endl;
    }
}
