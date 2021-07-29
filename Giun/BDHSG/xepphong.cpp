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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll randll(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

double randb(double a, double b){
    return uniform_real_distribution<double>(a, b)(rng);
}

double sigmoid(double x){
    return 1.0 / (1 + exp(-x));
}

void gen(ostream &cout, ll n, double threshold){
    cout << n << '\n';
    lp(j, 1, n) cout << (randb(0.0, 1.0) < threshold ? randll(1, 2) : randll(3, 4)) << ' ';
}

void run(){
    ofstream f(Fname".inp");
    gen(f, randll(2, 1e6), sigmoid(randb(-1.0, 1.0)));
    f.close();
}

cll mxn = 1e6 + 7;
ll n, cnt[5] = {0}, a[mxn];

int main(){
    run();
    giuncute();
    OF();
    cin >> n;
    lp(i, 1, n) ++cnt[a[i] = read()];

    cnt[1] -= min(cnt[1], cnt[3]);

    cnt[2] *= 2;
    ll tmp = cnt[2] % 4;
    cnt[2] += min(tmp, cnt[1]);
    cnt[1] -= min(tmp, cnt[1]);

    cnt[2] = (cnt[2] + 3) / 4;
    cnt[1] = (cnt[1] + 3) / 4;
    
    cout << cnt[1] + cnt[2] + cnt[3] + cnt[4];
}