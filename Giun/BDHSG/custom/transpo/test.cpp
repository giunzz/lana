#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "transpo"
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

cll mxn = 1e5 + 7;
ll n, m, vl, test = 0, cntu = 0;;
vec(pp(ll, ll)) g[mxn];
vec(bool) d;

void dfs(ll u){
    if(test == 3) ++ cntu;
    // if (test == 3) cerr << u << ' '; //18783, 49065
    for(pp(ll, ll) &v : g[u]){
        if(!d[v.first] && v.second >= vl){
            d[v.first] = 1;
            dfs(v.first);
        }
    }
}

bool check(){
    d.assign(n + 1, 0);
    d[1] = 1; ++test;
    dfs(1);
    d.clear();
    return d[n];
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    map<pp(ll, ll), ll> cnt;
    lp(i, 1, m){
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        if(cnt[make_pair(u, v)] || u == v || w > 1e9 || w < 1 || u > n || v > n || u < 1 || v < 1) cout << "NGU";
        cnt[make_pair(u, v)] = 1, cnt[make_pair(v, u)] = 1;
    }
    // cerr << g[18783].size();
    // for(pp(ll, ll) v : g[92292]) cerr << v.first << ' ' << v.second << '\n';
    ll ans = 0, l = 1, r = 1e9;
    while(l <= r){
        ll mid = (l + r) >> 1;
        vl = mid;
        // cerr << test << ' ';
        if(check()){
            ans = mid, l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
}