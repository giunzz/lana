#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "pb"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

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
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e6 + 7;
ll sang[mxn] = {0}, n;

void init(){
    for(ll i = 2; i * i<= 1e6; ++i){
        if(!sang[i]) for(ll j = i * i; j <= 1e6; j += i){
            sang[j] = i;
        }
    }
}

void sol(){
    cin >> n;
    // cerr << n;
    ll tmp = n, p2 = 0, totu = 0, totcp = 0, cnt = 0;
    while(tmp % 2 == 0){
        ++p2;
        tmp /= 2;
    }
    // cerr << tmp;
    totcp = p2 / 2, totu = p2 + 1;
    while(sang[tmp] != 0 && tmp % sang[tmp] == 0){
        ll pr = sang[tmp];
        cnt = 0;
        while(tmp % pr == 0) ++cnt, tmp /= pr;
        totu *= (cnt + 1);
        totcp *= (cnt / 2 + 1);
    }
    if(tmp != 1) totu *= 2;
    --totu;
    if((ll)sqrt(n) * (ll)sqrt(n) == n) --totcp;
    ll gcd = __gcd(totu, totcp);
    if(totcp) cout << totcp / gcd << "/" << totu / gcd<< '\n';
    else cout << "0\n";
}   

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    init();
    // cerr << '1';
    EACHCASE sol();
}