#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

ll Rand(ll l, ll r){
    return l + ((ll)rand()*(RAND_MAX + 1)*(RAND_MAX + 1)*(RAND_MAX + 1)+
                (ll)rand()*(RAND_MAX + 1)*(RAND_MAX + 1)+
                (ll)rand()*(RAND_MAX + 1)+
                rand()) % (r - l + 1);
}

void sinh(string s){
    ofstream co;
    co.open((s + ".inp").c_str());
    ll n = Rand(500, 1000), m = Rand(500, 1000);
    co << n << ' ' << m << endl;
    lp(i, 1, n) co << Rand(1, 1e9) << ' ';
    co << endl;
    lp(i, 1, m) co << Rand(1, 1e9) << ' ';
    co.close();
    system(s.c_str());
    system((s + "_bruce").c_str());
}

bool cham(string s){
    ll ac = system(("fc " + s + ".out " + s + ".ans /w").c_str());
    if(!ac) return 1;
    else return 0;
}

int main(){
    string s = "hough";
    // file(s);
    ll test = 100, ac = 0;
    string c = s;
    lp(i, 1, test){
        sinh(s);
        if(cham(s)) ++ac;
    }
    cout << ac << '/' << test;
}