#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "lulut"
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
    ll n = 100;
    co << n << '\n';
    lp(i, 1, n){
        co << randll(1, 20) << ' ' << randll(1, 2000) << ' ' << randll(1, 20) << '\n';
    }
    co.close();
}

ll n, t[20], d[20], p[20], pos[20], atpos[20], ans = 0;

void quay(ll u){
    if(u == n + 1){
        ll res = 0, time = 1;
        lp(i, 1, n){
            if(!atpos[i]) continue;
            if(d[atpos[i]] < time + t[atpos[i]]) return;
            res += p[atpos[i]];
            time = time + t[atpos[i]];
        }
        ans = max(ans, res);
        return;
    }
    lp(i, 0, n){
        if(i){
            if(!atpos[i]){
                atpos[i] = u;
                quay(u + 1);
                atpos[i] = 0;
            }
        }else{
            atpos[i] = 0;
            quay(u + 1);
        }
    }
}

void bruce(ofstream &cout, ifstream &cin){
    cin >> n;
    lp(i, 1, n) cin >> t[i] >> d[i] >> p[i];
    ans = 0;
    quay(1);
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
//        system(Fname);
        if(checker()){
            cout << "NGU";
            return 0;
        }
    }
}
