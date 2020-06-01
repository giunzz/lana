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
const string tenfile = "ternary";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll a, c, ans = 0;
vec(ll) ta, tc;

vec(ll) doi(ll num){
    vec(ll) tmp;
    if(num == 0) tmp.push_back(0);
    while (num != 0)
    {
        tmp.push_back(num%3);
        num /= 3;
    }
    return tmp;
}

int main(){
    opt;
    file;
    cin >> a >> c;
    ta = doi(a);
    tc = doi(c);
    while(ta.size() < tc.size()) ta.push_back(0);
    while(ta.size() > tc.size()) tc.push_back(0);
    //lp(i, 0, ta.size() - 1) cerr << tc[i];
    lpd(i, ta.size() - 1, 0){
        ans += ((6 + (tc[i] - ta[i]))%3) * pow(3, i);
    }
    cout << ans;
}
