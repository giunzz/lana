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

struct quang{
    ll x, y, id;
};

cll maxn = 1e5 + 7;
ll n, f[maxn], ans = 0;
vec(ll) tv[maxn];
vec(vec(ll)) res;
quang a[maxn];

inline bool cpr(quang const &q, quang const &p){
    return (q.x < p.x || (q.x == p.x && q.y < p.y));
}

void compress(){
    set<ll> cp;
    cp.insert(0);
    lp(i, 1, n){
        cp.insert(a[i].y);
    }
    vec(ll) tmp(cp.begin(), cp.end());
    lp(i, 1, n){
        a[i].y = lower_bound(tmp.begin(), tmp.end(), a[i].y) - tmp.begin();
    }
}

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int n): n(n), f(n+2, 0) {}
    void set(int x, int i) {
        for (; i<=n; i += i&(-i)) f[i] = max(f[i], x);
    }
    int get(int i) const {
        int r = 0;
        for (; i>=1; i -= i&(-i)) r = max(r, f[i]);
        return r;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cpr);
    compress();
    Fenwick bit(n);
    lp(i, 1, n){
        f[i] = bit.get(a[i].y - 1) + 1;
        // cerr << a[i].y << ' ' << f[i] << '\n';
        ans = max(ans, f[i]);
        bit.set(f[i], a[i].y);
        tv[f[i]].push_back(a[i].id);
    }
    // cerr << tv[3].size();
    lpd(i, ans, 1){
        // if(!res.back().empty()) res.push_back(vec(ll)());
        while(tv[i].size()) {
            res.push_back(vec(ll)());
            lpd(j, i, 1){
                if(tv[j].size()){
                    res.back().push_back(tv[j].back());
                    tv[j].pop_back();
                }
            }
            if(res.back().empty()) res.pop_back();  
            // res.push_back(vec(ll)());
        }
    }
    cout << res.size() << '\n';
    for(auto v : res){
        cout << v.size() << ' ';
        for(auto r : v) cout << r << ' ';
        cout << '\n';
    }
}