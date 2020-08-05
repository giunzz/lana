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
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "tracfficn";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e3 + 7, maxk = 307;
ll n, m, k, s, t, ans = 0, f[maxn] = {0}, ds[maxn] = {0};
vec(pp(ll, ll)) g[maxn];

struct strgk{
    ll u, w, v;
}gk[maxk];

void ent(){
    ll u, v, w;
    lp(i, 1, m){
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        // tt[u][v] = w;
    }
    lp(i, 1, k){
        cin >> u >> v >> w;
        gk[i] = {u, w, v};
    }
}

void dk1(ll r, ll res[]){
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    lp(i, 1, n) 
        if(i != r) {
            res[i] = INT_MAX;
            q.push({res[i], i});
    }
    ll u;
    pp(ll, ll) tmp;
    while(!q.empty()){
        tmp = q.top();
        q.pop();
        u = tmp.se;
        for(pp(ll, ll) v : g[u])
            res[v.se] = min(res[v.se], res[u] + v.fi);
    }
}

void dk(ll r, ll &x){
    ll res[maxn] = {0};
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    lp(i, 1, n) {
        if(i != r) res[i] = INT_MAX;
        q.push({res[i], i});
    }
    ll u;
    pp(ll, ll) tmp;
    while(!q.empty()){
        tmp = q.top();
        q.pop();
        u = tmp.se;
        if(u == t) break;
        for(pp(ll, ll) v : g[u])
            res[v.se] = min(res[v.se], res[u] + v.fi);
    }
    x = res[t];
}

ii main(){
    opt;
    file;
    cin >> n >> m >> k >> s >> t;
    ent();
    lp(i, 1, n)
        if(i != t) dk(i, f[i]);
    dk1(s, ds);
    ll dd[2], ans = ds[t];
    cerr << ans;
    lp(i, 1, k){
        dd[1] = ds[gk[i].u] + f[gk[i].v] + gk[i].w;
        dd[0] = ds[gk[i].v] + f[gk[i].u] + gk[i].w;
        ans = min(ans, min(dd[1], dd[0]));
    }
    if(ans==INT_MAX) cout << "-1";
    else cout << ans;
}


// #include <bits/stdc++.h>
// #define ii int
// #define ll long long
// #define cii const int
// #define cll const long long
// #define opt ios_base::sync_with_stdio(0); cin.tie(0)
// #define lp(a, b, c) for(ll a = b; a <= c; a++)
// #define lpd(a, b, c) for(ll a = b; a >= c; a--)
// #define pp(a, b) pair<a, b>
// #define vec(a) vector<a>
// #define vecite(a) vector<a>::iterator
// #define fi first
// #define se second
// #define mp(a, b) map<a, b>
// #define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
// #define st(a) system((a).c_str());
// using namespace std;
// cll MOD = 1e9 + 7;
// const double esf = 1e-9;
// const string tenfile = "tracfficn";
// #define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

// cll maxn = 1e3 + 7, maxk = 307;
// ll n, m, k, s, t, ds[maxn] = {0}, dt[maxn] = {0}, ans = 0;
// vec(pp(ll, ll)) g[maxn];

// struct strgk{
//     ll u, w, v;
// }gk[maxk];

// void ent(){
//     ll u, v, w;
//     lp(i, 1, m){
//         cin >> u >> v >> w;
//         g[u].push_back({w, v});
//     }
//     lp(i, 1, k){
//         cin >> u >> v >> w;
//         gk[i] = {u, w, v};
//     }
// }

// void dk(ll r, ll res[]){
//     lp(i, 1, n) if(i != r) res[i] = INT_MAX;
//     bool fr[maxn] = {0};
//     ll u, ts;
//     while(1){
//         u = 0, ts = INT_MAX;
//         lp(i, 1, n)
//             if(!fr[i] and ts > res[i]) u = i, ts = res[i];
//         if(!u) break;
//         fr[u] = 1;
//         for(pp(ll, ll) v : g[u])
//             res[v.se] = min(res[v.se], res[u] + v.fi);
//     }
// }

// ii main(){
//     opt;
//     file;
//     cin >> n >> m >> k >> s >> t;
//     ent();
//     dk(s, ds);
//     dk(t, dt);
//     ll dd[2];
//     ans = ds[t];
//     lp(i, 1, k){
//         dd[0] = ds[gk[i].u] + dt[gk[i].v] + gk[i].w;
//         dd[1] = ds[gk[i].v] + dt[gk[i].u] + gk[i].w;
//         ans = min(ans, min(dd[1], dd[0]));
//     }
//     if(ans==INT_MAX) cout << "-1";
//     else cout << ans;
// }
