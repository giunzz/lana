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

cll mxn = 107, mxv = 1e7 + 2;
ll n, a[mxn], tu[mxv] = {0}, mau[mxv] = {0};
bool sang[mxv] = {0};
vec(ll) snt;

ll _pow(ll u, ll v){
    if(!v) return 1;
    ll tmp = _pow(u, v >> 1);
    if(v & 1) return tmp * tmp * u;
    return tmp * tmp;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    for(ll i = 2; i <= 1e7; ++i) 
        if(!sang[i]){for(ll j = i * i; j <= 1e7; j += i) sang[j] = 1; snt.push_back(i);}
    cin >> n;
    if(!n){
        cout << "impossible";
        return 0;
    }
    ll tmp;
    lp(i, 1, n){
        cin >> a[i];
        if(a[i] == 0){
            cout << "impossible";
            return 0;
        }
        
        for(ll j : snt){
            if(j * j > a[i]) break;
            tmp = 0;
            while(a[i] % j == 0) ++tmp, a[i] /= j;
            tu[j] += tmp, mau[j] = max(mau[j], tmp);
        }
        if(a[i] > 1) ++tu[a[i]], mau[a[i]] = max(mau[a[i]], 1LL);
    }
    ll ans = 1;
    lp(i, 2, 1e7){
        tu[i] -= mau[i];
        ans *= _pow(i, tu[i]);
    }
    cout << ans;
}