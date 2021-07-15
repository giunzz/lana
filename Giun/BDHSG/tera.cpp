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

cll mxn = 1e3 + 7, mxnn = 1e6 + 7;
ll n, a[mxn], b[mxn], c[mxn], d[mxn], l, ans = 0, down[mxnn];
unordered_map<ll, ll> cnt;

int main(){
    giuncute();
    OF();
    Read(n); Read(l);
    lp(i, 1, n) Read(a[i]);
    lp(i, 1, n) Read(b[i]);
    lp(i, 1, n) Read(c[i]);
    lp(i, 1, n) Read(d[i]);
    ll tot = 0;
    lp(i, 1, n) lp(j, 1, n) down[++tot] = (c[i] + d[j]), ++cnt[a[i] + b[j]];
    lp(i, 1, tot) ans += cnt[l - down[i]];
    cout << ans;
    cerr << clock();
}
