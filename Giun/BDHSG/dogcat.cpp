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
ll n, ans = 0;
point a[mxn];
vec(point) res;

int sign(ll &u){
    if(u < 0) return -1;
    else return u > 0;
}

int ccw(point &a, point &b, point &c){
    ll tmp = (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
    return sign(tmp);
}

bool cpr(point &u, point &v){
    int tmp = ccw(a[1], u, v);
    return tmp == -1 || (!tmp && (u.second < v.second || (u.second == v.second && u.first < v.first)));
}

point _vec(point u, point v){
    return {v.first - u.first, v.second - u.second};
}

bool check_vec(point a, point b){
    return (a.first ? sign(a.first) != sign(b.first) : sign(a.second) != sign(b.second));
}

bool check(point p){
    if(ccw(res[0], res[1], p) == 1) return 0;
    if(ccw(res[0], res.back(), p) == -1) return 0;
    if(!ccw(res[0], res[1], p)) return check_vec(_vec(p, res[0]), _vec(p, res[1]));
    if(!ccw(res[0], res.back(), p)) return check_vec(_vec(p, res[0]), _vec(p, res.back()));

    ll l = 1, r = res.size() - 1, mid, pos;
    while(l <= r){
        mid = (l + r) >> 1;
        if(ccw(res[0], res[mid], p) == -1) pos = mid, l = mid + 1;
        else r = mid - 1;
    }

    if(ccw(res[pos], res[pos + 1], p) == 1) return 0;
    else return 1; 
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
        if(a[i].second < a[1].second || (a[i].second == a[1].second && a[i].first < a[1].first)) 
            swap(a[i], a[1]);
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
    // for(auto i : res) cerr << i.first << ' ' << i.second << '\n';
    EACHCASE{
        ll x, y;
        cin >> x >> y;
        if(check({x, y})){
            ++ans;
            // cerr << x << ' ' << y << '\n';
        }
    }
    cout << ans << '\n';
}