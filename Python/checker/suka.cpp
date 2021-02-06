#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "suka"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 407;
ll m, n, row[maxn][maxn], col[maxn][maxn], ans = 0;
bool a[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> m >> n;
    lp(i, 1, m) lp(j, 1, n){
        char c; cin >> c;
        a[i][j] = (c == '.');
    }
    lp(i, 1, m) lp(j, 1, n){
        row[i][j] = (a[i][j] ? row[i][j - 1] + 1 : 0);
        col[i][j] = (a[i][j] ? col[i - 1][j] + 1 : 0);
        ll mincol = LLONG_MAX, minrow = LLONG_MAX;
        lpd(r, i, 1){
            if(!a[r][j]) break;
            minrow = min(minrow, row[r][j]);
            ll num_col = i - r + 1;
            ans = max(ans, (num_col + minrow) * 2 - 1);
        }
        // lpd(c, j, 1){
        //     if(!a[i][c]) break;
        //     mincol = min(mincol, col[i][c]);
        //     ll num_row = j - c + 1;
        //     ans = max(ans, (num_row + mincol) * 2 - 1);
        // }
    }
    cout << ans;
}