#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define Fname "cscong"
using namespace std;

cll maxn = 3e3 + 7;
ll n, a[maxn], f[maxn][maxn] = {{0}}, ff[maxn][maxn] = {{0}};

void init(){
    lp(i, 1, n){
        lp(j, i + 1, n) if(a[j] - a[i] > 0) ff[j][a[j] - a[i]] = i;
    }       
}

ll res = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    init();
    lp(i, 1, maxn - 1){
        lp(j, 1, maxn - 1) f[i][j] = 1;
    }
    lp(i, 1, n){
        lp(j, 1, a[i]){
            ll tmp = ff[i][j];
            if(tmp == 0) {continue;}
            else{   
                f[i][j] = f[tmp][j] + 1;
                res = max(res, f[i][j]);
            }
        }
    }
    cout << res;
}