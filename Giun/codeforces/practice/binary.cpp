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

cll maxd = 36;
ll c[maxd][maxd] = {{0}}, n, k, ans, d0, d00; //Cnk
vec(ll) a;

ll getS(ll q, ll r){
    ll tmp = 0;
    lp(i, 0, q && (r-i>=0)) tmp += c[i][r - i];
    return tmp;
}

ii main(){
    opt;
    // file;
    lp(i, 0, 35) c[i][0] = 1;
    lp(i, 1, 35) lp(j, 1, i) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    while(cin >> n >> k){
        a.clear(); ans = 0, d0 = 0, d00 = 0;
        while(n) a.push_back(n&1), d00 += (n&1)?0:1, n >>= 1;
        if(!k) {ans = a.size() - 1; if(!d00) ++ans; cout << ans << endl; continue;}
        reverse(a.begin(), a.end());
        lp(i, 1, a.size() - 1)
            if(a[i]) ans += getS(a.size() - i - 2, k - d0 - 1)  + ((d00 + 1) == k)?1:0;
            else ++d0;
        lp(i, 0, a.size() - 2) ans += c[i][k];
        if(d00==k)++ans;
        if(k==1)++ans;
        cout << ans << endl;
    }
}

// https://codeforces.com/group/FLVn1Sc504/contest/234046/problem/A
// https://codeforces.com/group/FLVn1Sc504/contest/266446/problem/B
// https://codeforces.com/group/FLVn1Sc504/contest/274811/problem/J
// https://codeforces.com/contest/1393/problem/D
// https://codeforces.com/group/FLVn1Sc504/contest/274425/problem/P
// http://vnoi.info/wiki/translate/topcoder/dynamic-programming
// http://vnoi.info/wiki/algo/dp/basic-problems
// http://vnoi.info/wiki/algo/dp/palindrome-problems
