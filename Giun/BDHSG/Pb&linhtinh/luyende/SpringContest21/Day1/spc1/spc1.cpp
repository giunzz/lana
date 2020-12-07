#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

cll MOD = 1e9 + 7, maxn = 1e3 + 7;
ll n, k, a[maxn], f[maxn][maxn] = {{0}}, gt[maxn], c[maxn][maxn] = {{0}}, ff[maxn][maxn] = {{0}};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    file("spc1");
    ll cs;
    cin >> cs;
    a[0] = 0;
    f[0][0] = 1;
    gt[0] = 1;
    lp(i, 1, 1000) gt[i] = (gt[i - 1] * i) % MOD;
    lp(i, 0, 1000) c[0][i] = 1;
    lp(i, 1, 1000) lp(j, 1, i) c[j][i] = (c[j - 1][i - 1] + c[j][i - 1]) % MOD;
    // so cach chon i ng phan biet co danh so dung j ban ko danh so 
    lp(i, 1, 1000){
        lp(j, 1, i){
            f[i][j] = (f[i - 1][j] * j + f[i - 1][j - 1]) % MOD;
        } 
    }
    lp(i, 1, 1000) lp(j, 1, i) ff[i][j] = (ff[i][j - 1] + f[i][j]) % MOD; 
    lp(i, 1, 1000) lp(j, i + 1, 1000) ff[i][j] = f[i][i];
    // cerr << c[5][10];
    cerr << f[2][2] << '\n';
    while(cs--){
        cin >> n >> k;
        lp(i, 1, n) cin >> a[i];
        ll ans = 0;
        lp(j, 1, min(k, n)){
            ll tmp = c[j][k] * gt[j] * f[n][j], du = k - j, tmp1 = 1;
            // lp(i, 1, n) ans += tmp * ff[a[i]][du + 1] * gt[du];
            lp(i, 1, n) tmp1 *= ff[a[i]][du + 1];
            ans += tmp * tmp1 * gt[du];
            cerr << tmp << ' ';
        }
        cout << ans << '\n';
    }
} 