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

cll mxn = 1e7 + 7;
ll snt[mxn] = {0}, dp[mxn] = {0};

void init(){
    snt[1] = 0;
    for(ll i = 2; i * i <= 1e7; ++i){
        if(!snt[i]){for(ll j = i * i; j <= 1e7; j += i) snt[j] = i;}
    }
    lp(i, 1, 1e7){
        if(snt[i] && !snt[i / snt[i]] && i / snt[i] != snt[i]) ++dp[i];
        if(snt[i] && snt[i] * snt[i] == i / snt[i]) ++dp[i];
        dp[i] += dp[i - 1]; 
    }
    // cerr << 1;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    init();
    EACHCASE{
        ll l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << '\n';
    }
}