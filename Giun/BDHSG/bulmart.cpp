#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 5e3 + 7, maxst = maxn, maxgt = 1e3 + 7;
ll n, m, gt, st, ans; //guest, store
bool d[maxn];
pp(ll, pp(ll, ll)) agt[maxn], ast[maxn];
vec(ll) g[maxn];

#define pos first

#define slc second.first
#define gi second.second

#define nc second.first
#define tt second.second

bool cpr(pp(ll, pp(ll, ll)) const &x, pp(ll, pp(ll, ll)) const &y){
    return (x.gi < y.gi);
}

void bfs(ll r){
    ans = 0;
    queue<ll> q;
    q.push(r);
    while(q.size()){
        ll u = q.front();
        q.pop();
        for(ll v : g[u]){
            if(d[v]) continue;
            d[v] = 1;
            q.push(v);
        }
    }
}

void init(){
    cin >> n >> m;
    ll u, v;
    lp(i, 1, m){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> st;
    lp(i, 1, st){
        cin >> ast[i].pos >> ast[i].slc >> ast[i].gi;
    }
    sort(a + 1, a + 1 + n, cpr);
    cin >> gt;
    lp(i, 1, gt){
        memset(d, 0, sizeof(d));
        cin >> agt[i].pos >> agt[i].nc >> agt[i].tt;
        d[agt[i].pos] = 1;
        bfs(agt[i].pos);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
}

//vo bfs hoac cnp tim khoang cach loc cac cua hang trong khoang cach