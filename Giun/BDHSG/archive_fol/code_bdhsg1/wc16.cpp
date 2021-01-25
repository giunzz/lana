#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "microbus"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e3 + 7;
ll n, m, a[maxn] = {0}, b[maxn] = {0}, q, p, f[maxn][maxn] = {{0}};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m >> p >> q;
    lp(i, 1, n) cin >> a[i];
    lp(i, 1, m) cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    lp(i, 0, n) f[i][0] = p * i;
    lp(j, 0, m) f[0][j] = q * j;
    lp(i, 1, n){
        lp(j, 1, m){
            f[i][j] = min(f[i - 1][j - 1] + abs(a[i] - b[j]), min(f[i - 1][j] + p, f[i][j - 1] + q));
        }
    }
    cout << f[n][m];
    // cerr << clock();
}