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

//date gene 1/7/2021
mt19937 rng(01072021);

ll randll(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

double randb(double a, double b){
    return uniform_real_distribution<double>(a, b)(rng);
}

double sigmoid(double x){
    return 1.0 / (1 + exp(-x));
}

void gen(ostream &cout, ll m, ll n, double threshold){
    cout << m << ' ' << n << '\n';
    lp(i, 1, m){lp(j, 1, n) cout << (randb(0.0, 1.0) < threshold ? '.' : '#'); cout << '\n';}
}

#define maxtest 25

int main(){
    // giuncute();
    lp(i, 0, maxtest - 1){
        char filename[128];
        sprintf(filename, "tests/input.%03d", i);
        ofstream co(filename);
        if(i < 1) gen(co, 7, 8, 1.01);
        else if(i < 2) gen(co, 8, 7, 0);
        else if(i < 6) gen(co, randll(1, 70), randll(1, 70), sigmoid(randb(-4.0, 1.5)));
        else if(i < 10) gen(co, randll(1, 70), randll(1, 70), sigmoid(randb(-1.5, 4.0))); 
        else if(i < 15) gen(co, randll(1, 1e3), randll(1, 1e3), sigmoid(randb(-4.0, 1.5)));
        else if(i < 20) gen(co, randll(1, 1e3), randll(1, 1e3), sigmoid(randb(-1.5, 4.0)));
        else if(i < 22) gen(co, randll(999, 1e3), randll(999, 1e3), sigmoid(randb(-4.0, 1.5)));
        else if(i < 24) gen(co, randll(999, 1e3), randll(999, 1e3), sigmoid(randb(-1.5, 4.0)));
        else gen(co, randll(999, 1e3), randll(999, 1e3), sigmoid(0));
        // gen(cout, randll(1, 30), randll(1, 30), sigmoid(randb(-8.5, 1)));
        
        cout << filename << '\n';
    }
    lp(i, 0, maxtest - 1){
        char command[128];
        sprintf(command, "/usr/bin/time -p ./FNHOUSES < ./tests/input.%03d > ./tests/output.%03d", i, i);
        cout << command << '\n';
        system(command);
    }
}