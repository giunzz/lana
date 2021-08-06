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

#define point pp(ll, ll)

void inp(point &u){cin >> u.first >> u.second;}

ll getS(point &a, point &b, point &c){
    ll tmp = (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
    return tmp;
}

int ccw(point &a, point &b, point &c){
    ll tmp = (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
    if(tmp < 0) return -1;
    else return tmp > 0;
}

cll mxn = 1e3 + 7;
ll n, ans = 0; 
point a[mxn];
bool ok = 0;

int main(){
    giuncute();
    #ifdef PMQ
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) inp(a[i]);
    lp(i, 2, n - 1){
        if(ccw(a[i - 1], a[i], a[i + 1]) == 1) ok = 1;
        ans += getS(a[1], a[i], a[i + 1]);
    }
    ans = abs(ans);
    cout << (ok ? "CCW" : "CW") << ' ' << ans / 2 << '.' << (ans & 1) * 5 << '\n';
}