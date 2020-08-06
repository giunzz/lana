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

cll maxn = 2e5 + 7;
ll qr, n, ans[maxn] = {0};
stack<ll> v[2];
string s;

ii main(){
    opt;
    // file;
    cin >> qr;
    while(qr--){
        ll tt = 0;
        while(!v[0].empty()) v[0].pop();
        while(!v[1].empty()) v[1].pop();
        cin >> n >> s;
        lp(i, 0, n - 1){
            if(s[i] == '0'){
                if(v[1].empty()) ans[i] = ++tt;
                else ans[i] = ans[v[1].top()], v[1].pop();
                v[0].push(i);
            }
            else{
                if(v[0].empty()) ans[i] = ++tt;
                else ans[i] = ans[v[0].top()], v[0].pop();
                v[1].push(i);
            }
        }
        cout << tt << endl;
        lp(i, 0, n - 1) cout << ans[i] << " ";
        cout << endl;
    }
}
