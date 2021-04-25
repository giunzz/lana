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

cll mxn = 57;
ll n, m;
vec(pp(ll, double)) g[mxn], in[mxn], t[mxn];

double sol(ll r){
    lp(i, 1, n) t[i] = g[i];
    for(pp(ll, ll) i : in[r]){
        t[i.first].push_back({n + 1, i.second});
    }
    vec(double) dp(n + 2, 1e9);
    priority_queue<pp(double, pp(ll, double)), vec(pp(double, pp(ll, double))), greater<pp(double, pp(ll, double))>> q;
    q.push({0, {r, 1}});
    dp[r] = 0;
    while(q.size()){
        ll u = q.top().second.first;
        double cu = q.top().first, vt = q.top().second.second;
        q.pop();
        if(cu != dp[u]) continue;
        for(auto v : t[u]){
            if(dp[v.first] > dp[u] + v.second * 1.0 / vt) dp[v.first] = dp[u] + v.second * 1.0 / vt, q.push({dp[v.first], {v.first, vt + 1}});
        }
    }
    return dp[n + 1];
}

#define ONLINE_JUDGE
int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, m){
        ll u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        in[v].push_back({u, c});
    }
    double ans = 1e9;
    lp(i, 1, n){
        double res = sol(i);
        ans = min(res, ans);

    }
    cout << (ans == 1e9 ? -1 : ans) << '\n';
}