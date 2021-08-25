#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "POLYLINES"
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

cll mxn = 1e5 + 3;
ll n;
point a[mxn];

int ccw(point &a, point &b, point &c){
    ll val = (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
    if(val < 0) return -1;
    return val > 0;
}

bool cpr(point &u, point &v){
    ll val = ccw(a[0], u, v);
    return val == -1;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    a[0] = {0, 0};
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].first >> a[i].second;
        // if(a[i].first < a[1].first || (a[i].first == a[1].second && a[i].second < a[1].second)) swap(a[i], a[1]);
    }
    sort(a + 1, a + 1 + n, cpr);
    lp(i, 1, n) cout << a[i].first << ' ' << a[i].second << '\n';
}