#include <bits/stdc++.h>
#define ll int
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

class EllysFlags{
    private:
    ll n, m, sol(ll i, string stt);
    map<ll, map<string, map<string, ll>>> dp;
    vec(vec(ll)) f;
    public:
    int getMax(vec(string) a);
};

int EllysFlags::getMax(vec(string)a){
    this -> n = a.size() - 1, this -> m = a.back().size() - 1;
    f.assign(2, vec(ll)(a.back().size(), 0));
    return sol(-1, string(m, '0'));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    
}