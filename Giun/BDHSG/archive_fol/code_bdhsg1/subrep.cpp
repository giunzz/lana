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
const string tenfile = "subrep";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

char x;
ll ans = 0, lap = 0;
string s, t;

int main(){
    opt;
    file;
    cin >> s >> t;
    lp(i, 0, t.size() - 1){
        if(t[i] == s[lap]){
            if(!((lap + 1) % s.size())){
                ++ans;
            }
            lap = (lap + 1) % s.size();
        }
    }
    cout << ans;
}
