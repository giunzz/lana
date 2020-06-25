//https://codeforces.com/group/FLVn1Sc504/contest/271715/problem/D
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
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 5e2 + 7;
ll f[maxn][maxn], n, fp[maxn][maxn], ans = INT_MAX, k;

ii main(){
    opt;
    file;
    memset(f, 0, sizeof(f));
    cin >> n;
    lp(i, 0, n + 4) f[i][0] = INT_MAX, f[0][i] = INT_MAX;
    lp(i, 0, n + 4) fp[i][n + 1] = INT_MAX, fp[0][i] = INT_MAX;
    cin >> k;
    lp(i, 1, k){
        ll a, b;
        cin >> a >> b;
        f[a][b] = INT_MAX, fp[a][b] = INT_MAX;
    }
    lp(i, 1, n){
        lp(j, 1, n){
            if((i == 1 && j == 1) || f[i][j] >= INT_MAX) continue;
            f[i][j] = min(f[i][j - 1], min(f[i - 1][j], f[i-1][j-1])) + 1;
        }
    }
    f[1][n] = 0;
    lp(i, 1, n){
        lpd(j, n, 1){ // i cot j hang
            if((i == 1 && j == n) || fp[i][j] >= INT_MAX) continue;
            fp[i][j] = min(fp[i - 1][j], min(fp[i][j + 1], fp[i - 1][j + 1])) + 1;
            if(fp[i][j] == f[i][j]) ans = min(ans, f[i][j]);
        }
    }
    cout << ans;
}
