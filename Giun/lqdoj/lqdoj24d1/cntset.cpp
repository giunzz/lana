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

cll mxn = 103, mxbit = 1 << 14 + 2;
ll a[mxn], n, m;
bool dp[mxbit];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE{
        memset(dp, 0, sizeof dp);
        cin >> n >> m;
        lp(i, 1, n){
            a[i] = 0;
            ll tmp; cin >> tmp;
            lp(j, 1, tmp){
                ll x; cin >> x;
                a[i] |= (1 << (x - 1));
            }
        }
        lp(i, 1, n){
            dp[a[i]] = 1;
            lp(j, 0, (1 << m) - 1) if(dp[j]) dp[j | a[i]] = 1;
        }
        ll ans = 0;
        for(ll mask = 0; mask < (1 << m); ++mask) ans += dp[mask];
        cout << ans << '\n';
    }
}