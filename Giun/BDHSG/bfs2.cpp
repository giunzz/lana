#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
vec(ll) g[maxn];
ll n, m, d[maxn], t[maxn];

void bfs(ll r){
    ll u;
    memset(t, 0, sizeof(t));
    memset(d, 0, sizeof(d));
    d[r] = 1, t[r] = 0;
    queue<ll> qu;
    qu.push(r);
    while(!qu.empty()){
        u = qu.front();
        qu.pop();
        lp(i, 0, g[u].size() - 1){
            if(d[g[u][i]]) continue;
            d[g[u][i]] = d[u] + 1;
            t[g[u][i]] = u;
            qu.push(g[u][i]);
        }
    }
}

ll getg1(){
    ll u, tg = INT_MIN;
    lp(i, 1, n){
        if(tg < d[i]) tg = d[i], u = i;
    }
    return u;
}

ii main(){
    opt;
    file;
    cin >> n;
    ll u, v;
    lp(i, 1, n - 1){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    //lp(i, 1, n) cerr << d[i] << " ";
    //cerr << endl;
    ll x1 = getg1();
    //cerr << x1 << endl;
    bfs(x1);
    ll x2 = getg1();
    //cerr << x2 << endl;
    //lp(i, 1, n) cerr << d[i] << " ";
    cout << d[x2] << endl;
    if(d[x2] % 2){
        cout << 1 << endl;
        u = d[x2];
        lp(i, 1, d[x2] / 2){
            u = t[u];
        }
        cout << u;
    }
    else{
        cout << 2 << endl;
        u = d[x2];
        lp(i, 1, d[x2]/2 -1){
            u = t[u];
        }
        cout << u << " " << t[u];
    }
}
