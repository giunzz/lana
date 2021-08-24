#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "waw"
using namespace std;

mt19937 rng(4545422);

ll randll(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

double randb(double a, double b){
    return uniform_real_distribution<double>(a, b)(rng);
}

void gen(){
    ofstream co(Fname".inp");
    ll n = 1e5;
    co << n << '\n';
    lp(i, 1, n) co << randll(1, 1e9) << ' ';
    co << '\n';
    lp(i, 2, n){
        co << randll(1, i - 1) << ' ' << i << '\n';
    }
    co.close();
}

cll mxn = 2e3;
ll n, a[mxn], sz = 0, ans = 0;
vec(ll) g[mxn];
unordered_map<ll, ll> mp;

void sol(ll u){
    for(ll v : g[u]){
        sol(v);
    }
    if(++mp[a[u]] > sz) sz = mp[a[u]], ans = a[u];
    else if(mp[a[u]] == sz) ans += a[u];
}

void bruce(ofstream &cout, ifstream &cin){
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
        g[i].clear();
    }
    lp(i, 1, n - 1){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    lp(i, 1, n){
        mp.clear();
        sz = ans = 0;
        sol(i);
        cout << ans << ' ';
    }
}

bool checker(){
    ll val = system("fc " Fname ".out " Fname  ".ans /w");
    return val;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    lp(i, 1, 1){
        gen();
//        ofstream o(Fname".ans"); ifstream ip(Fname".inp");
//        bruce(o, ip);
//        o.close(); ip.close();
     //   system(Fname);
        if(checker()){
            cout << "NGU";
            return 0;
        }
    }
}
