#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
// #define Fname "palindrome"
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

cll maxn = 1e4 + 7;
ll n, f[maxn] = {0};
vec(ll) palin;

bool isPalin(string s){
    lp(i, 0, (s.size() - 1) / 2){
        if(s[i] != s[s.size() - 1 - i]) return 0;
    }
    return 1;
}

void sol(){
    cin >> n;
    cout << f[n] << '\n';
}

void init(){
    lp(i, 1, maxn) if(isPalin(to_string(i))) palin.push_back(i);
    ll j = 0;
    lp(i, 1, 1e4){
        while(palin[j] <= i) ++j;
        ll mi = LLONG_MAX;
        lpd(z, j - 1, 0) if(f[i - palin[z]] < mi) mi = f[i - palin[z]];
        if(mi == LLONG_MAX) mi = 0;
        f[i] = mi + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    init();
    // cerr << clock();
    EACHCASE sol();
}