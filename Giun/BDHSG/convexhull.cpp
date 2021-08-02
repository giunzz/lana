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

cll mxn = 1e5 + 6;
ll n;
point a[mxn];
vec(point) res;

int ccw(point &a, point &b, point &c){
    ll tmp = (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
    if(tmp < 0) return -1;
    else return tmp > 0;
}

bool cpr(point &u, point &v){
    int tmp = ccw(a[1], u, v);
    return tmp == -1 || (!tmp && (u.second < v.second || (u.second == v.second && u.first < v.first)));
}

ll getS(point &a, point &b, point &c){
    ll tmp = (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
    return abs(tmp);
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    a[0] = {-1e18, -1e18};
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].first >> a[i].second;
        if(a[i].second < a[1].second || (a[i].second == a[1].second && a[i].first < a[1].first)) swap(a[i], a[1]);
    }
    sort(a + 2, a + 1 + n, cpr);
    lp(i, 1, n){
        if(a[i] == a[i - 1]) continue;
        if(res.size() < 2) res.push_back(a[i]);
        else{
            while(res.size() > 1 && ccw(res[res.size() - 2], res.back(), a[i]) != -1){
                res.pop_back();
            }
            res.push_back(a[i]);
        }
    }
    ll ans = 0;
    lp(i, 2, res.size() - 1) ans += getS(res[0], res[i - 1], res[i]);
    cout << res.size() << '\n';
    cout << ans / 2 << '.' << (ans & 1) * 5 << '\n';
    cout << res[0].first << ' ' << res[0].second << '\n';
    lpd(i, res.size() - 1, 1) cout << res[i].first << ' ' << res[i].second << '\n';
}