#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e3 + 7;
ll f[mxn][mxn] = {{0}}, n, m, ans = -1e18, test = 0, a[mxn][mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, n) lp(j, 1, m) f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (a[i][j] = read());
    // lp(i, 1, n) {
    //     lp(j, 1, m) cout << a[i][j] << ' ';
    //     cout << '\n';
    // }
    lp(i, 1, n) lp(j, 1, m) lp(x, 1, i) lp(y, 1, j)
        ans = max(ans, f[i][j] - f[x - 1][j] - f[i][y - 1] + f[x - 1][y - 1]);
    cout << ans; 
    lp(i, 1, n) lp(j, 1, m) lp(x, 1, i) lp(y, 1, j){
        ll s = 0;
        lp(ii, x, i) lp(jj, y, j) s += a[ii][jj];
        if(s >= 992473) cerr << "YES\n";
    }
}