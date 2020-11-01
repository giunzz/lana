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
const string tenfile = "gifts";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e6 + 7;
ll n, k, a[maxn] = {0}, r[maxn] = {0}, l[maxn] = {0};

int main(){
    opt;
    file;
    cin >> n >> k;
    lp(i, 1, n){
        cin >> a[i]; 
        a[i] += a[i - 1];
        if(i - k >= 0){
            l[i] = max(l[i - 1], a[i] - a[i - k]);
        }
    }
    // lp(i, 1, n) cerr << (a[i] - a[i - k]) << ' ';
    lpd(i, n - k + 1, 1){
        r[i] = max(r[i + 1], a[i + k - 1] - a[i - 1]);
    }
    // lp(i, 1, n) cerr << r[i] << ' ';
    ll ans = LLONG_MAX;
    // cerr << '\n';
    lp(i, k, n){
        // cerr << (i - k + 1) << " -> " << i << '\n';
        ll tmpL = l[i - k], tmpR = r[i + 1];// sum = a[i] - a[i - k];
        // cerr << tmpL << ' ' << sum << ' ' << tmpR << '\n';
        // if(tmpL && tmpR && tmpL <= sum && tmpR <= sum) ans = min(ans, max(tmpL, tmpR));
        // if(!tmpL && tmpR <= sum) ans = min(ans, tmpR); 
        // if(!tmpR && tmpL <= sum) ans = min(ans, tmpL); 
        if(tmpL && tmpR) ans = min(ans, max(tmpL, tmpR));
        if(!tmpL) ans = min(ans, tmpR); 
        if(!tmpR) ans = min(ans, tmpL); 
    }
    cout << ans;
}

