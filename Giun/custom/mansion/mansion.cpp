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
const string tenfile = "mansion";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 2e5 + 7;
ll n, m, k;

struct quang{
    ll val, p;
    bool stt; //0 di doc, 1 di ngang
};
vec(quang) g[maxn];

struct quang1{
    ll first, second, index;
};

inline bool cpr(const quang1 &a, const quang1 &b){
    if(a.first < b.first) return true;
    if(a.first == b.first && a.second < b.second) return true;
    return false;
}

inline bool cpr1(const quang1 &a, const quang1 &b){
    if(a.second < b.second) return true;
    if(a.second == b.second && a.first < b.first) return true;
    return false;
}

void init(){
    ll x, y;
    vec(quang1) tmp;
    lp(i, 1, k) {scanf("%lld %lld", &x, &y); tmp.push_back({x, y, i});}
    tmp.push_back({1, 1, 0});
    tmp.push_back({m, n, k + 1});
    sort(tmp.begin(), tmp.end(), cpr);
    lp(i, 1, k + 1){
        if(tmp[i].first == tmp[i - 1].first) {
            g[tmp[i - 1].index].push_back({tmp[i].second - tmp[i - 1].second, tmp[i].index, 0});
            g[tmp[i].index].push_back({tmp[i].second - tmp[i - 1].second, tmp[i - 1].index, 0});
        }
    }
    // lp(i, 0, k + 1) cerr << tmp[i].first << ' ' << tmp[i].second << ' ' << tmp[i].index << '\n';
    sort(tmp.begin(), tmp.end(), cpr1);
    lp(i, 1, k + 1){
        if(tmp[i].second == tmp[i - 1].second) {
            g[tmp[i - 1].index].push_back({tmp[i].first - tmp[i - 1].first, tmp[i].index, 1});
            g[tmp[i].index].push_back({tmp[i].first - tmp[i - 1].first, tmp[i - 1].index, 1});
        }
    }
}

ll d[maxn] = {0}, c[maxn];

void dijkstra(){
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    lp(i, 1, k + 1) d[i] = INT_MAX, c[i] = -1;
    c[0] = 0;
    q.push({0, 0});
    ll u, wu;
    while(q.size()){
        u = q.top().second;
        wu = q.top().first;
        q.pop();
        if(wu != d[u]) continue;
        if(wu == d[u] && u == k + 1) break;
        for(quang v : g[u]){
            if((v.stt != c[u]) + d[u] + v.val < d[v.p]) {d[v.p] = (v.stt != c[u]) + d[u] + v.val, c[v.p] = ((v.stt != c[u]) ? v.stt : c[u]); q.push({d[v.p], v.p});} 
        }
    }
    if(d[k + 1] == INT_MAX) cout << -1;
    else cout << d[k + 1];
}

int main(){
    // opt;
    file;
    scanf("%lld %lld %lld", &m, &n, &k);
    init();
    dijkstra();
    // cerr << clock() << '\n';
}
