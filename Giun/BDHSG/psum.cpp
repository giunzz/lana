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
ll x, n, dp[mxn][40] = {0}, p[40] = {0}, mx;

ll Pow(ll u, ll p){
    ll res = 1;
    lp(i, 1, p) res *= u;
    return res;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> x >> n;
    lp(i, 1, 39) if((p[i] = Pow(i, n)) > x){mx = i - 1; break;}
    dp[0][0] = 1;
    lp(i, 1, x) lp(j, 1, mx){
        if(p[j] > i) break;
        lp(k, 0, j - 1) dp[i][j] += dp[i - p[j]][k];
    }
    ll ans = 0;
    lp(i, 0, mx) ans += dp[x][i];
    cout << ans; 
}