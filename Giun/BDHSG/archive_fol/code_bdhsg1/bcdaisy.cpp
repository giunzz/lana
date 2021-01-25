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
const string tenfile = "bcdaisy";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 253;
ll n, m, f[maxn][maxn] = {{0}}, d[maxn] = {0}, x, y;

void dfs(ll u){
    lp(i, 2, n){
        if(!d[i] && f[u][i]){
            d[i] = 1;
            dfs(i);
        }
    }
}

int main(){
    opt;
    file;
    cin >> n >> m;
    lp(i, 1, m){
        cin >> x >> y;
        f[x][y] = 1, f[y][x] = 1;
    }
    dfs(1);
    lp(i, 2, n){
        if(!d[i]) cout << i << endl;
    }
}
