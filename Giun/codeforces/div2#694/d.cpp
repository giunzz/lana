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

vec(ll) sang(1e6 + 7, 0), snt;

void sol(){
    ll n = read();
    vec(ll) a(n);
    for(ll &i : a) i = read();

}

void init(){
    sang[0] = sang[1] = 1;
    lp(i, 2, 1e6){
        if(!sang[i]){
            snt.push_back(i);
            for(ll )
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    init();
    EACHCASE sol();
}