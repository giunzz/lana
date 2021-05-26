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

cll mxn = 1e4 + 7;
ll n, ans = 0;
point a[mxn], p, b[mxn];

inline void change(point &a){
    if(a.y < 0 or (a.y == 0 && a.x < 0)) a = {-a.x, -a.y};
}

// (x, 0)

inline bool cmp(point &a, point &b){
    return a.x * b.y > b.x * a.y;
}

inline bool cmpeq(point &a, point &b){
    return a.x * b.y == b.x * a.y;
}

// ax + by + c = 0 => y = -(ax + c)/b = -ax/b - c / b

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> b[i].x >> b[i].y;
    lp(i, 1, n){
        p = b[i];
        lp(j, i + 1, n){a[j] = {b[j].x - p.x, b[j].y - p.y}; change(a[j]);}
        sort(a + i + 1, a + 1 + n, cmp);
        ll k = i + 1;
        lp(j, i + 2, n){
            if(!cmpeq(a[j], a[k])){
                ans += (j - k) * (j - k - 1) / 2;
                k = j;
            }
        }
        ans += (n - k) * (n - k + 1) / 2;
    }
    cout << ans;
}

//n! = (n - 2)! * (n - 1) *  n

// c(n, 2) = n * (n - 1) / 2

// p24 = 24 ^ (mod - 2)
// c(n, 4) = n * (n - 1) * (n - 2) * (n - 3) * p24;

// (a / b) % MOD voi MOD la snt = (a * b ^ (MOD - 2)) % MOD;