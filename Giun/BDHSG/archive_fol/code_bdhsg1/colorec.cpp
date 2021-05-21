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

cll mxn = 407, mxbit = 1 << 4;
ll n, a[mxn][mxn] = {{0}}, dp[mxbit] = {0}, ans = 0;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        ll x, y, c;
        cin >> x >> y >> c;
        a[x + 200][y + 200] = 1 << (c - 1);
    }
    lp(i, 1, 400) lp(j, 0, i - 1){
        memset(dp, 0, sizeof dp);
        lp(k, 0, 400){
            if(a[k][i] && a[k][j]){
                ll mask = a[k][i] | a[k][j];
                if(k) ans += dp[mxbit - mask - 1];
                ++dp[mask];
            }
        }
    }
    cout << ans;
}