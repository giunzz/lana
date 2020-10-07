#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
using namespace std;

void file(const string s){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

cll maxn = 407;
ll n, res[maxn] = {0}, m;
bool ok = 0, d[maxn] = {0}, tmp[maxn];
vec(ll) g[maxn];

void init(){
    ll u, v;
    lp(i, 1, m){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(abs(u - v) + 1 == n) ok = 1;
    }
}

void bfs(){
    d[1] = 1;
    queue<ll> q;
    q.push(1);
    while(q.size()){
        memset(tmp, 0, sizeof(tmp));
        ll u = q.front();
        q.pop();
        for(ll v : g[u]){
            tmp[v] = 1;
        }
        lp(i, 1, n) {if(!d[i] && !tmp[i]) res[i] = res[u] + 1, d[i] = 1, q.push(i);}
    }
}

void bfs1(){
    d[1] = 1;
    queue<ll> q;
    q.push(1);
    while(q.size()){
        ll u = q.front();
        q.pop();
        for(ll v : g[u]){
            if(!d[v]){
                res[v] = res[u] + 1;
                q.push(v);
                d[v] = 1;
            }
        }
    }
}

int main(){
    file("f");
    cin >> n >> m;
    init();
    // cerr << ok;
    if(ok) {bfs();}
    else bfs1();
    // lp(i, 1, n) cerr << res[i] << ' ';
    cout << res[n];
}
