#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "phanthuong"
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

cll MOD = 1e9 + 7, mxn = 1e5 + 7, mxk = 52;
ll n, k, a[mxn], c[mxn][mxk] = {{0}}, ans = 0;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i];    
    sort(a + 1, a + 1 + n);
    lp(i, 0, n) c[i][0] = 1;
    lp(i, 1, n) lp(j, 1, k) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    lpd(i, n, 1){
        if(i == k - 1) break;
        (ans += (a[i] * c[i - 1][k - 1]) % MOD) %= MOD;
    }
    cout << ans;
}