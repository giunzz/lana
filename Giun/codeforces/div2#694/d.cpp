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

vec(ll) snt, notPrime(1e6 + 7, 0);
unordered_map<ll, ll> optMsk;

void init(){
    notPrime[0] = notPrime[1] = 1;
    optMsk[1] = 1;
    lp(i, 2, 1e6){
        if(!notPrime[i]){
            snt.push_back(i);
            optMsk[i] = i;
            for(ll j = i * i; j <= 1e6; j += i)
                notPrime[j] = i;  
        }
    }
    lp(i, 1, 1e6){
        if(optMsk[i]) continue;
        ll cnt = 0, tmp = i;
        while(!(tmp % notPrime[i])) tmp /= notPrime[i], ++cnt;
        optMsk[i] = optMsk[tmp];
        if(cnt & 1) optMsk[i] *= notPrime[i];
    }
}

void sol(){
    ll n = read();
    vec(ll) a(n), b;
    unordered_map<ll, ll> cntMsk;
    for(ll &i : a){
        cin >> i;
        i = optMsk[i];
        if(!cntMsk[i]++) b.push_back(i);
    }
    ll ans = 0, ans1 = 0;
    for(ll i : b){
        ans = max(ans, cntMsk[i]);
        if((~cntMsk[i] & 1) && i != 1) ans1 += cntMsk[i];
    }                                 
    ans1 += cntMsk[1];                                                                  
    for(ll i : b) ans1 = max(ans1, cntMsk[i]);
    lpd(q, read(), 1){
        ll num = read();
        if(num) cout << ans1 << '\n';
        else cout << ans << '\n';
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