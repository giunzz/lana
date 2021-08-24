#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "dankien"
using namespace std;

mt19937 rng(43243);

ll randll(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

double randb(double a, double b){
    return uniform_real_distribution<double>(a, b)(rng);
}

void gen(){
    ofstream co(Fname".inp");
    ll n = 1e6, last = 0;
    co << n << '\n';
    lp(i, 1, n) co << randll(1, 100) << ' ';
    co << '\n';
    lp(i, 1, n){
        last = randll(last + 1, 9e8 + i);
        co << last << ' ';
    }
    co.close();
}

void bruce(ofstream &cout, ifstream &cin){
    ll n, a[101], x[101], ans = 1e18;
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    lp(i, 1, n) cin >> x[i];
    lp(i, 1, n){
        ll tmp = 0;
        lp(j, 1, n) tmp += abs(x[j] - x[i]) * a[j];
        ans = min(ans, tmp);
    }
    cout << ans;
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
        // cerr << clock() << '\n';
        system(Fname);
        // cerr << clock() << '\n';
        if(checker()){
            cout << "NGU";
            return 0;
        }
    }
}
