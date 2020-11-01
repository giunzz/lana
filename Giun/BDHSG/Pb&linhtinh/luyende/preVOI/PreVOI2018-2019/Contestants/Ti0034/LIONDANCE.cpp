#include <bits/stdc++.h>

using namespace std;
#define fname "LIONDANCE"
#define For(i, a, b) for(int i = a; i <= b; i++)
#define FOr(i, a, b) for(int i = a; i < b; i++)
#define FOR(i, a, b) for(int i = a; i >= b; i--)
typedef int64_t ll;
typedef vector <ll> num;
const int N = 105;
int n, m;
ll a[N], b[N];
num res, f[N][N];
num operator +(num a,ll b){
    a.push_back(b);
    return a;
}
num nmax(num a, num b){
    if (a.size() > b.size()) return a;
    if (a.size() < b.size()) return b;
    FOr (i, 0, a.size()){
        if (a[i] != b[i]){
            if (a[i] > b[i]) return a;
            if (b[i] > a[i]) return b;
        }
    }
    return a;
}
void tao(){
    freopen (fname".inp", "w", stdout);
    n = 100; m = 50;
    cout << n << ' ' << m << '\n';
    For (i, 1, 50) cout << 1 << ' ';
    For (i, 1, 50) cout << 2 << ' ';
    cout << '\n';
    For (i, 1, 50) cout << 1 << ' ';
    For (i, 1, 50) cout << 2 << ' ';
}
int main(){
    //tao();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(fname".inp", "r")){
        freopen (fname".inp", "r", stdin);
        freopen (fname".out", "w", stdout);
    }
    cin >> n >> m;
    For (i, 1, n) cin >> a[i];
    For (i, 1, n) cin >> b[i];
    For (i, 1, n){
        For (j, 1, n){
            if (a[i] == b[j]){
                f[i][j].push_back(a[i]);
                For (k, 1, i-1)
                    if (abs(a[i]-a[k]) <= m)
                        f[i][j] = nmax(f[i][j], f[k][j-1]+a[i]);
            }
            else f[i][j] = f[i][j-1];
            res = nmax(res, f[i][j]);
        }
    }
    cout << res.size() << '\n';
    FOr (i, 0, res.size()) cout << res[i] << ' ';
}
