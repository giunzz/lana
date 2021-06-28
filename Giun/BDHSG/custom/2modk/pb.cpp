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

cll mxk = 1e4 + 7;
ll n, k, mul, cnt, f[mxk], ng, dv;

void sol(){
    cnt = 0;
    cin >> n >> k;
    ng = n / k;
    dv = n % k;
    lp(i, 0, k - 1){
        f[i] = ng;
        if(i <= dv) ++f[i]; 
    }
    --f[0];
    lp(i, 0, k - 1){
        if(i > k - i) break;
        if(i == 0 or i == k - i) cnt += f[i] * (f[i] - 1) / 2;
        else cnt += f[i] * f[k - i]; 
    }
    cout << cnt << '\n';
}

int main(){
    giuncute();
    // #ifndef ONLINE_JUDGE
    // OF();
    // #endif
    EACHCASE sol();
}