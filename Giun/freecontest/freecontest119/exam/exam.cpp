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

pp(ll, ll) a[3];
ll d, ans[3] = {0};

int main(){
    opt;
    // file;
    lp(i, 0, 2){
        cin >> a[i].first;
        a[i].second = i;
    }
    cin >> d;
    sort(a, a + 3);
    lp(i, 0, 2) ans[a[i].second] = min(d, a[i].first), d -= min(d, a[i].first);
    lp(i, 0, 2) cout << ans[i] << ' ';
}

