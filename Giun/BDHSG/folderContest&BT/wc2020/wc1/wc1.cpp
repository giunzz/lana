#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a < c; a++)
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
cll MOD = 1000000007;
const double esf = 1e-9;
const string tenfile = "wc1";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll f[11][85][85][85][3] = {{{{{0}}}}};

ll dp(string n, ll k){
    ll len = n.size();
    // n = '0' + n;
    // f[0][0][0][0][1] = 1;
    lp(x, 1, 10){
        ll stt;
        if(x < n[0] - '0') stt = 0;
        else if(x == n[0] - '0') stt = 1;
        else stt = 2;
        ++f[1][x % k][x % k][x % k][stt];
    }
    lp(i, 1, len){
        lp(r, 0, k){
            lp(sr, 0, k){
                lp(pr, 0, k){
                    lp(stt, 0, 3){
                        if(!f[i][r][sr][pr][stt]) continue;
                        for(ll d = 0; d <= 9; d++){
                            ll newr, newsr, newpr, newstt;
                            newr = (r * 10 + d) % k;
                            newsr = (sr + d) % k;
                            newpr = (pr * d) % k;
                            if(stt == 0 || stt == 2) newstt = stt;
                            else{
                                if(d < n[i] - '0') newstt = 0;
                                else if (d == n[i] - '0') newstt = 1;
                                else newstt = 2;
                            }
                            // if(i == 1 && d == 0 && stt == 1) cerr << newstt;
                            f[i + 1][newr][newsr][newpr][newstt] = (f[i + 1][newr][newsr][newpr][newstt] + f[i][r][sr][pr][stt]) % MOD;
                        }
                    }
                }
            }
        }
    }
    ll res = (f[len][0][0][0][0] + f[len][0][0][0][1]) % MOD;
    for (int i = 1; i < len; i++) {
        (res += f[i][0][0][0][0]) %= MOD;
        (res += f[i][0][0][0][1]) %= MOD;
        (res += f[i][0][0][0][2]) %= MOD;
    }
    return res;
}

int main(){
    opt;
    file;
    ll t, k;
    string n;
    cin >> t;
    while(t--){
        memset(f, 0, sizeof(f));
        cin >> n >> k;
        if(k > 81 || n.size() * 9 < k) {
            cout << 0 << endl;
        }
        else{
            cout << dp(n, k) << '\n';
        }
    }
}
