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

cll maxl = 107;
string a, b;
ll f[maxl][maxl] = {{0}};

ii main(){
    opt;
    file;
    cin >> a >> b;
    lp(i, 1, 100) f[i][0] = i, f[0][i] = i;
    lp(i, 1, a.length() - 1){
        lp(j, 1, b.length() - 1){
            if(a[i] == b[j]) f[i][j] = f[i - 1][j - 1];
            else{
                f[i][j] = min(f[i - 1][j], min(f[i - 1][j - 1], f[i][j - 1])) + 1;
            }
        }
    }
    cout << f[a.length() - 1][b.length() - 1];
}
