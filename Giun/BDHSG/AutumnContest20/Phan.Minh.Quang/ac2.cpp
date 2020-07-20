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
const string tenfile = "ac2";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 57;
ll t, n, g, k, d[maxn], mi, ma, cnt, ans[maxn];
pp(ll, ll) a[maxn];

int main(){
    opt;
    file;
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n >> g >> k;
        lp(i, 1, n) {cin >> a[i].fi; a[i].se = i;}
        sort(a + 1, a + 1 + n);
        // lp(i, 1, n) cerr << a[i].fi << " ";
        lpd(i, n, 1){
            mi = a[i].fi, ma = a[i].fi, ++cnt;
            lpd(j, i, 1){
                // mi = min(a[j].fi, mi), ma = max(a[j].fi, ma);
                mi = a[j].fi;
                if(ma - mi <= k) d[j] = cnt;
                else {i = j + 1; break;}
                if(j == 1) i = 0;
            }
            // cerr << i << " " << cnt << endl;
        }
        // cerr << cnt << endl;
        if(cnt > g){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        if(cnt < g){
            lpd(i, n, 1){
                if(g == cnt) break;
                if(d[i] == d[i - 1]) d[i] = g--;
            }
        }
        lp(i, 1, n){
            ans[a[i].se] = d[i];
        }
        lp(i, 1, n) cout << ans[i] << " ";
        cout << endl;
    }
}
