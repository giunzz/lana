#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "number1"
// #define Fname "f"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

string toS(ll u){
    string tmp;
    while(u) tmp.push_back(u % 10), u /= 10;
    return tmp;
}

ll bc(ll x, ll y){
    return x * y / __gcd(x, y);
}

void sol(){
    ll n, a = 1, cnt = 1;
    cin >> n;
    while(a % n){
        a = (a * 10 + 1) % n;
        ++cnt;
    }
    cout << cnt << '\n';
    // string sn = toS(n);
    // ll tg = 1;
    // if(n % 9 == 0) tg = bc(tg, 9);
    // else if(n % 7 == 0) tg = bc(tg, 6);
    // else tg = bc(tg, 3);
    // // cerr << tg << '\n';
    // cout << (sn.size() + tg - 1) / tg * tg << '\n';
    // cout << cnt << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}