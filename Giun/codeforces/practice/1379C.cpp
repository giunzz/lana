#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
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

cll mxm = 1e5 + 7;
ll n, m, c[mxm];
pp(ll, ll) a[mxm], b[mxm];

void sol(){
    cin >> n >> m;
    lp(i, 1, m){
        cin >> a[i].first >> b[i].first;
        c[i] = a[i].first;
        a[i].second = b[i].second = i;
    }
    sort(a + 1, a + 1 + m, greater<pp(ll, ll)>());
    sort(b + 1, b + 1 + m, greater<pp(ll, ll)>());
    vec(bool) d(m + 2, 0);
    ll ans = 0, j = 0, sum = 0;
    lp(i, 1, m){
        while(a[j + 1].first >= b[i].first && j < m && n){
            ans = max(ans, sum += a[++j].first);
            d[a[j].second] = 1;
            --n;
        }
        if(!n) break;
        if(d[b[i].second]) ans = max(ans, sum + n * b[i].first);
        else ans = max(ans, sum + c[b[i].second] + (n - 1) * b[i].first);
    }
    cout << ans << '\n';
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}