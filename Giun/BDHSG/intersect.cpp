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
#define segment pp(point, point)

int ccw(point &a, point &b, point &c){
    ll tmp = (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
    if(tmp < 0) return -1;
    else return tmp > 0;
}

void input(point &x){cin >> x.first >> x.second;}

segment a, b;

bool check(segment &u, segment &v){
    return ccw(u.first, u.second, v.first) != ccw(u.first, u.second, v.second);
}

int main(){
    giuncute();
    // #ifndef ONLINE_JUDGE
    // OF();
    // #endif
    EACHCASE{
        input(a.first); input(a.second); 
        input(b.first); input(b.second);
        if(check(a, b) && check(b, a)){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}