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
const string tenfile = "spirit";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll maxn = 1e6 + 7;
ll a, b, c, f[maxn] = {0};

int main(){
    opt;
    file;
    cin >> a >> b >> c;
    if(a + 1 % c) f[a + 1] = 1;
    lp(i, a + 2, b){
        if(i % c == 0) f[i] = 0;
        else if((i - 1) % c == 0) f[i] = f[i - 2] + 1;
        else if ((i - 2) % c == 0) f[i] = f[i - 1] + 1;
        else f[i] = min(f[i - 1] + 1, f[i - 2] + 1);
    }
    cout << f[b];
    // lp(i, a, b) cerr << f[i] << ' ';
}
