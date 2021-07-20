#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "ac6"

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}
#define EACHCASE lpd(cs, read(), 1)

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1, d = gcd(b, a % b, x1, y1);
    x = y1, y = x1 - y1 * (a / b);
    return d;
}

ll a, b, n, x, y, g;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    EACHCASE{
        cin >> a >> b >> n;
        if(a > b) swap(a, b);
        if(n % (g = gcd(a, b, x, y))){
            cout << "-1\n";
        } else{
            // a /= g, b /= g, n /= g;
            // if(y < 0) swap(a, b), gcd(a, b, x, y);
            
            ll k, ans1, ans2, xx = x, yy = y;
            // if(x < 0){
                x *= (n / g);
            y *= (n / g);
                k = -x * g / ((double)b);
                x = x + k * b / g;
                y = y - k * a / g;
            if(x >= 0 && y >= 0) ans1 = x + y;
            else ans1 = 1e18;
            swap(a, b);
            gcd(a, b, x, y);
            x *= (n / g);
            y *= (n / g);
                k = -x * g / ((double)b);
                x = x + k * b / g;
                y = y - k * a / g;
            if(x >= 0 && y >= 0) ans2 = x + y;
            else ans2 = 1e18;
            ans1 = min(ans1, ans2);
            // cerr << x << ' ' << y << ' ' << k << '\n';
            // ll k = round((n * (x - y)) / ((a + b) * (double)1.0));
            // if(n * x - k * b >= 0 && n * y + k * a >= 0) cout << (n * x - k * b + n * y + k * a) << '\n';
            // else cout << "-1\n";
            if(ans1 == 1e18) cout << "-1\n";
            else cout << ans1 << '\n';
        }
    }
    // cerr << gcd(7, 3, x, y) << ' ' << x << ' ' << y;
}