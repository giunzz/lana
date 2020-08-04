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
const string tenfile = "fairnt";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7, maxk = 107;
ll n, m, k, s, a[maxn] = {0}, f[maxn][maxk] = {{0}};
vec(ll) g[maxn], ans[maxn];

void fs(ll &number){ 
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar(); 
    if (c == ' ') fs(number);
    // if (c=='-') 
    // { 
    //     negative = true; 
    //     c = getchar(); 
    // } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
} 

void ent(){
    ll u, v;
    lp(i, 1, m){
        fs(u); fs(v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void bfs(ll lk){
    ll u, t[maxn] = {0}, last;
    queue<ll> q;
    lp(i, 1, n) if(a[i] == lk) q.push(i), t[i] = -1;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(ll v : g[u]){
            if(!t[v]){
                last = (t[u] + 1) ? t[u] : 0;
                f[v][lk] = last + 1; t[v] = f[v][lk];
                q.push(v);
                ans[v].push_back(f[v][lk]);
            }
        }
    }
}

ii main(){
    opt;
    file;
    fs(n); fs(m); fs(k); fs(s);
    lp(i, 1, n) {fs(a[i]);}
    ent();
    lp(i, 1, k){
        bfs(i);
    }
    ll sum;
    lp(i, 1, n){
        sum = 0;
        sort(ans[i].begin(), ans[i].end());
        lp(j, 0, s - 2) sum += ans[i][j];
        cout << sum << " ";
    }
    cerr << clock();
}
