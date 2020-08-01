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
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll maxn = 1e5 + 7, maxk = 107;
ll n, m, k, s, a[maxn] = {0};
vec(ll) g[maxn];

void ent(){
    ll u, v;
    lp(i, 1, m){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

ll bfs(ll r){
    bool ok = 1;
    ll u, d[maxn] = {0}, last, dh[maxk] = {0}, cnt = s - 1, ans = 0;
    queue<ll> q;
    q.push(r);
    d[r] = -1, dh[a[r]] = 1;
    while(!q.empty() && ok){
        u = q.front(), last = (d[u] + 1) ? d[u] : 0;
        q.pop();
        for(ll v : g[u]){
            if(!d[v]){
                q.push(v);
                d[v] = last + 1;
                if(!dh[a[v]]) --cnt, dh[a[v]] = 1, ans += d[v]; 
            }
            if(!cnt) {ok = 0; break;}
        }
    }
    return ans;
}

int main(){
    opt;
    file;
    cin >> n >> m >> k >> s;
    lp(i, 1, n) cin >> a[i];
    ent();
    lp(i, 1, n){
        ll ans = bfs(i);
        cout << ans << " ";
    }
}
