#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define Fname "svot"
using namespace std;

cll maxn = 5007;
ll m, n, a[maxn][maxn] = {{0}}, f[maxn][maxn] = {{0}}, t[maxn] = {0}, tt[maxn][maxn] = {{0}};

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
    // fastscan(m); fastscan(n);
    scanf("%lld %lld", &m, &n);
    lp(i, 1, m){
        lp(j, 1, n){
            scanf("%lld", &a[i][j]); //on mon j trong i ngay
        }
    }
    // bool ok;
    lp(i, 1, m){
        lp(j, 1, n){
            f[i][j] = f[i][j - 1];
            lp(z, 1, i){
                if(f[i - z][j - 1] + a[z][j] > f[i][j]){
                    f[i][j] = f[i - z][j - 1] + a[z][j];
                    tt[i][j] = z;
                }
                // f[i][j] = max(f[i][j], f[i - z][j - 1] + a[z][j]);
                // if(f[i - z][j - 1] + a[z][j] == f[i][j]) tmpz = z;
            }
            // tt[i][j] = tmpz;
        }
    }
    printf("%lld\n", f[m][n]);
    //trace
    ll i = m, j = n, tmp;
    while(i && j){
        t[j] = tt[i][j];
        i -= t[j--]; 
    }
    // lp(i, 1, n){
    //     lp(j, 1, m){
    //         cerr << tt[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }
    // cerr << endl;
    // lp(i, 1, m){
    //     lp(j, 1, n){
    //         cerr << f[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }    
    lp(i, 1, n) printf("%lld %lld\n", i, t[i]);
}
