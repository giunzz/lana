#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

string s;
ll MOD = 1e9 + 7;

ll poww(ll u, ll v){
    if(!v) return 1;
    ll tmp = poww(u, v >> 1);
    (tmp *= tmp) %= MOD;
    if(v & 1) return (tmp * u) % MOD;
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    // OF();
    #endif
    cin >> s;
    ll ans = 0;
    lp(i, 0, s.size() - 1){
        (ans += (s[i] - 'a' + 1) * poww(31, i)) %= MOD;
    }
    cout << ans;
}

// lamnguoiyeuanhnhooooo