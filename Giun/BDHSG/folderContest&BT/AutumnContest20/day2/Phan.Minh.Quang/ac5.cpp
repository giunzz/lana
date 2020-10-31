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
const string tenfile = "ac5";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 110;
ll qr, n, k, key[maxn] = {0}, cnt;

int main(){
    opt;
    file;
    cin >> qr;
    while(qr--){
        cnt = 0;
        cin >> n >> k;
        lp(i, 1, n) cin >> key[i];
        sort(key + 1, key + 1 + n);
        lpd(i, n, 1){
            if(key[i] != 1){
                while(!(k % key[i])){
                    ++cnt, k /= key[i];
                }
            }
        }
        if(k == 1) cout << cnt << endl;
        else cout << "Impossible" << endl;
    }
}
