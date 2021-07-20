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
    // freopen(Fname".out", "w", stdout);
}

ll cnt(ll i){
    if(!i) return 0;
    return cnt(i >> 1) + (i & 1);
}

mt19937 rng(841566);

ll randll(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

void gen(){
    ofstream co("f.inp");
    co << 4 << '\n';
    lp(i, 1, 4){
        ll l = randll(1, 1000), r = randll(1000, 100000);
        co << l << ' ' << r << ' ' << randll(1, (ll)log2(r)) << '\n';
    }
    co.close();
}

int main(){
    gen();
    // giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE{
        ll l, r, k;
        bool ok = 0;
        cin >> l >> r >> k;
        lp(i, l, r){
            if(ok) continue;
            if(cnt(i) == k) ok = 1, cout << i << '\n';
        }
        if(!ok) cout << -1 << '\n';
    }
    cout << "===========\n";
    system("test");
}