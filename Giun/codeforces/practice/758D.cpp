#include <bits/stdc++.h>
#define ll unsigned long long
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

cll oo = 1e18;
ll n, dp[65][65], p[65], mx;
string s;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> s;
    p[1] = 1;
    lp(i, 2, 60){
        if(oo / (p[i] = p[i - 1] * n) < n){mx = i; break;}
    }
    // cerr << p[mx];
    lp(i, 0, 64) lp(j, 0, 64) dp[i][j] = oo;
    reverse(s.begin(), s.end());
    s = '0' + s;
    // cerr << s;
    dp[0][0] = 0;
    ll ans = 1e18;
    lp(i, 1, s.size() - 1) lp(j, 1, mx){
        ll num = 0;
        lpd(k, i, 1){
            num = num * 10 + s[k] - '0';
            if(num >= n || num * p[j] > oo) break;
            if(dp[k - 1][j - 1] > oo - p[j] * num) continue;
            // assert(p[j] * num <= oo);
            // if(p[j] * num > oo) cerr << p[j] * num << ' ' << j << '\n';
            // cerr << num << ' ';
            dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + p[j] * num);
            if(!num) break;
        }
        if(i == s.size() - 1) ans = min(dp[i][j], ans);
    }
    // cerr << dp[2][1];
    cout << ans;
}