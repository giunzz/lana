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
const string tenfile = "garden";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

ll n, m, q;
vec(pp(ll, ll)) g;

#define mp make_pair

int main(){
    opt;
    file;
    cin >> n >> m;
    lp(i, 1, n) lp(j, 1, m){
        char x;
        cin >> x;
        if(x == 'x'){
            g.push_back({i, j});
        }
    }
    cin >> q;
    lp(i, 1, n){
        ll x, y, ma = LLONG_MAX;
        cin >> x >> y;
        for(pp(ll, ll) p : g){
            ma = min(ma, (p.first - x) * (p.first - x) + (p.second - y) * (p.second - y));
        }
        cout << ma << '\n';
        g.push_back({x, y});
    }
}
