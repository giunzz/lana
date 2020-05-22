#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e6 + 7;
ll n, ans[maxn] = {0};
string s;

int main(){
    opt;
    file;
    cin >> n >> s;
    s = "0" + s;
    ans[1] = 1;
    lp(i, 1, n - 1){
        if(s[i] == '=') ans[i + 1] = ans[i];
        if(s[i] == 'R') ans[i + 1] = ans[i] + 1;
        if(s[i] == 'L') ans[i + 1] = 1;
    }
    lpd(i, n, 2){

    }
    lp(i, 1, n) cerr << ans[i] << " ";
}
