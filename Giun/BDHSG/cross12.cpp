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

cll mxn = 1e4 + 7, mxm = 1e5 + 7, mxr = 107;
ll n, m, a[mxn], nxt[mxm] = {0}, tot[mxr] = {0}, dp[mxn] = {0};
string s;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, n) cin >> a[i];
    cin >> s;
    s = '0' + s + '0';
    lpd(i, m, 0){
        if(s[i + 1] == '0') nxt[i] = i + 1;
        else nxt[i] = nxt[i + 1];
    }
    lp(i, 1, 100){
        ll step = i, j = 0;
        while(j <= m){
            if(nxt[j] - j <= step) step -= (nxt[j] - j);
            // else if(nxt[j] - j == step) step = i, ++tot[i];
            else if(i >= nxt[j] - j) step = i - (nxt[j] - j), ++tot[i];
            else {tot[i] = 1e17; break;}
            if(!step) ++tot[i], step = i;
            j = nxt[j];
        }
        if(step - i) ++tot[i];
    }
    sort(a + 1, a + 1 + n);
    dp[1] = tot[a[1]] + tot[a[n]]; 
    lp(i, 2, n - 1){
        dp[i] = min(dp[i - 1] + tot[a[i]] + tot[a[n]], dp[i - 2] + 2 * tot[a[n - 1]] + tot[a[n]] + tot[a[i - 1]]);
    }
    if(n == 1){
        cout << tot[a[1]];
        return 0;
    }
    dp[n] = min(dp[n - 1] - tot[a[n]], dp[n - 2] + tot[a[n - 1]]);
    cout << dp[n];
}