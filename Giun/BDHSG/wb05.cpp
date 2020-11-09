#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "primes"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll a, b;

bool check(ll t){
    if(t < 2) return 0;
    for(ll i = 2; i * i <= t; ++i) if(!(t%i)) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> a >> b;
    // if(a > b) swap(a, b);
    // if(check(b - a)) {cout << 2 << '\n' << a << ' ' << b; return 0;}
    // else if(a > 2){
    //     if(check(a - 2) && check(b - 2)) {cout << 3 << '\n' << a << ' ' << 2 << ' ' << b; return 0;}
    // }
    // else{
    //     if(check(b - 2) && check(b - 4)) {cout << 3 << '\n' << a << ' ' << (b - 2) << ' ' << b; return 0;}
    //     if(check(b + 2)) {cout << 3 << '\n' << a << ' ' << (b + 2) << ' ' << b; return 0;}
    // }
    ll a2, b2;
    if(a % 3 == 1) a2 = a - 2;
    else a2 = a + 2;
    if(b % 3 == 1) b2 = b - 2;
    else b2 = b + 2;
    if(check(abs(b - a))) cout << 2 << '\n' << a << ' ' << b;
    else if(check(a2) && check(b2) && a2 > a && b2 > b) cout << 5 << '\n' << a << ' ' << a2 << ' ' << 2 << ' ' << b2 << ' ' << b;
    else if(check(abs(a2 - b)) && check(a2)) cout << 3 <<  '\n' << a << ' ' << a2 << ' ' << b;
    else if(check(abs(b2 - a) && check(b2))) cout << 3 << '\n' << a << ' ' << b2 << ' ' << b;
    else if(check(abs(a - 2)) && check(abs(b - 2))) cout << 3 << '\n' << a << ' ' << 2 << ' ' << b;
    else cout << "-1";
}