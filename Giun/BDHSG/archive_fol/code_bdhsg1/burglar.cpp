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
const string tenfile = "burglar";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxm = 25;
pp(ll, ll) a[maxm];
ll n, m, ans = 0;

ii main(){
    opt;
    file;
    cin >> n >> m;
    lp(i, 1, m){
        cin >> a[i].se >> a[i].fi;
    }
    sort(a + 1, a + 1 + m);
    lpd(i, m, 1){
        if(n >= a[i].se){
            ans += a[i].fi * a[i].se;
            n -= a[i].se;
        }
        else{
            ans += a[i].fi * n;
            break;
        }
    }
    cout << ans;
}
