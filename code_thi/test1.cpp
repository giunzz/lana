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
#define filln(a, b) memset(a, b, sizeof(a))
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "giun";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
ll p2[65] = {1}, n, t;
ll dequy(ll vt){
    if(vt == 1) return 0;
    ll lap;
    lp(i, 0, 63){
        if(p2[i] >= vt) {
            lap = i;
            break;
        }
    }
    return ((dequy(vt - p2[lap] / 2) + 1) % 3);
}
ii main(){
    opt;
    file;
    lp(i, 1, 64) p2[i] = p2[i - 1] * 2;
    while(cin >> n){
        cout << dequy(n) << endl;
    }
}