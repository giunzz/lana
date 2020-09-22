#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define fname "f"
using namespace std;

void File(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(fname".inp", "r", stdin);
    freopen(fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, q, t[maxn * 4] = {0};

void down(ll id){
    t[id * 2] += t[id];
    t[id * 2 + 1] += t[id];
    t[id] = 0;
}

void upd(ll id, ll l, ll r, ll u, ll v, ll vl){
    if(l > v || r < u || l > r) return;
    if(u <= l && r <= v) t[id] += vl;
    else{
        // cerr << 1;
        down(id);
        ll mid = (l + r) / 2;
        upd(id * 2, l, mid, u, v, vl);
        upd(id * 2 + 1, mid + 1, r, u, v, vl);
    }
}

ll getp(ll id, ll l, ll r, ll p){
    if(l > p || r < p) return 0;
    if(l == r) return t[id];
    down(id);
    ll mid = (l + r)/2;
    return max(getp(id*2, l, mid, p), getp(id*2 + 1, mid + 1, r, p));
}

int main(){
    File();
    cin >> n >> q;
    ll l, r, vl;
    lp(i, 1, q){
        cin >> l >> r >> vl;
        upd(1, 1, n, l, r, vl);
        // cerr << t[1] << endl;
    }
    // cerr << t[8];
    cout << getp(1, 1, n, 3);
}