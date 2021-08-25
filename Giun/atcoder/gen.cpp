#define _seed 879898
#define _need 1

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

// void OF(){
//     // freopen(Fname".inp", "r", stdin);
//     freopen(Fname".inp", "w", stdout);
// }

mt19937 rng(_seed);

ll randll(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

void gen(ofstream &cout){
    ll n = 5, m = 10, q = 50;
    vec(bool) start(25, 0);
    cout << n << ' ' << m << ' ' << q << '\n';
    lp(i, 1, m){
        ll time_start = randll(1, i * 2), time_end = randll(time_start + 1, 21), a = randll(1, n), b = randll(1, n);
        while(start[time_start]) time_start = randll(1, i * 2), time_end = randll(time_start + 1, 21);
        start[time_start] = 1;
        while(a == b) a = randll(1, n), b = randll(1, n);
        cout << a << ' ' << b << ' ' << time_start << ' ' << time_end << '\n';
    }
    lp(i, 1, q){
        ll x = randll(1, 24), y = randll(1, n), z = randll(x + 1, 25);
        cout << x << ' ' << y << ' ' << z << '\n';
    }
}

void process(){
    freopen("f.inp", "r", stdin);
    freopen("f.ans", "w", stdout);
    ll n, m, q;
    cin >> n >> m >> q;
    vec(pp(pp(ll, ll), pp(ll, ll))) bus;
    lp(i, 1, m){
        ll a, b, s, t;
        cin >> a >> b >> s >> t;
        bus.push_back({{s, t}, {a, b}});
    }
    sort(bus.begin(), bus.end());
    lp(i, 1, q){
        ll x, city, y, atbus, citynow, timenow;
        cin >> x >> city >> y;
        citynow = city;
        timenow = x;
        bool ok = 0;
        lp(i, 0, m - 1){
            if(bus[i].first.first >= timenow && bus[i].second.first == citynow){
                if(bus[i].first.first >= y) break;
                ok = 1, atbus = i;
                if(bus[i].first.second >= y) break;
                ok = 0, timenow = bus[i].first.second, citynow = bus[i].second.second;
            } 
        }
        if(ok) cout << bus[atbus].second.first << ' ' << bus[atbus].second.second << '\n';
        else cout << citynow << '\n';
    }
}

int main(){
    giuncute();
    if(_need){
        ofstream co("f.inp");
        gen(co);
        co.close();
    }
    process();
}