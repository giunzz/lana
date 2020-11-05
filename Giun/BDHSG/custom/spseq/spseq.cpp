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
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "spseq";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
ll n, a[maxn] = {0}, f[maxn], ans = 0;

ii main(){
    opt;
    // file;
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    lp(i, 0, n+1)f[i]=INT_MAX;
    lp(i, 1, n){
        lp(j, i + 1, n){
            if(a[j] > a[j - 1]) f[j] = min(i, f[j]);
            else {
                i = j - 1;
                break;
            }
        }
    }
    lp(i, 1, n){
        if(f[i] == INT_MAX) f[i] = i;
    }
    ll bg = 1, ed = 1;
    lp(i,2,n){
        ans = max(ans, min(ed - bg + 1, bg - f[bg] + 1) * 2 - 1);
        if(a[i] >= a[i - 1]) {
            bg = i;
        }
        else{
            ed = i;
        }
    }
    cout << ans;
}
