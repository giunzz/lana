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
ll n, m, k, s, t, f[maxn][maxn] = {{0}};

struct strgk{
    ll u, v, w;
}gk[maxk];

void ent(){
    ll u, v, w;
    cin >> n >> m >> k >> s >> t;
    lp(i, 1, m){
        cin >> u >> v >> w;
        f[u][v] = w;
    }
    lp(i, 1, k){
        cin >> u >> v >> w;
        gk[i] = {u, v, w};
    }
}

ll res[maxn] = {0};

ll dk(ll r, ll q){
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> qu;
    lp(i, 1, n) res[i] = INT_MAX; res[r] = 0;
    ll u;
    pp(ll, ll) tmp;
    qu.push({0, r});
    while(!qu.empty()){
        tmp = qu.top(), u = tmp.se;
        qu.pop();
        if(res[u] == tmp.fi && u == q) break;
        if(res[u] != tmp.fi) continue;
        lp(i, 1, n)
            if(f[u][i] && res[i] > res[u] + f[u][i]) res[i] = res[u] + f[u][i], qu.push({res[i], i});
    }
    return res[q];
}

int main(){
    opt;
    file;
    ent();
    ll ans = dk(s, t), tmp, tmp1;
    lp(i, 1, k){
        tmp = f[gk[i].u][gk[i].v], tmp1 = f[gk[i].v][gk[i].u];
        f[gk[i].u][gk[i].v] = gk[i].w, f[gk[i].v][gk[i].u] = gk[i].w;
        ans = min(ans, dk(s, t));
        f[gk[i].u][gk[i].v] = tmp, f[gk[i].v][gk[i].u] = tmp1;
    }
    if(ans == INT_MAX) cout << "-1";
    else cout << ans;
}