#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define loop(variable, valuegan, valuebehonbang) for(ll variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(ll variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(ll variable = valuegan; conditions; thaydoi) 
#define pp(type, type1) pair<type, type1>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll t, n, lt[35], sc, s, c, d[35] = {0};

int main(){
    opt;
    //fi;
    lt[0] = 1;
    loop(i, 1, 30) lt[i] = lt[i - 1] * 2;
    cin >> t;
    while(t--){
        s = 0;
        cin >> n;
        s += lt[n];
        loop(i, 1, n/2 - 1){
            s += lt[i];
        }
        loop(i, n/2, n - 1) s -= lt[i];
        cout << abs(s) << endl;
    }
}