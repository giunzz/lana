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

ll cnt(ll const &x, ll y){
    ll tmp = 0;
    while(x / y){
        tmp += x / y;
        y *= y;
    }
    return tmp;
}

cll maxb = 1e3 + 7;
ll n, b, ss[maxb] = {0}, c[maxb] = {0};
vec(ll) u;

void sang(){
    ss[0] = ss[1] = 1;
    for(ll i = 2; i * i <= 1e3; ++i){
        if(ss[i]) continue;
        for(ll j = i * i; j <= 1e3; j += i){
            ss[j] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> b;   
    ll k = 2;
    while(b){
        while(b % k){
            ++k;
        }
        u.push_back(k);
        while(b && b % k == 0) ++c[k], b /= k;
    }
    for(ll )
}