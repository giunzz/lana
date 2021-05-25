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
#define x first
#define y second

cll mxn = 2e3 + 7;
ll n, ans = 0;
point a[mxn], p;

inline void change(point &a){
    if(a.y < 0 or (!a.y && a.x < 0)) a = {-a.x, -a.y};
}

bool cmp(point a, point b){
    a = {a.x - p.x, a.y - p.y};
    b = {b.x - p.x, b.y - p.y};
    change(a);
    change(b);
    // if(!(a.x | a.y)) return 1;
    // else if(!(b.x | b.y)) return 0;
    return a.x * b.y >= b.x * a.y;
}

bool cmpeq(point a, point b){
    a = {a.x - p.x, a.y - p.y};
    b = {b.x - p.x, b.y - p.y};
    // change(a);
    // change(b);
    return a.x * b.y == b.x * a.y;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].x >> a[i].y;
    }
    if(n == 1 || n == 2){
        cout << 0;
        return 0;
    }
    lp(i, 1, n){
        p = a[i];
        sort(a + 1, a + 1 + n, cmp);
        ll k = 2;
        // if(i == 1) lp(j, 1, n) cerr << a[j].x << ' ' << a[j].y << '\n';
        lp(j, 3, n){
            if(!cmpeq(a[j], a[k])){
                ans += (j - k) * (j - k - 1) / 2;
                k = j;
            }
            else if(a[j] == p || a[k] == p) ++k;
        }
        ans += (n - k) * (n - k + 1) / 2;
        // cerr << ans << ' ';
    }
    // cerr << ans;
    cout << ans / 3;
}