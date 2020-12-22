#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;
string Fname = "pb";

void OF(const string f){
    freopen((f + ".inp").c_str(), "r", stdin);
    freopen((f + ".out").c_str(), "w", stdout);
}

void gene(){

    system((Fname).c_str());
    system((Fname + "_bruce").c_str());
}

bool ac(){
    bool c = system(("fc + " + Fname + ".ans " + Fname + ".out /w").c_str());
    return !c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF("pb");
    
}