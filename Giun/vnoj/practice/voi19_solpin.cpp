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

cll mxn = 1e3 + 3;
ll m, n, a[mxn][mxn], dp[mxn][mxn] = {{0}}, totr = 0, totd = 0;

void tt(pp(ll, ll) &a, pp(ll, ll) &b){
    a.first += b.first;
    a.second += b.second;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> m >> n;
    lp(i, 0, m - 1) lp(j, 0, n - 1){
        cin >> a[i][j];
        a[i + m][j] = a[i][j + n] = a[i + m][j + n] = a[i][j];
    }
    lp(i, 0, 2 * m - 1) lp(j, 0, 2 * n - 1) dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
    pp(ll, ll) top, u, v;
    ll x, y, type;
    // lp(i, 0, 2 * m - 1){
    //     lp(j, 0, n * 2 - 1) cerr << a[i][j] << ' ';
    //     cerr << '\n';
    // }
    EACHCASE{
        cin >> type;
        if(!type){
            cin >> x >> y;
            (totr += x) %= n;
            (totd += y) %= m;
        } else{
            top = {totd, totr};
            cin >> u.first >> u.second >> v.first >> v.second;
            --u.first, --u.second, --v.first, --v.second;
            tt(u, top); tt(v, top);
            // if(cs == 4) cerr << top.first << ' ' << top.second << '\n' << u.first << ' ' << u.second << ' ' << v.first << ' ' << v.second;  
            ll ans = dp[v.first][v.second];
            if(u.first > 0) ans -= dp[u.first - 1][v.second];
            if(u.second > 0) ans -= dp[v.first][u.second - 1];
            if(u.first > 0 && v.first > 0) ans += dp[u.first - 1][u.second - 1];
            cout << ans << '\n';
        }
    }
}