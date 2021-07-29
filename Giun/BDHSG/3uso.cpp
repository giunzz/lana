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

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".ans", "w", stdout);
}

cll mxn = 1e6 + 6;
ll n, ans = 0;
bool sang[mxn] = {0};

int main(){
    giuncute();
    OF();
    cin >> n;
    for(ll i = 2; i * i <= n; i++){
        if(!sang[i]){
            ++ans;
            for(ll j = i * i; j <= min((ll)1e6, n); j += i) 
                sang[j] = 1;
        }
    }
    cout << ans;
}