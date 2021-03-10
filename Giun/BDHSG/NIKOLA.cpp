#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "nikola"
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

cll mxn = 1e3 + 7;
ll n, a[mxn];
unordered_map<ll, unordered_map<ll, ll>> mp;

inline ll sol(ll pos, ll jump){
    // cerr << pos << ' ' << jump << ' ' <<'\n';
    if(pos == n) return a[pos];
    ll getRes = mp[pos][jump];
    if(getRes) return getRes;
    ll tmp = 1e15, njump = jump + 1;
    if(pos - jump >= 1 && jump) tmp = min(sol(pos - jump, jump), tmp);
    if(pos + njump <= n) tmp = min(sol(pos + njump, njump), tmp);
    return mp[pos][jump] = tmp + a[pos];
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    ll ans = LLONG_MAX;
    cout << sol(1, 0) - a[1];
}