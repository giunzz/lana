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

ll qr, n, a[57] =  {0}, b[57] = {0}, o, c, ans;

ii main(){
    opt;
    // file;
    cin >> qr;
    while(qr--){
        o = INT_MAX, c = INT_MAX, ans = 0;
        cin >> n;
        lp(i, 1, n) {cin >> a[i]; c = min(c, a[i]);}
        lp(i, 1, n) {cin >> b[i]; o = min(o, b[i]);}
        lp(i, 1, n){
            if((a[i] - c) < (b[i] - o)) {
                ans += (a[i] - c);
                b[i] -= (a[i] - c);
                ans += (b[i] - o); 
            }
            else{
                ans += (b[i] - o);
                a[i] -= (b[i] - o);
                ans += (a[i] - c);
            }
        }
        cout << ans << endl;
    }
}
