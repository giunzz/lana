#include <bits/stdc++.h>
#define ll long long
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

cll max2 = 59, max3 = 37, max5 = 25, max7 = 21;
ll a, b, n, f[67][67][67][67], check;
vec(ll) dg;

void processN(){
    ll tmp = n;
    dg.clear();
    while(tmp) dg.push_back(tmp%10), tmp /= 10;
    reverse(dg.begin(), dg.end());
}

ll getA(){
    processN();
    memset(f, 0, sizeof(f));
    lp(x, 0, max2){
        lp(y, 0, max3){
            lp(z, 0, max5){
                lp(t, 0, max7){
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> a >> b;
    n = a;
    getA();
}