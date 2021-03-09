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
const string tenfile = "daotau";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll mxn = 1e6 + 7, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
unordered_map<ll, unordered_map<ll, ll>> mtx;
vec(ll) g[mxn];
pp(ll, ll) pos[mxn];
ll n, k, dp[mxn] = {0};
bool vst[mxn] = {0};

void init(){
    ll x = 0, y = 0, d = 0;
    lp(i, 1, 1e6){
        mtx[x][y] = i;
        pos[i] = {x, y};
        if(i != 1 && !mtx[x + dx[(d + 1) % 4]][y + dy[(d + 1) % 4]]) (++d) %= 4;
        x += dx[d], y += dy[d];
    }
}

int main(){
    opt;
    file;
    init();
    cin >> n >> k;
    lp(i, 1, k){
        ll u, x, y;
        cin >> u;
        x = pos[u].first, y = pos[u].second;
        lp(d, 0, 3){
            ll nx = x + dx[d], ny = y + dy[d];
            if(u - mtx[nx][ny] > 1) g[mtx[nx][ny]].push_back(u), g[u].push_back(mtx[nx][ny]);
        }
    }
    queue<ll> q;
    vst[0] = vst[1] = 1;
    q.push(1);
    while(q.size()){
        ll u = q.front();
        q.pop();
        if(u == n) break;
        if(!vst[u - 1] && u - 1 >= 1){
            q.push(u - 1);
            vst[u - 1] = 1;
            dp[u - 1] = dp[u] + 1;
        } 
        if(!vst[u + 1] && u + 1 <= 1e6){
            q.push(u + 1);
            vst[u + 1] = 1;
            dp[u + 1] = dp[u] + 1;
        }
        for(ll v : g[u]) if(!vst[v]){
            vst[v] = 1;
            q.push(v);
            dp[v] = dp[u] + 1;
        }
    }
    cout << dp[n];
}
