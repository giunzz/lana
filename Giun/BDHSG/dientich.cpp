#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "dientich"
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

cll mxn = 1e6 + 3;
ll n, ans = 0;
pp(ll, ll) a[mxn];
vec(pp(ll, ll)) b;

void init(){
    ll ma = 0;
    b.push_back({0, 0});
    lp(i, 1, n){
        if(a[i].second > ma){
            ans += a[i].first * (a[i].second - b.back().second);
            b.push_back(a[i]);
            ma = a[i].second;
        }
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n, greater<pp(ll, ll)>());
    init();
    cout << ans;
}