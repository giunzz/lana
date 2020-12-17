#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e3 + 7;
ll n, k, b;
// pp(ll, ll) a[maxn];
vec(ll) a[3];

bool cpr(pp(ll, ll) &x, pp(ll, ll) &y){
    return x.second < y.second || (x.second == y.second && x.first < y.first);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> k >> b;
    lp(i, 1, n){
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    lp(i, 1, 2) sort(a[i].begin(), a[i].end());
    
}