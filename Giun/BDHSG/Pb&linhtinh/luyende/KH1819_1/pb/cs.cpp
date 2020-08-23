#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
using namespace std;

void file(const string s){
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

ll Rand(ll l, ll r){
    return l + (rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                 rand() * (RAND_MAX + 1)+
                  rand() % (r - l + 1));
}

void sinh(string f){
    ofstream co;
    co.open((f + ".inp").c_str());

    co.close();
    system(f.c_str());
    system((f + "_bruce").c_str());
}

bool cham(string f){
    ll t = system(("fc " + f + ".ans " + f + ".out /w").c_str());
    return !t;
}

int main(){
    srand((int)time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s = "pb";
    //file("pb");
    ll test = 1, ac = 0;
    lp(i, 1, test){
        sinh(s);
        if(cham(s)) ++ac;
    }
    cout << ac << '/' << test;
}
