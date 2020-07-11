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
const string tenfile = "fparty";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxk = 1e5 + 7;
ll n, k, a[maxk] = {0}, gt[maxk] = {1}, sl, ans = 1;

ll modexp(ll x, ll sn) 
{ 
    if (sn == 0) { 
        return 1; 
    } 
    else if (sn % 2 == 0) { 
        return modexp((x * x) % MOD, sn / 2); 
    } 
    else { 
        return (x * modexp((x * x) % MOD, (sn - 1) / 2) % MOD); 
    } 
} 

ll tohop(ll sn, ll sk){
    ll tu = gt[sn];
    ll mau = (gt[sk] * gt[sn - sk]) % MOD;
    ll c = __gcd(tu, mau);
    if(!c) c = 1;
    tu /= c;
    mau /= c;
    ll d = modexp(mau, MOD - 2);
    return (tu * (d % MOD)) % MOD;
}

ii main(){
    opt;
    file;
    cin >> n >> k;
    lp(i, 1, maxk - 1) gt[i] = (gt[i - 1] * i) % MOD; 
    lp(i, 1, k) cin >> a[i];
    sl = n;
    lp(i, 1, k){
        ans = (ans * tohop(sl, a[i])) % MOD;
        sl -= a[i];
    }
    cout << ans;
}
