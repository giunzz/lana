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

cll maxn = 3e4;
ll n, node, a[maxn] = {0}, getsum[maxn] = {0}, sum = 0;

void getsm(int id){
    getsum[id] = getsum[id/2] + a[id];
    if(pow(2, n) <= id && id < pow(2, n + 1)) {
        // getsum[id] = getsum[id/2] + a[id];
        return;
    }
    getsm(2 * id);
    getsm(2 * id + 1);
}

int main(){
    opt;
    file;
    cin >> n;
    node = pow(2, n + 1) - 1;
    cerr << node << endl;
    lp(i, 2, node) cin >> a[i];
    getsm(1);
    lp(i, pow(2, n), pow(2, n + 1) - 1){
        
    }
}