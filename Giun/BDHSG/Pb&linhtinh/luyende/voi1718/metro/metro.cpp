#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void OF(const string f){
    freopen((f + ".inp").c_str(), "r", stdin);
    freopen((f + ".out").c_str(), "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, m, s, t, e;
vec(pp(pp(ll, ll), ll)) g[maxn];

void sub1(){
    vec(ll) dp(n + 1, LLONG_MAX);
    dp[s] = 0;
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    q.push({0, s});
    while(q.size()){
        ll u = q.top().second, cu = q.top().first;
        q.pop();
        if(dp[u] != cu) continue;
        for(auto i : g[u]){
            ll v = i.second, w = i.first.first + i.first.second;
            if(u == s) w = i.first.first;
            if(cu + w < dp[v]){
                dp[v] = cu + w;
                q.push({dp[v], v});
            }
        }
    } 
    cout << dp[t];
}

void sub(){
    vec(pp(ll, ll)) dp(n + 1, pp(ll, ll)(LLONG_MAX, LLONG_MAX));
    dp[s] = {0, 0};
    priority_queue<pp(pp(ll, ll), ll), vec(pp(pp(ll, ll), ll)), greater<pp(pp(ll, ll), ll)>> q;
    q.push({{0, 0}, s});
    while(q.size()){
        ll u = q.top().second, cu = q.top().first.first, last = q.top().first.second;
        q.pop();
        if(make_pair(cu, last) != dp[u]) continue;
        for(auto i : g[u]){
            ll v = i.second, cuv = i.first.first, id = i.first.second, nw = cu + cuv;
            if(u != s) nw += (e + 1) * id;
            else nw += e * id;
            if(nw < dp[v].first){
                dp[v] = {nw, id};
                q.push({dp[v], v});
            }
            else if(nw == dp[v].first && id < dp[v].second){
                dp[v].second = nw;
                q.push({dp[v], v});
            }
        }
    }
    cout << dp[t].first - e * dp[t].second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF("metro");
    cin >> n >> m >> s >> t >> e;
    lp(i, 1, m){
        ll u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({{c, i}, v});
        // g[v].push_back({{c, i}, u});
    }
    if(!e) sub1();
    else sub();
}