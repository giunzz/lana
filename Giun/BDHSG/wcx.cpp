#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "5g"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll n;
vec(pp(ll, bool)) x;
// vec(pp(ll, ll)) x;
vec(pp(ll, ll)) ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    ll a, b;
    lp(i, 1, n){
        cin >> a >> b;
        x.push_back({a, 0});
        x.push_back({b, 1});
    }
    ll cnt = 0, c0 = 0, c1 = 0, d;
    bool stt = 0;
    sort(x.begin(), x.end());
    for(pp(ll, bool) &w : x){
        if(stt){
            if(w.second) ++c1;
            else ++c0;
            if(c1 == c0) ans.push_back({d, w.first}), c1 = 0, c0 = 0, stt = 0;
        } else{
            d = w.first, ++c0, stt = 1;
        }
    }
    // lp(i, 1, n){
    //     cin >> a >> b;
    //     x.push_back({a, b});
    // }
    // sort(x.begin(), x.end());
    // ans.push_back(x[0]);
    // lp(i, 1, n - 1){
    //     if(ans.back().second >= x[i].first) ans.back().second = max(ans.back().second, x[i].second);
    //     else ans.push_back(x[i]);
    // }
    cout << ans.size() << '\n';
    for(pp(ll, ll) &w : ans){
        cout << w.first << ' ' << w.second << '\n';
    }
}