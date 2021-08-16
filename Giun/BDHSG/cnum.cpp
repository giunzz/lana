#include <bits/stdc++.h>
#define ll int
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

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e7 + 2;
ll n, a[mxn], ans;

inline ll _min(ll &u, ll &v){
    return (u < v) ? u : v;
}

int main(){
    giuncute();
    OF();
    scanf("%d", &n);
    a[0] = 0;
    char c;
    lp(i, 1, n){
        scanf("%c", &c);
        while(c != '1' && c != '2') scanf("%c", &c);
        a[i] = a[i - 1] + (c - '1');
    }
    ans = min(a[n], n - a[n]);
    ll tmp;
    lp(i, 1, n - 1){
        ans = min(ans, a[i] + n - i - (a[n] - a[i]));
        // if(tmp == 2){
        //     dp[i][1] = _min(dp[i - 1][1], dp[i - 1][0]);
        //     dp[i][0] = dp[i - 1][0] + 1;
        // } else{
        //     dp[i][1] = _min(dp[i - 1][0], dp[i - 1][1]) + 1;
        //     dp[i][0] = dp[i - 1][0];
        // }
    }
    // cout << min(dp[n][0], dp[n][1]);
    printf("%d", ans);
}