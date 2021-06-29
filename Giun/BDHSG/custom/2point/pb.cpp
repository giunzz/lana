#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "pb"
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

cll mxn = 1e6 + 7;
ll n;

struct t{
    ll ma = -1e18, mi = 1e18;
}x, y;

void pro(t &a, ll v){
    a.ma = max(a.ma, v);
    a.mi = min(a.mi, v);
}

int main(){
    giuncute();
    // #ifndef ONLINE_JUDGE
    // OF();
    // #endif
    cin >> n;
    ll x_tmp, y_tmp;
    lp(i, 1, n){
        cin >> x_tmp >> y_tmp;
        if(!y_tmp)
            pro(x, x_tmp);
        if(!x_tmp)
            pro(y, y_tmp);
    }
    cout << max({
        x.ma - x.mi, 
        y.ma - y.mi, 
        (ll)sqrt(x.ma * x.ma + y.ma * y.ma),
        (ll)sqrt(x.ma * x.ma + y.mi * y.mi),
        (ll)sqrt(x.mi * x.mi + y.ma * y.ma),
        (ll)sqrt(x.mi * x.mi + y.mi * y.mi)
    });
}