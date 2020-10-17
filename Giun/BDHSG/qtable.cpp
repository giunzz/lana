#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "qtable"
using namespace std;

void OF(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 5007;
ll m, n, a[maxn][maxn] = {{0}}, f[maxn][maxn] = {{0}}, t[maxn] = {0};

int main(){
    OF();
    cin >> m >> n;
    lp(i, 1, m){
        lp(j, 1, n){
           cin >> a[i][j];
           if(a[i][j] >= a[i - 1][j]) f[i][j] = f[i - 1][j] + 1;
           else f[i][j] = 1;
           t[i] = max(t[i], f[i][j]);
        //    cerr << f[i][j] << ' ';
        }
        // cerr << endl;
    }
    ll l, r, k;
    cin >> k;
    // lp(i, 1, m) cerr << t[i] << endl; 
    lp(i, 1, k){
        cin >> l >> r;
        if(r - t[r] + 1 <= l) cout << "YES\n";
        else cout << "NO\n";
    }
}