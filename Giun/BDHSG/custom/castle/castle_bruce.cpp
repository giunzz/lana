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
const string tenfile = "castle";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll maxn = 1e3 + 7;
ll m, n, a[maxn][maxn], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, b[maxn][maxn];

int main(){
    opt;
    file;
    cin >> m >> n;
    lp(i, 0, 1e3) a[i][0] = a[0][i] = 1;
    lp(i, 1, m) lp(j, 1, n){
        char c;
        cin >> c;
        a[i][j] = c - '0';
    }
    ll ti = 0;
    lp(i, 2, m- 1) lp(j, 2, n- 1){
        if(a[i][j]){
            ++ti;
            queue<pp(ll, ll)> q;
            lp(k, 0, 3){
                ll u = i + dx[k], v = j + dy[k];
                if(a[i][j] || b[u][v] == ti) continue;
                q.push({})
            }
        }
    }
}
