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

cll mxn = 1e4 + 7;
ll n, ans = 0;
point a[mxn];
unordered_map<ll, unordered_map<ll, ll>> mp;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].first >> a[i].second;
        lp(j, 1, i - 1){
            if(a[i] == a[j]) continue;
            point vt = {a[i].first - a[j].first, a[i].second - a[j].second};
            if(vt.first < 0) vt = {-vt.first, -vt.second};
            else if(!vt.first && vt.second < 0) vt.second = -vt.second;
            ll gcd = __gcd(abs(vt.first), abs(vt.second));
            vt = {vt.first / gcd, vt.second / gcd};
            point pt = {-vt.second, vt.first};
            if(pt.first < 0) pt = {-pt.first, -pt.second};
            else if(!pt.first && pt.second < 0) pt.second = -pt.second;
            ans += mp[pt.first][pt.second];
            ++mp[vt.first][vt.second];
            // if(i == 4 && j == 1) cerr << vt.first << ' ' << vt.second << '\n' << pt.first << ' ' << pt.second << '\n' << mp[0][-1];
        }
        // if(i == 2) cerr << ans;
    }
    cout << ans;
}