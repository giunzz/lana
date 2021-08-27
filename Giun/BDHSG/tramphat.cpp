#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "tramphat"
#define double long double
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

#define point pp(ll, ll)

const double esp = 1e-7;
cll mxn = 1e3 + 3;
ll n, ans = 0, par[mxn] = {0};
point p[mxn];

double dis(point &a, point &b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

ll _get(ll u){
    return par[u] = (par[u] == u ? u : _get(par[u]));
}

bool _join(ll u, ll v){
    u = _get(u), v = _get(v);
    if(u == v) return 0;
    par[v] = u;
    return 1;
}

bool check(double val){
    lp(i, 1, n) par[i] = i;
    ll tot = n;
    lp(i, 1, n) lp(j, 1, i - 1){
        if(sqrt(dis(p[i], p[j])) <= val) if(_join(i, j)) --tot;
    }
    return tot == 1;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> p[i].first >> p[i].second;
    };
    double l = 0, r = 1e9, ans;
    while(r - l >= esp){
        double mid = (l + r) / 2;
        if(check(mid * 2)) ans = mid, r = mid;
        else l = mid;
    }
    ans *= 1e7;
    ans = floor(ans);
    cout << fixed << setprecision(7) << ans / 1e7;
}