#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "tcone"
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

cll mxn = 1e5;
ll a[mxn], l[mxn] = {0}, r[mxn] = {0}, n, ma = 1;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){cin >> a[i]; l[i] = __gcd(l[i - 1], a[i]);}
    lpd(i, n, 1) r[i] = __gcd(r[i + 1], a[i]);
    lp(i, 1, n){
        // ll tmp = __gcd(l[i - 1], r[i + 1]);
        // if(a[i] % tmp) ma = max(ma, tmp);
        ma = max(ma, __gcd(l[i - 1], r[i + 1]));
    }
    cout << ma;
}