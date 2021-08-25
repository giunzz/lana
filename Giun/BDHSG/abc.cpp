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

int ccw(point &a, point &b, point &c){
    ll tmp = (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
    if(tmp < 0) return -1;
    else return tmp > 0;
}

void input(point &x){cin >> x.first >> x.second;}

int sign(ll a){
    if(a < 0) return -1;
    else return a > 0;
}

point a, b, c;

bool check(point a, point b){
    return (a.first ? sign(a.first) != sign(b.first) : sign(a.second) != sign(b.second));
}

int main(){
    giuncute();
    // #ifndef ONLINE_JUDGE
    // OF();
    // #endif
    EACHCASE{
        input(a), input(b), input(c);
        if(!ccw(a, b, c) && check({a.first - c.first, a.second - c.second}, {b.first - c.first, b.second - c.second})){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}