#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 2e3 + 7;
ll n, q, X, Y, f[maxn], ttg;
double res[maxn];
pp(ll, ll) a[maxn], qr[maxn];
vec(pp(ll, ll)) g[maxn];
vec(pp(ll, pp(ll, ll))) e;
map<ll, ll> mp;

#define x first
#define y second
#define fi first
#define se second.first
#define th second.second

ll Get(ll u){
    if(f[u] < 0) return u;
    return Get(f[u]);
}

bool join(ll u, ll v){
    ll tu = Get(u), tv = Get(v);
    if(tu == tv) return 0;
    if(f[tu] > f[tv]) swap(tu, tv);
    f[tu] += f[tv];
    f[tv] = tu;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> q;
    lp(i, 1, n){
        f[i] = -1;
        cin >> a[i].x >> a[i].y;
    }
    ll cnt = 0;
    lp(i, 1, n){
        lp(j, i + 1, n){
            ll tmp = (a[j].x - a[i].x) * (a[j].x - a[i].x) + (a[j].y - a[i].y) * (a[j].y - a[i].y);
            // g[i].push_back({tmp, j});
            // g[j].push_back({tmp, i});
            e.push_back({tmp, {i, j}});
        }
    }
    // lp(i, 1, n){
    //     sort(g[i].begin(), g[i].end());
    // }
    sort(e.begin(), e.end());
    lp(i, 1, q){
        cin >> qr[i].x >> qr[i].y;
        res[i] = qr[i].y * (n - 1);
    }
    ll i = 0;
    while(i < e.size() && cnt != n - 1){
        ll tmp = e[i].first;
        while(i < e.size() && e[i].first == tmp && cnt != n - 1){
            if(join(e[i].second.first, e[i].second.second)) ++cnt;
            ++i;
        }
        ll tmp1 = 0, tmp2 = 0;
        lp(i, 1, n){
            if(f[i] == -1) ++tmp1;
            else if(f[i] < 1) ++tmp2;
        }   
        lp(i, 1, q){
            res[i] = min(qr[i].x * sqrt(tmp) + qr[i].y * (tmp1 + tmp2 - 1), res[i]);
        }
    }
    lp(i, 1, q){
        cout << setprecision(10) << fixed << res[i] << '\n';
    }
}