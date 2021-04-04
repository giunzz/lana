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

cll mxn = 3e5 + 7;
ll n, k, a[mxn], s[mxn];
double med = 0, res = 0;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> k;
    lp(i, 1, n){cin >> a[i]; s[i] = s[i - 1] + a[i];}
    res = med = s[k] / (k * 1.0);
    ll i = 1, j = k;
    while(j <= n){
        ll ni = i;
        ++j;
        while(j - ni >= k && (s[j] - s[ni]) * (j - ni + 1) > (s[j] - s[ni - 1]) * (j - ni)) ++ni;
        i = ni;
        res = max(res, (s[j] - s[i - 1]) / ((j - i + 1) * 1.0));
    }
    cout << fixed << setprecisio    n(6) << res;
}   