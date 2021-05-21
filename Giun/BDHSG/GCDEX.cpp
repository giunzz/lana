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
ll euler[mxn] = {0}, mo[mxn] = {0};

void init(){
    mo[1] = 1;
    // mo[i] = -sigma mo[j] voi j la uoc cua i
    lp(i, 1, 1e6) for(ll j = 2 * i; j <= 1e6; j += i) mo[j] -= mo[i];
    // n = sigma euler i voi i la uoc cua n
    // h[n] * cnt[n]
    // h[n] = n = sigma euler i voi i la uoc cua n
    // fn = sigma ()
    lp(i, 1, n) for(ll j = i; j <= 1e6; j += i) 
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    init();
}