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
#define pb push_back
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "delstr";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll k, f[1007][1007] = {{0}}, ff[1007][1007]  = {{0}};
string s, ss;

int main(){
    opt;
    file;
    cin >> k >> s;
    ss.pb(s[0]);
    lp(i, 1, s.size()-1) if(s[i] != s[i - 1]) ss.pb(s[i]);
    ll n = ss.size(), j;
    lp(l, 0, n - 1){
        lp(i, 0, n - 1){
            if(l + i >= n) break;
            j = l + i;
            if(i == j) {
                f[i][j] = 1, ff[i][j] = 1;
                //continue;
            }
            else if(ss[i] != ss[j]){
                f[i][j] = min(f[i + 1][j] + 1, min(f[i][j - 1] + 1, f[i + 1][j - 1] + 2));
            }
            else{
                ll tmp;
                lpd(q, j - 1, i + 1) if (ss[j] == s[q]) {tmp = f[i][q]; f[i][j] = tmp + j - q - 1; break;}
                lp(q, i + 1, j - 1) if (ss[i] == s[q]) {tmp = f[i][q]; f[i][j] = tmp + j - q - 1; break;}
                f[i][j] = min(f[i + 1][j] + 1, min(f[i][j - 1] + 1, f[i + 1][j - 1] + 1));

            }
        }
        cerr << endl;
    }
    lp(i, 0, n- 1){
        lp(j, i, n - 1) cerr << f[i][j] << ' ';
        cerr << endl;
    }
    //cerr << f[0][1];
    cout << f[0][n - 1];
}
