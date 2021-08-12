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

cll mxn = 107;
ll n, m, s, t, ti[mxn] = {0}, res[mxn];
vec(pp(ll, ll)) g[mxn];

int main(){
    giuncute();
    cin >> n >> m >> s >> t;
    lp(i, 1, n){
        cin >> ti[i];
        if(!ti[i]) ti[i] = 1e18 + 7;
    }
    lp(i, 1, m){
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    q.push({0, s});
    lp(i, 1, n) res[i] = 1e18;
    res[s] = 0;
    ll v, uv;
    while(q.size()){
        ll su = q.top().first, u = q.top().second;
        q.pop();
        if(res[u] != su) continue;
        for(auto i : g[u]){
            v = i.first, uv = i.second;
            if(res[u] + uv < res[v] && res[u] + uv < ti[v]){
                res[v] = res[u] + uv;
                q.push({res[v], v});
            }
        }
    }
    cout << (res[t] >= 1e18 ? -1 : res[t]);
}