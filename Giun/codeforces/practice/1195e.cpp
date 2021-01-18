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

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll n, m, _a, _b, g0, x, y, mod;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> _a >> _b >> g0 >> x >> y >> mod;
    vec(vec(ll)) adj(n + 1, vec(ll)(m + 1));
    lp(i, 1, n) lp(j, 1, m) adj[i][j] = g0, g0 = (g0 * x + y) % mod;
    // lp(i, 1, n){
    //     lp(j, 1, m) cerr << adj[i][j] << ' ';
    //     cerr << '\n';
    // }
    deque<pp(ll, ll)> q;
    lp(i, 1, n){
        q.clear();
        lp(j, 1, m){
            while(q.size() && q.front().first <= j - _b) q.pop_front();
            while(q.size() && q.back().second >= adj[i][j]) q.pop_back();
            q.push_back({j, adj[i][j]});
            adj[i][j] = q.front().second;
        }
    }
    lp(j, 1, m){
        q.clear();
        lp(i, 1, n){
            while(q.size() && q.front().first <= i - _a) q.pop_front();
            while(q.size() && q.back().second >= adj[i][j]) q.pop_back();
            q.push_back({i, adj[i][j]});
            adj[i][j] = q.front().second;
        }
    }
    ll ans = 0;
    lp(i, _a, n) lp(j, _b, m) ans += adj[i][j];
    cout << ans;
}