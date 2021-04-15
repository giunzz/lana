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

cll mxn = 203, inf = -1e9;
ll a[256] = {0}, dp[4][mxn][mxn][mxn]; //ccccccc[i, j) d bong c
string s;

inline ll cal_dp(ll col, ll num, ll i, ll j){
    ll &cur = dp[col][num][i][j];
    if(~cur) return cur;
    if(i == j){
        if(num == 1) return cur = inf;
        return cur = num * num;
    } 
    if(col == a[s[i]]) return cur = cal_dp(col, num + 1, i + 1, j);
    cur = inf;
    lp(k, i + 1, j) cur = max(cur, cal_dp(a[s[i]], 1, i + 1, k) + cal_dp(col, num, k, j));
    return cur; 
}

void sol(){
    cin >> s;
    lp(i, 0, s.size()) lp(j, 0, s.size()) lp(num, 0, s.size()) lp(k, 0, 3) dp[k][num][i][j] = -1; 
    cout << max(cal_dp(a[s[0]], 1, 1, s.size()), 0LL) << '\n';
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    a['R'] = 0, a['B'] = 1, a['G'] = 2, a['Y'] = 3;
    EACHCASE sol();
}