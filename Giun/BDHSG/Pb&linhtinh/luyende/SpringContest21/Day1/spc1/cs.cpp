#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

void sinh(string s){
    ofstream co;
    co.open((s + ".inp").c_str());

    co.close();
    system(s.c_str());
    system((s + "_bruce").c_str());
}

bool cham(string s){
    ll ac = system(("fc " + s + ".out " + s + ".ans /w").c_str());
    if(!ac) return 1;
}

int main(){
    string s = "sc1";
    file(s);
    ll test = 1, ac = 0;
    string c = s;
    lp(i, 1, test){
        sinh(s);
        if(cham(s)) ++ac;
    }
}