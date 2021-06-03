#include <bits/stdc++.h>
#define ll unsigned long long
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

ll cnt[107], snt[107] = {0}, n, p, num;
vec(ll) prime;

void init(){
    for(ll i = 2; i <= 100; ++i) if(!snt[i]){
        for(ll j = i * i; j <= 100; j += i){
            snt[j] = i;
        }
        snt[i] = i;
        prime.push_back(i);
    }
}

inline ll total(ll num, ll pw){
    ll pd = pw, tot = 0;
    while(num >= pd) tot += num / pd, pd *= pw;
    return tot;  
}

inline bool check(ll tmp){
    for(ll &i : prime)
        if(total(tmp, i) < cnt[i]) return 0;
    return 1;
}

void sol(){
    memset(cnt, 0, sizeof cnt);
    cin >> n;
    lp(i, 1, n){
        cin >> num >> p;
        if(num == 1) continue;
        for(; snt[num]; num /= snt[num]) cnt[snt[num]] += p;
    }
    ll l = 1, r = ULLONG_MAX - 1, ans = 0;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << '\n';
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    init();
    // EACHCASE sol();
    cerr << total(1e19, 97);
}