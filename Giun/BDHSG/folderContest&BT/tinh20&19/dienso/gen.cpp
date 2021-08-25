#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "dienso"
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
    ll n = 1e6;
    co << n << '\n';
    lp(i, 1, n) co << (randll(0, 1) ? '<' : '>');
    co.close();
}

void bruce(ofstream &cout, ifstream &cin){

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
        system(Fname);
        if(checker()){
            cout << "NGU";
            return 0;
        }
    }
}
