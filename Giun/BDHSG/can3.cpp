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

ll a[40] = {0}, f[40][40] = {{0}}, m, sr, sl, alp, s = 0, d[37] = {0};
vec(ll) ansr, anrl;

int main(){
    opt;
    file;
    a[0] = 1;
    lp(i, 1, 37) a[i] = a[i - 1] * 3;
    cin >> m;
    lp(i, 0, 37 && (s + a[i] <= m)) alp = i, s += a[i];
    s = m;
    while(1){
        lpd(i, alp, 0){
            s += a[i];
            d[i] = 1;
            lpd(i, alp + 2, 0){
                
            }
        }
    }
}
