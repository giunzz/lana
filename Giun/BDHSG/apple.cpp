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

ll Sabc;
point a, b, c;

void inp(point &u){cin >> u.first >> u.second;}

ll getS(point &a, point &b, point &c){
    ll tmp = (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
    return abs(tmp);
}

bool check(point &u){
    return getS(a, b, u) + getS(b, c, u) + getS(a, c, u) == Sabc;
}

int main(){
    giuncute();
    #ifdef PMQ
    OF();
    #endif
    inp(a), inp(b), inp(c);
    Sabc = getS(a, b, c);
    ll ans = 0;
    EACHCASE{
        point p;
        inp(p);
        if(check(p)) ++ans;
    }
    cout << Sabc / 2 << '.' << (Sabc & 1) * 5 << '\n' << ans <<'\n';
}