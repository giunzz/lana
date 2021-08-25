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

#define point pp(pp(ll, ll), ll)
#define x first
#define y second

cll mxn = 1e5 + 7;
ll n;
point a[mxn];

bool ccw(point &a, point &b, point &c){
    return (b.x.x - a.x.x) * (c.x.y - b.x.y) - (b.x.y - a.x.y) * (c.x.x - b.x.x) < 0; // turn right
}

bool cpr(point &u, point &v){
    return ccw(v, a[1], u);
}

int main(){
    giuncute();
    cin >> n;
    lp(i, 1, n){
        a[i] = {{read(), read()}, i};
        if(i > 1 && a[i] < a[1]) swap(a[i], a[1]);
    }
    sort(a + 2, a + 1 + n, cpr);
    lp(i, 2, n){
        if(i - 2 == n - i){
            cout << a[1].second << ' ' << a[i].second;
            return 0;
        }
    }
}