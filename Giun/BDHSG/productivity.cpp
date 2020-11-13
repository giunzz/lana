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
ll n, c[maxn][maxn] = {{0}}, d[maxn*2], dd[2*maxn];
vec(ll) a[2 * maxn];

bool visit(ll u, ll r){
    if(dd[u] != r) dd[u] = r;
    else return 0;
    for(ll v : a[u]){
        if(!d[v] || visit(v, r)){
            d[v] = u;
            return 1;
        }
    } 
    return 0;
}

bool check(){
    lp(i, 1, n * 2) d[i] = dd[i] = 0;
    lp(i, 1, n){
        if(!d[i] && !visit(i, i)) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    cin >> n;
    ll ma = 0;
    lp(i, 1, n){
        lp(j, 1, n){
            cin >> c[i][j];
            if(c[i][j] > ma) ma = c[i][j];
        }
    }
    ll l = 0, r = ma, ans;
    while(l <= r){
        ll mid = (l + r) / 2;
        lp(i, 1, n) a[i].clear(), a[i + n].clear();
        lp(i, 1, n) lp(j, 1, n) if(c[i][j] >= mid) 
            a[i].push_back(j + n), a[j + n].push_back(i);
        if(check()) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
}