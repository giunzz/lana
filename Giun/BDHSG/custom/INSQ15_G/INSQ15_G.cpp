#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "INSQ15_G"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll n, m, p;
map<pp(ll, ll), ll> cnt;
vec(pp(ll, ll)) point;

// #define ONLINE_JUDGE
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> p;
    lp(i, 1, p){
        ll x, y;
        cin >> x >> y;
        if(!cnt[{x, y}]++) point.push_back({x, y});
    }
    ll ans = 0;
    for(pp(ll, ll) p : point){
        if(((p.first + p.second) & 1) != ((1 + m) & 1)) ans ^= cnt[p];
    }
    if(ans) cout << "Yes\n";
    else cout << "No\n";
}

//https://www.codechef.com/problems/INSQ15_G

// void subbruce(){
//     cin >>  n >> m >> p;
//     a.assign(n + 1, vec(ll)(m + 1, 0));
//     lp(i, 1, p){
//         ll x, y;
//         cin >> x >> y;
//         ++a[x][y];
//     }
//     lp(i, 1, n) lp(j, 1, m){
//         if(((i + j) & 1) == ((1 + m) & 1)) a[i][j] = 0;
//     }
//     ll ans = 0;
//     lp(i, 1, n) lp(j, 1, m){
//         ans ^= a[i][j];
//     }
//     if(ans) cout << "YES\n";
//     else cout << "NO\n";
// }
