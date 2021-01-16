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

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

void sol(){
    string x, y;
    cin >> x >> y;
    ll a = x.size(), b = y.size(), lcm = (a * b) / __gcd(a, b);
    a = lcm / a, b = lcm / b;
    string ans1, ans2;
    lp(i, 1, a) ans1 += x;
    lp(i, 1, b) ans2 += y;
    if(ans1 == ans2) cout << ans1 << '\n';
    else cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}