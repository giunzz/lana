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

cll maxn = 1e4 + 3;
ll n, c, f[maxn][maxn] = {{0}}, g[maxn][maxn] = {{0}};

int main(){
    opt;
    file;
    cin >> n >> c;
    lp(i, 1, n) f[i][0] = 1, g[i][0] = 1;
    lp(i, 1, n){
        lp(j, 1, c) {
            if(j < i){
                f[i - 1][j] = g[i - 1][j - 1];
            }
        }
    }
    cout << f[n][c];
}
