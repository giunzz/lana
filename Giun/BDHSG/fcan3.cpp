#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 <= obj3; obj1++)
#define lpd(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 >= obj3; obj1--)
#define lpdk(obj1, obj2, obj3, obj4) for(ll obj1 = obj2; obj3; obj4) 
#define pp(obj1, obj2) pair<obj1, obj2>
#define vec(obj1) vector<obj1>
#define vecite(obj1) vector<obj1>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "fcan3";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll m, dem = 0, lt3[40] = {0}; 

vec(ll) coso;

void doicoso(){
    ll b = m;
    while(b != 0){
        coso.push_back(b % 3);
        dem += b % 3;
        b /= 3;
    }
}

int main(){
    opt;
    file;
    cin >> m;
    lt3[0] = 1;
    lp(i, 1, 37) lt3[i] = lt3[i - 1] * 3;
    doicoso();
    cout << dem << " ";
    lp(i, 0, coso.size() - 1)
        while(coso[i]--) cout << lt3[i] << " ";
}
