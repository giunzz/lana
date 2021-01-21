#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

cll maxm = 1e5 + 7;
ll n, m, f[maxm];

struct quang{
    ll u, v, w;
}g[maxm];

ll root(ll u){
    return ((f[u] < 0 ? u : root(f[u])));
}

bool ghep(quang& a){
    ll x, y;
    if((x = root(a.u)) ==  (y = root(a.v))) return 0;
    if(y < x) swap(x, y);
    f[x] += f[y];
    f[y] = x;
    return 1;
}

bool cpr(quang &x, quang &y){
    return x.w < y.w;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("f"".inp", "r", stdin);
    freopen("f"".out", "w", stdout);
    cin >> n >> m;
    lp(i, 1, m){
        cin >> g[i].u >> g[i].v >> g[i].w;
    }
    ll cnt = 0, tw = 0;
    sort(g + 1, g + 1 + m, cpr);
    lp(i, 1, n) f[i] = -1;
    lp(i, 1, m){
        if(ghep(g[i]) && cnt != n - 1){
            ++cnt;
            tw += g[i].w;
        }
    }
    cout << tw;
}