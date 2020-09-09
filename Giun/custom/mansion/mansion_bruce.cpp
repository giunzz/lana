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
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll maxm = 1e3 + 7;
bool f[maxm][maxm] = {{0}}, c[maxm][maxm] = {{0}};
ll n, m, k, d[maxm][maxm];

int main(){
    opt;
    file;
    cin >> m >> n >> k;
    ll x, y;
    lp(i, 1, k){
        cin >> x >> y;
        f[x][y] = 1;
    }
    priority_queue<pp(ll, pp(ll, ll)), vec(pp(ll, pp(ll, ll))), greater<pp(ll, pp(ll, ll))>> q;
    q.push({0, {1, 1}});
    lp(i, 1, m) lp(j, 1, n) d[i][j] = INT_MAX;
    d[1][1] = 0;
    ll wu;
    pp(ll, ll) u;
    while(q.size()){
        u = q.top().second;
        wu = q.top().first;
        q.pop();
        if(wu != d[u.first][u.second]) continue;
        if(c[u.first][u.second]){
            
        }
    }
}
