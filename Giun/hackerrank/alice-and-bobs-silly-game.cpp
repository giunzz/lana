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

cll mxn = 1e5 + 7;
vec(ll) snt;
bool f[mxn], sv[mxn] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    sv[0] = sv[1] = 1; 
    f[0] = 0;
    lp(i, 2, 1e5){
        if(!sv[i]){
            snt.push_back(i);
            for(ll j = i * i; j <= 1e5; j += i) sv[j] = 1;
        }
        f[i] = snt.size() & 1;
    } 
    EACHCASE{
        ll n = read();
        if(f[n]) cout << "Alice\n";
        else cout << "Bob\n";
    }
}