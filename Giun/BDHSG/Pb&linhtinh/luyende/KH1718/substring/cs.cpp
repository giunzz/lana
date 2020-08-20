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
    ll n = Rand(1, 500), k = Rand(1, (ll)min(n, 1LL*26));
    co << n << ' ' << k << '\n';
    lp(i, 1, n) co << (char)Rand('a', 'z');
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
    srand((ll)time(0));
    string s = "substring";
    // file(s);
    ll test = 100, ac = 0;
    lp(i, 1, test){
        sinh(s);
        if(cham(s)) ++ac;
        else break;
    }
    cout << ac << '/' << test;
}