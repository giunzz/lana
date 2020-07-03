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
#define filln(a, b) memset(a, b, sizeof(a))
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "lakes";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxmn = 57;
ll n, m, k, f[maxmn][maxmn], d[maxmn][maxmn], cnt;

void enter(){
    char c;
    lp(i, 1, n){
        lp(j, 1, m){
            cin >> c;
            if(c == '.') f[i][j] = 1;
            else f[i][j] = 0;
        }
    }
}

struct point{
    ll x, y;
};

bool bfs(ll q, ll p){
    bool ok = 1;
    point a = {q, p};
    queue<point> qu;
    qu.push(a);
    d[q][p] = 1;
    while(!qu.empty()){
        ++cnt;
        a = qu.front();
        qu.pop();
        if(!(a.x - 1) || (a.x + 1 > n) || !(a.y - 1) || (a.y + 1 > m)) ok = 0;
        if(!d[a.x + 1][a.y] && f[a.x + 1][a.y]) {
            point po = {a.x + 1, a.y};
            d[po.x][po.y] = 1;
            qu.push(po);
        }
        if(!d[a.x - 1][a.y] && f[a.x - 1][a.y]) {
            point po = {a.x - 1, a.y};
            d[po.x][po.y] = 1;
            qu.push(po);
        }
        if(!d[a.x][a.y + 1] && f[a.x][a.y + 1]) {
            point po = {a.x, a.y + 1};
            d[po.x][po.y] = 1;
            qu.push(po);
        }
        if(!d[a.x][a.y - 1] && f[a.x][a.y - 1]) {
            point po = {a.x, a.y - 1};
            d[po.x][po.y] = 1;
            qu.push(po);
        }
    }
    return ok;
}

vector <ll> ans;
ll ans1 = 0;

ii main(){
    opt;
    file;
    cin >> n >> m >> k;
    filln(f, 0);
    enter();
    memset(d, 0, sizeof(d));
    lp(i, 1, n){
        lp(j, 1, m){
            if(f[i][j] && !d[i][j]){
                cnt = 0;
                if(bfs(i, j)){
                    ans.push_back(cnt);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(),ans.end());
    while(ans.size() > k){
        ans1 += ans.back();
        ans.pop_back();
    }
    cout << ans1;
}
