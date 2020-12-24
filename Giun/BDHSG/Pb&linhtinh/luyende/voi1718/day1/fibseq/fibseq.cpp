#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void OF(const string f){
    freopen((f + ".inp").c_str(), "r", stdin);
    freopen((f + ".out").c_str(), "w", stdout);
}

ll n, pos, mod;

struct quang{
    ll matrix[2][2] = {{0}};
};

quang mul(quang &x, quang &y){
    quang nquang;
    lp(i, 0, 1) lp(j, 0, 1){
        ll tmp = 0;
        lp(k, 0, 1) (tmp += x.matrix[i][k] * y.matrix[k][j]) %= mod;
        nquang.matrix[i][j] = tmp;
    }
    return nquang;
}

quang poww(quang x, ll v){
    if(v == 1) return x;
    quang tmp = poww(x, v >> 1);
    tmp = mul(tmp, tmp);
    if(v & 1) return mul(tmp, x);
    return tmp;
}

cll maxn = 1e3 + 7;
ll a[maxn] = {0}, dp[maxn][maxn], trace[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF("fibseq");
    ll cs;
    cin >> cs;
    quang fibo;
    lp(i, 0, 1) lp(j, 0, 1) fibo.matrix[i][j] = 1;
    fibo.matrix[0][0] = 0;
    while(cs--){
        cin >> n >> pos >> mod;
        lp(i, 0, n) lp(j, 0, n) dp[i][j] = trace[i][j] = 0;
        quang fi = poww(fibo, pos);
        ll p = fi.matrix[0][1], pre = fi.matrix[0][0];
        a[1] = p, a[0] = pre;
        lp(i, 2, n) (a[i] = a[i - 1] + a[i - 2]) %= mod;
        // lp(i, 1, n) cerr << a[i] << '\n';
        lp(i, 1, n){
            lp(j, 0, mod - 1){
                ll x = a[i] % mod, t = (j - x + mod) % mod;
                dp[i][j] = dp[i - 1][j], trace[i][j] = j;
                if(!dp[i - 1][t] && t) continue;
                // dp[i][j] = max(dp[i - 1][j], dp[i - 1][t] + 1);
                if(dp[i - 1][t] + 1 > dp[i][j]) dp[i][j] = dp[i - 1][t] + 1, trace[i][j] = t;
            }
        }
        cout << dp[n][0] << ' ';
        ll i = n, j = 0;
        while(i){
            // bool ok = 0;
            // lp(t, 0, mod - 1) if(dp[i][j] == dp[i - 1][t] + 1){
            //     cerr << i << ' ';
            //     cout << (pos + i - 1) << ' ';
            //     j = t;
            //     // ok = 1;
            //     break;
            // }
            // ll x = a[i] % mod, t = (j - x + mod) % mod;
            ll pr = trace[i][j];
            if(dp[i][j] == dp[i - 1][pr] + 1){
                // cerr <<i << ' ';
                cout << (pos + i - 1) << ' ';
                // j = pr; 
            }
            --i;
            j = pr;
            // if(ok) 
        }   
        cout << '\n';
    }
}