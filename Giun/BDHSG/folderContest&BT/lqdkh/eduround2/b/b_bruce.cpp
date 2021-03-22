#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "b"
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
    freopen(Fname".ans", "w", stdout);
}

cll mxn = 1e5 + 7;
ll n, sum = 0, a[mxn];

inline ll Get(ll x){
    ll res = 0, tv = 1e18, vl;
    lp(i, 1, n) if(abs(a[i] - x) < tv) tv = abs(a[i] - x), vl = a[i];
    lp(i, 1, n) res += abs(a[i] - vl);
    return res;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) sum += (a[i] = (read() - i));
    // cout << min({Get(ceil(sum / (double)n)), Get(floor(sum / (double)n)), Get(ceil(sum / (double)n) + 1), Get(floor(sum / (double)n) - 1)});
    sort(a + 1, a + 1 + n);
    ll x = a[(n + 1) / 2], res = 0;
    lp(i, 1, n) res += abs(x - a[i]);
    cout << res;
}