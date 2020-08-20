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
#define setE(a, b) memset(a, b, sizeof(a))
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "top_sct";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e3 + 7;
ll n, m, k, a[maxn] = {0}, num;

ii main(){
    opt;
    file;
    cin >> n >> m >> k;
    lp(i, 1, n) cin >> a[i];
    ll s1, s2, rs;
    bool st1, st2;
    lp(i, 1, m){
        cin >> num;
        s1 = INT_MIN, s2 = INT_MAX, rs = s1, st1 = 0, st2 = 0;
        lpd(i, k, 1)
            if(a[i] > num && !st1) s1 = i, st1 = 1;
            else if(a[i] == num) {s1 = i, rs = i; break;}
        lp(i, k + 1, n)
            if(a[i] > num && !st2) s2 = i, st2 = 1;
            else if(a[i] == num) {s2 = i, rs = ((i - k - 1 > k - s1 && rs != INT_MIN) ? s1 : i); break;}
        if(rs != INT_MIN) cout << rs << ' ';
        else{
            rs = ((k - s1 <= s2 - k - 1) ? s1 : s2);
            if(rs == INT_MIN || rs == INT_MAX) rs = -1;
            cout << rs << ' ';
        }  
        if(rs != -1) a[rs] = 0;
    }
}
