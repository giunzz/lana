#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "stopwatch"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll n, a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> a >> b;
    // n, --a, --b;
    // ll ans = 0;
    // while(a != b) {
    //     a  = (a + 1) % n;
    //     ++ans;
    // }
    // cout << ans;
    cout << ((a <= b) ? (b - a) : (n + b - a));
}