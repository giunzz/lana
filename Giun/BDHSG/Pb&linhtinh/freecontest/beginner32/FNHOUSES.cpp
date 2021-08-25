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

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

cll mxn = 1e3 + 2, dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {1, 0, -1, -1, -1, 0, 1, 1};
ll m, n, total = 0, more = 0;
bool a[mxn][mxn];

ll numpairs(ll x, ll y){
    ll cnt = 0;
    lp(i, 0, 7) cnt += a[x + dx[i]][y + dy[i]];
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    lp(i, 1, m) lp(j, 1, n){
        char c;
        cin >> c;
        a[i][j] = (c == '#');
    }
    lp(x, 1, m) lp(y, 1, n) 
        if(a[x][y]) total += numpairs(x, y);
        else more = max(more, numpairs(x, y));
    cout << total / 2 + more << '\n';
}