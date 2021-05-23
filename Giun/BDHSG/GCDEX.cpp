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
ll euler[mxn] = {0}, mo[mxn] = {0}, se[mxn] = {0};

void init(){
    mo[1] = 1;
    // mo[i] = -sigma mo[j] voi j la uoc cua i
    lp(i, 1, 1e6) for(ll j = 2 * i; j <= 1e6; j += i) mo[j] -= mo[i];
    // n = sigma euler i voi i la uoc cua n
    // h[n] * cnt[n]
    // h[n] = n = sigma euler i voi i la uoc cua n
    // fn = sigma (sigma(fd', d' la uoc cua d) * mu(n/d), d la uoc cua n)
    // Ma fn = euler n
    // => euler n = sigma (d * mu(n / d), d la uoc cua n)
    lp(i, 1, 1e6){
        // for(ll j = 2 * i; j <= 1e6; j += i) mo[j] -= mo[i]; 
        for(ll j = i; j <= 1e6; j += i) euler[j] += i * mo[j / i]; 
        se[i] = se[i - 1] + euler[i];
    }
}

void init1(){
    // euler n = n * (1 - 1/p1) * .. * (1 - 1/pk)
    // assign a = n;
    // a -= a/p1; .. a-=a/pk; => a = euler n
    // se[1] = 1;
    lp(i, 1, 1e6) euler[i] = i;
    lp(i, 2, 1e6){
        if(euler[i] == i) for(ll j = i; j <= 1e6; j += i) euler[j] -= euler[j] / i; 
        // se[i] = se[i - 1] + euler[i];
    }
    // sigma gcd(i, n) // i < n
    //cnt i la so luong cap gcd(j, n) = i
    // bai toan con sigma gcd(i, n) = d la uoc cua n sigma d * cnt[d] = sigma (sigma euler d', d' la uoc d) * cnt[d] = vs i la uoc cua n sigma euler[i] * sigma cnt[d'], d' la boi cua i = sigma euler i * n/i vs i la cua n
    lp(i, 1, 1e6) for(ll j = i << 1; j <= 1e6; j += i) se[j] += i * euler[j / i];
    lp(i, 1, 1e6) se[i] += se[i - 1];
}

int main(){
    // giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    // init();
    init1();
    // lp(i, 1, 1e6) se[i] = se[i - 1] + euler[i];
    // lp(i, 1, 21) cerr << euler[i] <<  ' ';
    ll n;
    // ans = sigma (i * cnt[i]) = sigma(sigma(euler d, d la uoc cua i) * cnt[i]) = sigma(euler i * sigma(cnt[d], d la boi cua i va d <= n))
    // <=> ans = sigma(euler i * n / d * (n / d - 1) / 2)
    for(;;){
        scanf("%lld", &n);
        if(!n) break;
        printf("%lld\n", se[n]);
    }
}