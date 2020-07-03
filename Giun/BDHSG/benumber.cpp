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
#define filln(a, b) memset(a, b, sizeof(a))
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll q, p, t, a1, n, tu, mau, ans = LLONG_MAX, ps, ans1, p10[19];

ii main(){
    opt;
    file;
    cin >> p >> q;
    if(q != 1){
    ll x = __gcd(p, q);
    p /= x, q /= x;
    }
    p10[0] =1;
    lp(i, 1, 18) p10[i] = p10[i-1] * 10;
    if(q == p && q == 1){
        cout << 1;
        return 0;
    }
    lp(a1, 1, 9){
        lp(n, 1, 9){
            if(p10[n - 1] > LLONG_MAX/p) continue;
            tu = a1*(p * p10[n - 1] - q);
            mau = q * 10 - p;
            if(!(tu % mau)){
                ps = (tu / mau);
                if(n == 1 && ps != 0) continue;
                if(ps >= 0) ans = min(ans,(ll)( a1 * p10[n-1] + ps));
            }
        }
    }
    //cerr << ans;
    if(ans == LLONG_MAX) cout << -1;
    else cout << ans;
}
