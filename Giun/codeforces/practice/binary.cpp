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

cll maxd = 40;
ll c[maxd][maxd] = {{0}}, n, k, ans; //Cnk
vec(ll) dg;

void rg(ll x){
    if(!x) {dg.push_back(x); return;}
    while(x) dg.push_back(x&1), x>>=1;
}

ii main(){
    opt;
    file;
    lp(i, 0, 36) c[i][0] = 1;
    lp(i, 1, 36) lp(j, 1, i) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    while(cin >> n >> k){
        ans = 0; dg.clear();
        ll cnt0 = 0, tmp0 = 0, tmp;
        rg(n);
        for(ll i : dg) if(!i) ++cnt0;
        if(k == cnt0) ++ans;
        reverse(dg.begin(), dg.end());
        lp(i, 1, dg.size()-1)
            if(dg[i]){
                tmp = k - tmp0 - 1;
                if(cnt0-tmp0==dg.size()-i-1&&cnt0+1==k)++ans;
                lp(j, i + 1, dg.size() - 1 && tmp >= 0 && k <= 32) ans += c[dg.size() - j - 1][tmp--];
            }
            else ++tmp0;
        lp(i, 1, dg.size()-1 && k <= 32)
            ans+=c[dg.size()-i-1][k];
        if(k==1 && n)++ans;
        cout<<ans<<endl;
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
