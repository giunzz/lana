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

ll m, n, k, x, y, hg = 0, ct = 0, osl, ans;
map<ll, bool> dhg, dct;

int main(){
    opt;
    fi;
    cin >> m >> n >> k;
    loop(i, 1, k){
        cin >> x >> y;
        if(!dhg[x]) dhg[x] = 1, ++hg;
        if(!dct[y]) dct[y] = 1, ++ct;
    }
    osl = hg*n + (ct * (m - hg));
    ans = n * m - osl;
    cout << ans;
}