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
const string tenfile = "chuot";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxmn = 1e3 + 7;
ll m, n, f[maxmn][maxmn], d[maxmn][maxmn], ans = -1;

void enter(){
    string s;
    lp(i, 1, m){
        cin >> s;
        reverse(s.begin(), s.end());
        lp(j, 1, n) {
            f[i][j] = s.back() - 48;
            s.pop_back();
        }
    }
}

ll bfs(ll x, ll y){
    pair<ll, ll> o = {x, y};
    queue<pp(ll, ll)> qu;
    qu.push(o);
    d[o.first][o.second] = 1;
    ll cnt = 0;
    while(!qu.empty()){
        o = qu.front();
        qu.pop();
        ++cnt;
        if(f[o.fi - 1][o.se] && !d[o.fi - 1][o.se]++) qu.push(make_pair(o.fi - 1, o.se));
        if(f[o.fi + 1][o.se] && !d[o.fi + 1][o.se]++) qu.push(make_pair(o.fi + 1, o.se));
        if(f[o.fi][o.se + 1] && !d[o.fi][o.se + 1]++) qu.push(make_pair(o.fi, o.se + 1));
        if(f[o.fi][o.se - 1] && !d[o.fi][o.se - 1]++) qu.push(make_pair(o.fi, o.se - 1));
    }
    return cnt;
}

ii main(){
    opt;
    file;
    cin >> m >> n;
    memset(f, 0, sizeof(f));
    enter();
    memset(d, 0, sizeof(d));
    lp(i, 1, m){
        lp(j, 1, n){
            if(!d[i][j] && f[i][j]){
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans;
}
