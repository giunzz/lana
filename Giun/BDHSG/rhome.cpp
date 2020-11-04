#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "rhome"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxm = 1e5 + 7;
ll n, m, f[maxm];
pp(ll, pp(ll, ll)) a[maxm];
vec(pp(ll, ll)) g[maxm];

#define x first
#define y second.first
#define z second.second

bool cpr1(pp(ll, pp(ll, ll)) &q, pp(ll, pp(ll, ll)) &p){
    return q.x < p.x || (q.x == p.x && q.y < p.y);
}

bool cpr2(pp(ll, pp(ll, ll)) &q, pp(ll, pp(ll, ll)) &p){
    return q.y < p.y || (q.y == p.y && q.x < p.x);
}

void dijkstra(ll const &r){
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    lp(i, 1, m + 1) f[i] = LLONG_MAX;
    f[r] = 0;
    q.push({0, r});
    while(q.size()){
        ll u = q.top().second;
        ll cu = q.top().first;
        q.pop();
        if(f[u] != cu) continue;
        for(pp(ll, ll) &v : g[u]){
            if(f[v.second] > f[u] + v.first){
                f[v.second] = f[u] + v.first;
                q.push({f[v.second], v.second});
            }
        } 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m;
    cin >> a[0].x >> a[0].y >> a[m + 1].x >> a[m + 1].y;
    a[0].z = 0, a[m + 1].z = m + 1;
    lp(i, 1, m){
        cin >> a[i].x >> a[i].y;
        a[i].z = i;
    }
    sort(a, a + 2 + m, cpr1);
    lp(i, 1, m + 1){
        g[a[i].z].push_back({a[i].x - a[i - 1].x, a[i - 1].z});
        g[a[i - 1].z].push_back({a[i].x - a[i - 1].x, a[i].z});
    }
    // g[a[1].z].push_back({abs(a[1].x - a[0].x) + abs(a[1].y - a[0].y), 0});
    // g[0].push_back({abs(a[1].x - a[0].x) + abs(a[1].y - a[0].y), a[1].z});
    // g[a[m].z].push_back({abs(a[m].x - a[m + 1].x) + abs(a[m].y - a[m + 1].y), m + 1});
    // g[m + 1].push_back({abs(a[m].x - a[m + 1].x) + abs(a[m].y - a[m + 1].y), a[m].z});
    sort(a, a + 2 + m, cpr2);
    lp(i, 1, m + 1){
        g[a[i].z].push_back({a[i].y - a[i - 1].y, a[i - 1].z});
        g[a[i - 1].z].push_back({a[i].y - a[i - 1].y, a[i].z});
    }
    // g[a[1].z].push_back({abs(a[1].x - a[0].x) + abs(a[1].y - a[0].y), 0});
    // g[0].push_back({abs(a[1].x - a[0].x) + abs(a[1].y - a[0].y), a[1].z});
    // g[a[m].z].push_back({abs(a[m].x - a[m + 1].x) + abs(a[m].y - a[m + 1].y), m + 1});
    // g[m + 1].push_back({abs(a[m].x - a[m + 1].x) + abs(a[m].y - a[m + 1].y), a[m].z});
    // lp(u, 0, m + 1)
    //     for(pp(ll, ll) &v : g[u])
    //         cerr << u << ' ' << v.second << ' ' << v.first << '\n';
    dijkstra(0LL);
    cout << f[m + 1];
}