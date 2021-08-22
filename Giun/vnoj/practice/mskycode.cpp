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

cll mxn = 1e4 + 4;
ll n, cnt[mxn] = {0}, res[mxn], mo[mxn] = {0};

ll choose4(ll n){
    return (n - 3) * (n - 2) * (n - 1) * n / 24;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    // init mobius func
    // mo[i] = -sum of mo[j] with j | i
    mo[1] = 1;
    lp(i, 1, 1e4) for(ll j = 2 * i; j <= 1e4; j += i) mo[j] -= mo[i];
    EACHCASE{
        memset(cnt, 0, sizeof cnt);
        cin >> n;
        lp(i, 1, n){
            ll tmp; cin >> tmp;
            ++cnt[tmp];
        }
        lp(i, 2, 1e4){
            ll tot = 0;
            for(ll j = i; j <= 1e4; j += i)
                tot += cnt[j];
            res[i] = choose4(tot);
            // if(res[i] || tot) cerr << i << ' ' << res[i] << ' ' << tot << '\n';
        }
        ll ans = choose4(n);
        lp(i, 2, 1e4) ans += mo[i] * res[i];
        cout << ans << '\n';
    }
}