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

cll mxn = 123, s = 0, t = 241;
ll n, c[mxn][mxn] = {{0}}, par[mxn] = {0}, l[mxn];

ll find_path(){
    queue<ll> q;
    q.push(s);
    lp(i, s, t) par[i] = -1;
    par[s] = s;
    l[s] = 1e18, l[t] = 0;
    while(q.size()){
        ll u = q.front();
        q.pop();
        lp(i, s, t){
            if(c[u][i] && par[i] == -1){
                par[i] = u;
                l[i] = min(l[u], c[u][i]);
                q.push(i);
            }
        }
    }
    return l[t];
}

void increase(ll cost){
    for(ll i = t; par[i] != i; i = par[i]) c[par[i]][i] -= cost, c[i][par[i]] += cost;
}

void sol(){
    cin >> n;
    memset(c, 0, sizeof c);
    lp(i, 1, 240) c[s][i] = c[i][t] = 1;
    lp(i, 1, n){
        ll u, v;
        cin >> u >> v;
        c[u][v + 120] = 1;
    }
    ll cost, ans = 0;
    while(cost = find_path()){
        cerr << cost << '\n'; 
        increase(cost);
        ans += cost;
    }
    cout << ans << '\n';
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}