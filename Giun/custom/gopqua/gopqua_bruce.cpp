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
const string tenfile = "gopqua";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll maxn = 2e5 + 7;
ll m, n, a[maxn], cnt[(ll)1e3+7] = {0};

int main(){
    opt;
    file;
    cin >> n >> m;
    lp(i, 1, n) cin >> a[i];
    ll l, r, ans;
    lp(i, 1, m){
        ans = 0;
        memset(cnt, 0, sizeof(cnt));
        cin >> l >> r;
        lp(i, l, r) ++cnt[a[i]];
        lp(i, 1, 1e3) ans += cnt[i] * cnt[i] * i;
        cout << ans << endl;
    }
}
