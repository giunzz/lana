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
const string tenfile = "conseq";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e6 + 7;
ll n, a[maxn] = {0}, cnt[maxn] = {0}, res = 0;

int main(){
    opt;
    // file;
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
        if(a[i] > 1e6) continue;
        if(a[i] == 1) ++cnt[a[i]], res = (res + 1) % MOD;
        else if(cnt[a[i] - 1] != 0){
            cnt[a[i]] = (cnt[a[i]] + cnt[a[i] - 1]) % MOD;
            res = (res + cnt[a[i] - 1]) % MOD;
        }
        // cerr << i << ' ' << res << '\n';
    } 
    cout << res;
}
