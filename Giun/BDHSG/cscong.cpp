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

cll mxn = 3e3 + 2;
ll n, a[mxn], dp[mxn][mxn] = {{0}}, ans = 0;

int main(){
    giuncute();
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    lp(i, 1, n) lp(j, 1, i - 1){
        if(a[i] > a[j] && (dp[i][a[i] - a[j]] = dp[j][a[i] - a[j]] + 1) > ans) 
            ans = dp[i][a[i] - a[j]];
    }
    cout << ans + 1;
}