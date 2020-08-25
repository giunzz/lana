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

ii main(){
    opt;
    // file;
    ll cases, x;
    string s;
    cin >> cases;
    while(cases --> 0){
        bool c = 0;
        cin >> s >> x;
        string w(s.length(), '1');
        lp(i, 0, s.length() - 1){
            if(s[i] == '1') continue;
            if(i + x < s.length()) w[i + x] = '0';
            if(i - x >= 0) w[i - x] = '0';
        }   
        lp(i, 0, s.size() - 1){
            if(s[i] == '1') if(!((i + x < s.size() && w[i + x] == '1') || (i - x >= 0 && w[i - x] == '1'))) c = 1;
            // else if(((i + x < s.size() && w[i + x] == '1') || (i - x >= 0 && w[i - x] == '1'))) c = 1;
        }
        if(!c) cout << w << endl;
        else cout << -1 << endl;
    }
}
