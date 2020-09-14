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
const string tenfile = "move";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 507;
ll n, k, f[maxn][maxn] = {{0}};
pp(ll, ll) g[maxn];

#define x first
#define y second

inline ll kc(pp(ll, ll) &a, pp(ll, ll) &b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main(){
    opt;
    file;
    cin >> n >> k;
    lp(i, 1, n){
        cin >> g[i].x >> g[i].y;
    }
    // lp(i, 2, n){
    //     lp(j, 0, k) f[i][j] = LLONG_MAX;
    // }
    lp(i, 2, n){
        lp(j, 0, i){
            if(i != j) f[i][j] = LLONG_MAX;
            else{
                f[i][j] = 0; continue;
            }
            for(ll z = i - 1; z >= 1; z--){
                if(j - (i - z - 1) < 0) break;
                if(z < (j - (i - z - 1))) continue;
                f[i][j] = min(f[i][j], kc(g[i], g[z]) + f[z][j - (i - z - 1)]);
            }
        }
    }
    // lp(i, 1, n){
    //     lp(j, 0, i) cerr << f[i][j] << ' ';
    //     cerr << endl;
    // }
    cout << f[n][k];
}
