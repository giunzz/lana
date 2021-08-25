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

cll mxn = 2e3 + 7;
ll n, a[mxn], dp[mxn][mxn] = {{0}}, pos[mxn][mxn], t = 0;

ll sol(ll l, ll r){
    if(dp[l][r]) return dp[l][r];
    if(l == r){pos[l][l] = l; return 0;}
    ll &cur = dp[l][r], sum;
    sol(l, r - 1), sol(l + 1, r);
    lp(k, pos[l][r - 1], pos[l + 1][r]){
        if(k + 1 > r) break;
        sum = min(sol(l, k) + a[k] - a[l - 1], sol(k + 1, r) + a[r] - a[k]);
        if(sum > cur) cur = sum, pos[l][r] = k;
    }
    return cur;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) a[i] = a[i - 1] + read();
    cout << sol(1, n);
}