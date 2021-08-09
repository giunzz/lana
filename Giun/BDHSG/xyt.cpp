#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "xyt"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e4 + 7;
ll n, m, a[mxn], ans = -1;

void upd(ll v){
    if(v <= m) ans = max(ans, v);
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll j, k;
    j = k = 0;
    lp(i, 1, n){
        upd(a[i]);
        for(; j < i - 1 && a[j + 1] + a[i] <= m; ++j);
        upd(a[i] + a[j]);
        for(; k < j - 1 && a[k + 1] + a[j] + a[i] <= m; ++k);
        upd(a[k] + a[j] + a[i]);
        if(!k || !j) continue;
        ll rest = m - a[i], p = k;
        lpd(q, j - 1, k){
            for(; p < q - 1 && a[p + 1] + a[q] <= rest; ++p);
            if(p >= q) break;
            upd(a[q] + a[p] + a[i]);
        }
    }
    cout << ans;
}