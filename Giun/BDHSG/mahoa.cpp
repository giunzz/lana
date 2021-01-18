#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "mahoa"
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

string encrypt(string &s, ll l, ll r){
    if(l > r) return "";
    if(l == r) return string(1, s[l]);
    ll mid = (l + r) >> 1;
    return string(1, s[mid]) + encrypt(s, l, mid - 1) + encrypt(s, mid + 1, r);
}

void sol(){
    ll n;
    string s;
    cin >> n >> s;
    s = '.' + s;
    cout << encrypt(s, 1, n) << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}