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
const string tenfile = "nop";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
ll n, res[maxn] = {0}, p[maxn], pre[maxn] = {0};
bool d[maxn] = {0};
vec(ll) a[maxn];

void init(){
    ll tmp;
    lp(i, 1, n){
        cin >> tmp;
        p[i] = tmp;
        if(i - tmp > 0){
            a[i].push_back(i - tmp);
            // cerr << i << ' ' << i - tmp << '\n';
        } 
        if(i + tmp <= n){
            a[i].push_back(i + tmp);
            // cerr << i << ' ' << i + tmp << '\n';
        }
        if(a[i].empty()) res[i] = -1;
    }
}

void bfs(ll r){
    // bool ok = 0;
    // ll tmp = LLONG_MAX;
    // for(ll &v : a[u]){
    //     if((p[v] & 1) ^ (p[u] & 1)) {d[v] = 1; res[u] = 1; return;}
    // }
    // for(ll &v : a[u]){
    //     if(d[v]) continue;
    //     d[v] = 1;
    //     if(res[v] != -1) ok = 1;
    //     if(res[v] > 0) tmp = min(tmp, res[v]);  
    //     else{
    //         dfs(v); 
    //         if(res[v] != -1) tmp = min(tmp, res[v]), ok = 1;
    //     }
    // }
    // // cerr << u << ' ' << tmp << ' ' << ok << '\n';
    // if(ok){
    //     res[u] = tmp + 1;
    // }
    // else res[u] = -1;
    queue<ll> q;
    q.push(r);
    d[r] = 1;
    while(q.size()){
        // cerr << 1;
        ll u = q.front();
        q.pop();
        // cerr << 1;
        if(res[u] == -1) continue;
        for(ll v : a[u]){
            if(d[v]) continue;
            d[v] = 1;
            if((p[v] & 1) ^ (p[u] & 1)){
                res[u] = 1;
                ll j = u, tmp = 1;
                // cerr << 1;
                while(j) {if(((p[v] & 1) ^ (p[j] & 1)) && res[j] > tmp) res[j] = tmp; j = pre[j], ++tmp;}
                // cerr << 1;
            }
            pre[v] = u;
            if(res[v] == -1) res[u] = -1;
            else q.push(v);
        }
    }
}

int main(){
    opt;
    file;
    cin >> n;
    init();
    lp(i, 1, n){
        if(!res[i]) bfs(i);
        cout << res[i] << ' ';
    }
}
