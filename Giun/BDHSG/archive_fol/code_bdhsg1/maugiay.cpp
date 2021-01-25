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
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

double p, q;
ll m, n, pn, dg[6] = {0}, mr;

void rg(){
    ll uc = __gcd(m, n);
    if(!uc) uc = 1;
    m /= uc, n /= uc;
}

ii main(){
    opt;
    file;
    cin >> q;
    p = q;
    p *= 1e9;
    n = 1e9;
    m = p;
    pn = (ll)q;
    rg();
    mr = m - n * pn;
    dg[pn] = n;
    lpd(i, 5 - pn, 1){
        ll nn = mr / i;
        mr %= i;
        dg[pn] -= nn;
        dg[pn + i] += nn;
    }
    lp(i, 1, 5) cout << dg[i] << " ";
    cerr << m << endl << n;
}
