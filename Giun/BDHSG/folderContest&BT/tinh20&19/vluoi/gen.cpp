#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "vluoi"
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
    ll n = 99, m = 100;
    co << n << ' ' << m << '\n';
    co << 1 << ' ';
    lp(i, 1, n){
        lp(j, 1, m) if(!(i == 1 && j == 1)) co << randll(1, 3) << ' ';
        co << '\n';
    }
    co.close();
}

//cll mxn = 1e3 + 2;
//ll n, m, a[mxn][mxn];
//
//void bruce(ofstream &cout, ifstream &cin){
//    cin >> n >> m;
//    lp(i, 1, n) cin >> a[i];
//    dfs(1, 1);
//}

bool checker(){
    ll val = system("fc " Fname ".out " Fname  ".ans /w");
    return val;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    lp(i, 1, 100){
        gen();
//        ofstream o(Fname".ans"); ifstream ip(Fname".inp");
//        bruce(o, ip);
//        o.close(); ip.close();
        system("bruce");
        system(Fname);
        if(checker()){
            cout << "NGU";
            return 0;
        }
    }
}
